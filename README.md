# Flir Lepton ROS package
This package capture images from the [Flir Lepton Camera](https://www.sparkfun.com/products/14654) and publish them in a ROS topic. Tested on ROS melodic in a Raspberry pi 3 and the NVIDIA Jetson Nano.

## Pin Mapping

Camera Pin  | Raspberry Pi Pin          | Nvidia Jetson Nano Pin         
----------- | :------------------------ | :-----------------------
CS          | GPIO24 (28)               | GPIO_PZ0 (31)
MOSI        | GPIO10, SPI_MOSI (19)     | SPI_1_MOSI (19)
MISO        | GPIO09, SPI_MISO (21)     | SPI_1_MISO (21)
CLK         | GPIO11, SPI_CLK (23)      | SPI_1_SCK (23)
GND         | Ground (4)                | GND (9)
VIN         | 3.3v DC Power (1)         | 3.3 VDC Power (1)
SDA         | SDA1, GPIO02 (3)          | I2C_2_SDA, I2C Bus 1 (3)
SCL         | SCL1, GPIO03 (5)          | I2C_2_SCL, I2C Bus 1 (5)

## flir_lepton_node

### Publish
  - `~/thermal_image`: `sensor_msgs/Image`

### Services
  - `~/performFCC`: No arguments

### Parameters
  - `~/typeColormap`: int, default: 3, (`RAINBOW` = 1, `GRAYSCALE` = 2, `IRONBLACK` = 3)
  - `~/typeLepton`: int, default: 2, (Lepton 2.x = 2, Lepton 3.x = 3)
  - `~/spiSpeed`: int [Mhz], default: 20, (10 - 30)
  - `~/rangeMin`: int, default: automatic scaling range adjustment, (0 - 65535)
  - `~/rangeMax`: int, default: automatic scaling range adjustment, (0 - 65535)
  - `~/autoScale`: int, default: 1 (yes = 1 or no = 0)
  - `~/loglevel`: int, default: 0 (0 - 255)

### Execution
```bash
roslaunch flir_lepton captureAndView.launch
```
