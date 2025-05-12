#pragma once

#include "esphome.h"
#include "esphome/components/api/custom_api_device.h"
#include "esphome/components/light/light_output.h"
#include "esphome/components/fan/fan.h"

#define CMD_PAIR (0x28)
#define CMD_UNPAIR (0x45)
#define CMD_LEVEL (0x31)
#define CMD_GEAR (0x32)
#define CMD_DIRECTION (0x15)
#define CMD_TIMER (0x51)
#define CMD_MODEL (0x36)

namespace esphome
{
  namespace lampsmartpro
  {

    class LampSmartProFan : public fan::Fan, public Component, public api::CustomAPIDevice
    {
    public:
      void setup() override;
      void set_tx_duration(uint32_t tx_duration) { tx_duration_ = tx_duration; }
      void set_group_id(uint8_t group_id) { group_id_ = group_id; }
      fan::FanTraits get_traits() override;

    protected:
      void on_pair();
      void on_unpair();
      void send_packet(uint16_t cmd, uint8_t cold, uint8_t warm);
      void control(const fan::FanCall &call) override;
      char *getHostDeviceIdentifier();
      uint32_t tx_duration_;
      uint8_t group_id_;
    };

  } // namespace lampsmartpro
} // namespace esphome
