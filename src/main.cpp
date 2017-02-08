/**
 * @file main.cpp
 * @author Nuo Ma
 * @date Feb5,2017
 * @version 1.0
 * 
 * @purpose: Read video stream from Oncam and write video.
 * 
 * @reference: http://docs.opencv.org/2.4/doc/tutorials/highgui/video-write/video-write.html
 * http://stackoverflow.com/questions/24195926/opencv-write-webcam-output-to-avi-file
 */

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

static void help()
{
    cout
        << "------------------------------------------------------------------------------" << endl
        << "This code write video from IPcam."                                   << endl
        << "Usage:"                                                                         << endl
        << "./record ip VideoName"<< endl
	      << "eg ./record 192.168.1.50 id1"<< endl
	      << "press ESC to end recording"<< endl
	      << "Remember to change cam setting and parameters in code"<< endl
	      << "Current 2MP H264 30fps"<< endl
        << "Press anykey to continue"<< endl
        << "------------------------------------------------------------------------------" << endl
        << endl;
}

int main(int argc, char *argv[]){

help();


const string ip = argv[1]; //first input is IP address
const string out = argv[2]; //second input is output video name
const string videoOutputName = string("../") + out + string(".mov");

//this is for OnCam
//const string videoStreamAddress = string("rtsp://admin:admin@") + ip + string("/h264/video.sdp");

//this is for vivotek
const string videoStreamAddress = string("http://root:admin@") + ip + string(":80/video.mjpg");

// This works on a oncam Mjpeg
//const string videoStreamAddress = "rtsp://admin:admin@192.168.1.50:8555/video.sdp?name=MJPEG";

// This works on a oncam concealed12 primary H.264
//const string videoStreamAddress = "rtsp://admin:admin@192.168.1.50/h264/video.sdp";

//temp mod for vivotek cam
//http://root:admin@192.168.1.16/video.cgi?.mjpg
//Rtsp://ROOT:ADMIN@<ip  address>:554/live.sdp
//

//open the video stream here
    VideoCapture vcap(videoStreamAddress); 
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

//get write video properties 
   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
  // int codec = CV_FOURCC('M','J','P','G');
   int codec = CV_FOURCC('X','2','6','4');
   double fps = 15;
   
   VideoWriter video(videoOutputName,codec,fps, Size(frame_width,frame_height),true);

   for(;;){

       Mat frame;
       vcap >> frame;
       video.write(frame);
       imshow( "Frame", frame );
       char c = (char)waitKey(33);//dely 33ms between each frame being shown on the screen
       if( c == 27 ) break; //press 27 = ascii ESC key to end
    }
cout << "Finished writing" << endl;
  return 0;
}

 

