#define BATH_BOT_VERSION "1.1.5"
// test for Geekhouse Tsukuba
#define WIFI_SSID "GeekHouseTsukuba-g"
#define WIFI_PASS "tomorinao"

String message_wakeup = "payload={\"channel\": \"73-1_opr_bath_geekhouse_tsukuba\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
String message_in_use = "payload={\"channel\": \"73-1_opr_bath_geekhouse_tsukuba\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
String message_available = "payload={\"channel\": \"73-1_opr_bath_geekhouse_tsukuba\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";

const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n" \
"MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n" \
"d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"......n" \
"06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n" \
"PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n" \
"YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n" \
"CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n" \
"-----END CERTIFICATE-----\n";

const char* hostname = "hooks.slack.com";
const char* target_page = "/services/T0....../B0....../jB......";


