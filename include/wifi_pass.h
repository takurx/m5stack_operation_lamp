#define BATH_BOT_VERSION "1.1.3"
// test for Geekhouse Tsukuba
//#define WIFI_SSID "GeekHouseTsukuba-g"
//#define WIFI_PASS "tomorinao"
// test for teTra Office
//#define WIFI_SSID "teTra_Office"
//#define WIFI_PASS "tetratetra"

// Geekhouse Bijogi
//#define WIFI_SSID "teTra_GHB"
//#define WIFI_PASS "tetratetra"
//String message_wakeup = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";

// Geekhouse Minami-Soma
#define WIFI_SSID "teTra_GHM"
#define WIFI_PASS "tetratetra"
String message_wakeup = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
String message_in_use = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
String message_available = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";



const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n" \
"MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n" \
"d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n" \
"QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT\n" \
"MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n" \
"b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG\n" \
"9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB\n" \
"CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97\n" \
"nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt\n" \
"43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P\n" \
"T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4\n" \
"gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO\n" \
"BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR\n" \
"TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw\n" \
"DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr\n" \
"hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg\n" \
"06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n" \
"PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n" \
"YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n" \
"CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n" \
"-----END CERTIFICATE-----\n";

const char* hostname = "hooks.slack.com";
const char* target_page = "/services/T0101P6FH2L/B01Q76TEGPQ/jBEHT6gtwIs4b7yBiryWPGEL";
