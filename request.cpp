#include "request.h"

RequestHeader::RequestHeader(CURL * curl)
{
    list = curl_slist_append(list, "Content-Type: application/json; charset=UTF-8");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_URL, (url + key).c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);

}

RequestBody::RequestBody(CURL * curl)
{
    jPostData.insert_or_assign("homeMobileCountryCode", homeMobileCountryCode);
    jPostData.insert_or_assign("homeMobileNetworkCode", homeMobileNetworkCode);
    jPostData.insert_or_assign("radioType", radioType);
    jPostData.insert_or_assign("carrier", carrier);
    jPostData.insert_or_assign("considerIp", considerIp);
    sPostData = jPostData.as_string();
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sPostData.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sPostData.length());
}

void RequestBody::GetAPs()
{
  wireless_scan_head head;
  wireless_scan *result;
  iwrange range;
  int sock;

  /* Open socket to kernel */
  sock = iw_sockets_open();

  /* Get some metadata to use for scanning */
  if (iw_get_range_info(sock, interface_name, &range) < 0) {
    cout << "Error during iw_get_range_info. Aborting." << endl;
    exit(2);
  }

  /* Perform the scan */
  if (iw_scan(sock, interface_name, range.we_version_compiled, &head) < 0) {
    cout << "Error during iw_scan. Aborting." << endl;
    exit(2);
  }
  /* Traverse the results */
  result = head.result;
  char buffer[128];
  vector<json> APs;
  while (NULL != result) {
    if(result->has_ap_addr)
    {
      json AP;
      AP["macAddress"] = iw_sawap_ntop(&result->ap_addr, buffer);
      APs.push_back(AP);
    }
    result = result->next;
  }
  jPostData["wifiAccessPoints"] = json::make_array<1>(APs.size());
  for(int i = 0; i < APs.size(); ++i)
    jPostData["wifiAccessPoints"][i] = APs[i];
}