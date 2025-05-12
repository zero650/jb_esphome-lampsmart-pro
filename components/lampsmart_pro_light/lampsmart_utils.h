#pragma once
#include "esphome/core/log.h"

#ifdef USE_ESP32

#include <esp_gap_ble_api.h>
#include <esp_gatts_api.h>

namespace esphome
{
  namespace lampsmartpro
  {

    static const char *TAG = "lampsmartpro";

    char *bitReverse(char *bArr);

    char *bleWhitening(char *bArr);

    char *bleWhiteningForPacket(char *bArr);

    int CRC16(char *bArr, int len, int offset);

    char *buildPacket(char command, char mControl0, char mControl1, char arg1, char arg2, uint8_t groupId);

    static esp_ble_adv_params_t ADVERTISING_PARAMS = {
        .adv_int_min = 0x20,
        .adv_int_max = 0x20,
        .adv_type = ADV_TYPE_NONCONN_IND,
        .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
        .peer_addr =
            {
                0x00,
            },
        .peer_addr_type = BLE_ADDR_TYPE_PUBLIC,
        .channel_map = ADV_CHNL_ALL,
        .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
    };
  } // namespace lampsmartpro
} // namespace esphome

#endif
