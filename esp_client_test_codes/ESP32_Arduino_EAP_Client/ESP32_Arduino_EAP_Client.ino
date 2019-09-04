#include "esp_wpa2.h"
#include "esp_wifi.h"
#include "esp_wpa2.h"
#include <WiFi.h>


#define EXAMPLE_EAP_METHOD 1

#define EXAMPLE_EAP_ID "matheus_garbelini"
#define EXAMPLE_EAP_USERNAME "matheus_garbelini"
#define EXAMPLE_EAP_PASSWORD "testtest"

#define EXAMPLE_WIFI_SSID "TEST_KRA"

void setup() {
  Serial.begin(115200);
  Serial.println("INIT");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  // This part of the code is taken from the oficial wpa2_enterprise example from esp-idf
  ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
  ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
  ESP_ERROR_CHECK( esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EXAMPLE_EAP_ID, strlen(EXAMPLE_EAP_ID)) );
  ESP_ERROR_CHECK( esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EXAMPLE_EAP_USERNAME, strlen(EXAMPLE_EAP_USERNAME)) );
  ESP_ERROR_CHECK( esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EXAMPLE_EAP_PASSWORD, strlen(EXAMPLE_EAP_PASSWORD)) );
  ESP_ERROR_CHECK( esp_wifi_sta_wpa2_ent_enable(&config) );

  WiFi.begin(EXAMPLE_WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

} 
