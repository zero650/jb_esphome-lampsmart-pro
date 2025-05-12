# esphome-lampsmart-pro
Custom ESPHome component to interface with Chinese "LampSmart Pro" Bluetooth lights.

Basically it's https://github.com/aronsky/esphome-components and https://github.com/MasterDevX/lampify combined to work with more (or different?) lights.

## How to try it

1. Create an ESPHome configuration that references the repo (using `external_components`)
2. Add a light entity to the configuration with the `lampsmart_pro_light` platform(set light and fan with same group, you just need pair once for same group)
3. Build the configuration and flash it to an ESP32 device (since BLE is used, ESP8266-based devices are a no-go)
4. Add the new ESPHome node to your Home Assistant instance
5. Use the newly exposed service (`esphome.<esphome-node-name>_pair`) to pair with your light (call the service withing 5 seconds of powering it with a switch).
6. Enjoy controlling your BLE light with Home Assistant!

## Example configuration (LampSmart Pro)

```yaml
external_components:
  # shorthand
  source: github://zero650/jb_esphome-lampsmart-pro

light:
  - platform: lampsmart_pro_light
    name: Bed Room Light
    group: 1
    default_transition_length: 0s
    duration: 500

fan:
  - platform: lampsmart_pro_light
    group: 1
    name: Bed Room Fan
    duration: 500
```
