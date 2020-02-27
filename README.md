# Flir Lepton ROS package
This package capture images from the [Flir Lepton Camera](https://www.sparkfun.com/products/14654) and publish them in a ROS topic.

## flir_lepton_rpi_node

### Publish
  - `~thermal_image`: `sensor_msgs/Image`

### Services
  - `~performFCC`: No arguments

### Parameters
  - `~typeColormap`: int, default: 3, (`RAINBOW` = 1, `GRAYSCALE` = 2, `IRONBLACK` = 3)
  - `~typeLepton`: int, default: 2, (Lepton 2.x = 2, Lepton 3.x = 3)
  - `~spiSpeed`: int [Mhz], default: 20, (10 - 30)
  - `~rangeMin`: int, default: automatic scaling range adjustment, (0 - 65535)
  - `~rangeMax`: int, default: automatic scaling range adjustment, (0 - 65535)
  - `~loglevel`: int, default: 0 (0 - 255)

### Execution
```bash
rosrun flir_lepton_rpi flir_lepton_rpi_node
```
