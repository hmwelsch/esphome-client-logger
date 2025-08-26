#include "esphome/core/component.h"
#include "esphome/core/log.h"
extern "C" {
  #include "esp_wifi.h"
}

namespace esphome {
namespace client_logger {

class ClientLogger : public Component {
 public:
  void loop() override {
    wifi_sta_list_t stations;
    esp_wifi_ap_get_sta_list(&stations);
    ESP_LOGD("DoorAuth", "Verbunden: %d Client(s)", stations.num);

    for (int i = 0; i < stations.num; i++) {
      char mac[18];
      snprintf(mac, sizeof(mac), "%02X:%02X:%02X:%02X:%02X:%02X",
               stations.sta[i].mac[0], stations.sta[i].mac[1],
               stations.sta[i].mac[2], stations.sta[i].mac[3],
               stations.sta[i].mac[4], stations.sta[i].mac[5]);
      ESP_LOGD("DoorAuth", "Client %d MAC: %s", i+1, mac);
    }
    delay(5000); // Alle 5 Sekunden prüfen
  }
};

}  // namespace client_logger
}  // namespace esphome