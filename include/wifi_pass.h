#define BATH_BOT_VERSION "1.1.8"
// test for Geekhouse Tsukuba
//#define WIFI_SSID "GeekHouseTsukuba-g"
//#define WIFI_PASS "tomorinao"
// test for teTra Office
#define WIFI_SSID "teTra_Office"
#define WIFI_PASS "tetratetra"

// Geekhouse Bijogi
//#define WIFI_SSID "teTra_GHB"
//#define WIFI_PASS "tetratetra"
//String message_wakeup = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"#71-1_opr_bath_geekhouse_bijogi\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
//String message_wakeup = "payload={\"channel\": \"#z_geekhouse_bijogi_bathroom\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"#z_geekhouse_bijogi_bathroom\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"#z_geekhouse_bijogi_bathroom\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
// Channel ID: C021B98R75E
//String message_wakeup = "payload={\"channel\": \"C021B98R75E\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"C021B98R75E\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"C021B98R75E\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
// chanel name: misc_geekhouse_bijogi_bath
String message_wakeup = "payload={\"channel\": \"#misc_geekhouse_bijogi_bath\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
String message_in_use = "payload={\"channel\": \"#misc_geekhouse_bijogi_bath\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
String message_available = "payload={\"channel\": \"#misc_geekhouse_bijogi_bath\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";



// Geekhouse Minami-Soma
//#define WIFI_SSID "teTra_GHM"
//#define WIFI_PASS "tetratetra"
//String message_wakeup = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"#72-1_opr_bath_geekhouse_minamisoma\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
//String message_wakeup = "payload={\"channel\": \"#z_geekhouse_minamisoma_bathroom\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"#z_geekhouse_minamisoma_bathroom\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"#z_geekhouse_minamisoma_bathroom\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
// Channel ID: C01Q76PD9DL
//String message_wakeup = "payload={\"channel\": \"C01Q76PD9DL\", \"username\": \"Bath Bot\", \"text\": \"Wakeup Bath Bot. Version: " + String(BATH_BOT_VERSION) + "\", \"icon_emoji\": \":satisfied:\"}";
//String message_in_use = "payload={\"channel\": \"C01Q76PD9DL\", \"username\": \"Bath in use\", \"text\": \"Bath in use.\", \"icon_emoji\": \":hotsprings:\"}";
//String message_available = "payload={\"channel\": \"C01Q76PD9DL\", \"username\": \"Bath is available\", \"text\": \"Bath is available\", \"icon_emoji\": \":o:\"}";
//https://hooks.slack.com/services/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, haranomatch

/*
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
*/

/*
const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIFJTCCBA2gAwIBAgISBHu6bO4huNAiFhYpQhlVsUPaMA0GCSqGSIb3DQEBCwUA\n" \
"MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD\n" \
"EwJSMzAeFw0yMzAzMTQwNTE3MTNaFw0yMzA2MTIwNTE3MTJaMBQxEjAQBgNVBAMT\n" \
"CXNsYWNrLmNvbTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN2rqHkC\n" \
"HJkqERgVnhsGalMy+W5cFGhyWPVkPknNmLvYnznWxny7PQRmucedAjmaXVGFBpRo\n" \
"kT6LDFJJGpc9IDcH3UxI/0lWFsh/IF6PTlJ5n14rKFDqnLyo+/JfHhSK4WsYSmfX\n" \
"FkQSeb/GG3so3Ttnqj1lPYsQEc4OMXIHU07pNYAzL59z0kpXkDHUqwQ9OzJ4xAj0\n" \
"JJyoEXntKlF0s06YLqCKLCpZNRJpJMufzcgA1BuoCf+FR9zb2JiIlCTbU+ykF2em\n" \
"RUzya6pZkpyWeeP+IGTzGQ2fYb/3P+h9RTGdGhRZrlgEPfJd2Vwkeycfi77A61He\n" \
"Qw9W6U44/dk1KjsCAwEAAaOCAlEwggJNMA4GA1UdDwEB/wQEAwIFoDAdBgNVHSUE\n" \
"FjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDAYDVR0TAQH/BAIwADAdBgNVHQ4EFgQU\n" \
"mGdj+1lAmdcO20aIUo7FVjvdq5UwHwYDVR0jBBgwFoAUFC6zF7dYVsuuUAlA5h+v\n" \
"nYsUwsYwVQYIKwYBBQUHAQEESTBHMCEGCCsGAQUFBzABhhVodHRwOi8vcjMuby5s\n" \
"ZW5jci5vcmcwIgYIKwYBBQUHMAKGFmh0dHA6Ly9yMy5pLmxlbmNyLm9yZy8wIQYD\n" \
"VR0RBBowGIILKi5zbGFjay5jb22CCXNsYWNrLmNvbTBMBgNVHSAERTBDMAgGBmeB\n" \
"DAECATA3BgsrBgEEAYLfEwEBATAoMCYGCCsGAQUFBwIBFhpodHRwOi8vY3BzLmxl\n" \
"dHNlbmNyeXB0Lm9yZzCCAQQGCisGAQQB1nkCBAIEgfUEgfIA8AB3ALc++yTfnE26\n" \
"dfI5xbpY9Gxd/ELPep81xJ4dCYEl7bSZAAABht7EAvsAAAQDAEgwRgIhAOEMiIau\n" \
"KO0C92nvDk5fqpyat2lQg0W5Q224IFDCgZ1aAiEAyfcZUzWUf6Mp4dg9kT5kkjbb\n" \
"tfHa+VRhqyPyZuhfqnsAdQDoPtDaPvUGNTLnVyi8iWvJA9PL0RFr7Otp4Xd9bQa9\n" \
"bgAAAYbexALxAAAEAwBGMEQCIB/kYtGMs/05ePVmI/IGgGJPiUgSSEcsjsPL8TgQ\n" \
"h8HqAiA6W6aoujt6SbOihAwmz04WqD5xtn6Wss7lNsUmb0pp+TANBgkqhkiG9w0B\n" \
"AQsFAAOCAQEAR/qMA3MjQygHPcZL9HDFDX2qGx1yWoBJhfn97z9B3XsSCrGP647f\n" \
"nIVDxOqNXskjbYZPxjGW5ny8Gqyn0gF98n7BZx40PfKJdhhuo8vNpWDThAvQkbdc\n" \
"mZkiB/HhKww0vELOXRH0AerLiWMN8uuI1C43P+P8l/woM/1fccAiWlPearTMcsG4\n" \
"ufZ8HldSFVmv/0BGZj9GaW89bydHy6J1xo4QP1nEVu+a0u2zans47HkhqmmDjTpf\n" \
"ThSdUEk2rnPicNgLKMBek0vkq++F1LEwGC0UEkL1CZNo8nRzKG12UJku+B4agZ4t\n" \
"cXelW9Qj0aUGT49sHRur67plfIxxg8eRGA==\n" \
"-----END CERTIFICATE-----\n";
*/

const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"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\n" \
"-----END CERTIFICATE-----\n";

//update 230413, https://hooks.slack.com/services/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
//haranomatchi,  https://hooks.slack.com/services/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
const char* hostname = "hooks.slack.com";
//const char* target_page = "/services/T0101P6FH2L/B01Q76TEGPQ/jBEHT6gtwIs4b7yBiryWPGEL";
const char* target_page = "/services/T0101P6FH2L/B0530468M0B/HOQQAD0cwQICpuyPbuugMav3";


