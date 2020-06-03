#include "ros/ros.h"
#include <sensor_msgs/Image.h>
#include "flir_lepton/LeptonThread.h"
#define RAINBOW 1
#define GRAYSCALE 2
#define IRONBLACK 3
#define LEPTON_2 2
#define LEPTON_3 3

int main( int argc, char **argv )
{

  ros::init(argc, argv, "flir_lepton");
  ros::NodeHandle nh("~");

	int typeColormap;
	int typeLepton;
	int spiSpeed; // SPI bus speed 20MHz
	int rangeMin; //
	int rangeMax; //
	int loglevel;
  int autoScale;
  std::string topicName = "thermal_image";

  if(!nh.getParam("typeColormap", typeColormap))
    typeColormap = IRONBLACK;

  if(!nh.getParam("typeLepton", typeLepton))
    typeLepton = LEPTON_2;

  if(!nh.getParam("spiSpeed", spiSpeed))
    spiSpeed = 20;

  if(!nh.getParam("rangeMin", rangeMin))
    rangeMin = -1;

  if(!nh.getParam("rangeMax", rangeMax))
    rangeMax = -1;

  if(!nh.getParam("loglevel", loglevel))
    loglevel = 0;

  if(!nh.getParam("autoScale", autoScale))
    autoScale = 1;

  ROS_INFO("Flir Lepton typeColormap: %d", typeColormap);
  ROS_INFO("Flir Lepton typeLepton: %d, SpiSpeed: %d", typeColormap, spiSpeed);
  ROS_INFO("Flir Lepton rangeMin: %d, rangeMax: %d", rangeMin, rangeMax);

  ros::Publisher imagePublisher = nh.advertise<sensor_msgs::Image>(topicName, 10);

	//create a thread to gather SPI data
	//when the thread emits updateImage, the label should update its image accordingly
	LeptonThread *lepton = new LeptonThread();
	lepton->setLogLevel(loglevel);
	lepton->useColormap(typeColormap);
	lepton->useLepton(typeLepton);
	lepton->useSpiSpeedMhz(spiSpeed);
	lepton->setAutomaticScalingRange(autoScale);
  lepton->setPublisher(imagePublisher);
	if (0 <= rangeMin) lepton->useRangeMinValue(rangeMin);
	if (0 <= rangeMax) lepton->useRangeMaxValue(rangeMax);
  ros::ServiceServer performFCC = nh.advertiseService("performFCC", &LeptonThread::performFFC, lepton);
	lepton->run();
	return 0 ;
}
