#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace us100 {

class US100Component : public PollingComponent, public uart::UARTDevice {
 public:
  US100Component() : PollingComponent(10000) {}
  
  void setup() override;
  void update() override;
  void loop() override;
  void dump_config() override;
  
  void set_temperature_sensor(sensor::Sensor *temperature_sensor) { temperature_sensor_ = temperature_sensor; }
  void set_distance_sensor(sensor::Sensor *distance_sensor) { distance_sensor_ = distance_sensor; }

 protected:
  sensor::Sensor *temperature_sensor_{nullptr};
  sensor::Sensor *distance_sensor_{nullptr};
  unsigned int bytes_expected_{0};
};

}  // namespace us100
}  // namespace esphome