# RecordIPCam
Read video stream from Oncam and write video.

## Building
You will need OpenCV 3 (not version 2.4.11 or anything previous). It can be downloaded from the
[OpenCV download page](http://opencv.org/downloads.html).   
Once installed, build from the terminal:

```sh
$ mkdir build        # Create a build directory
$ cd build
$ cmake ..           # Use CMake to generate the Makefile
$ make -j20           # Compiles four files in parallel, best for quad-core computers
```

## Usage

The syntax for running the program is `./record <ip> <VideoName>`, where `<ip>` is the camera's IP address and `<VideoName>`
is the name for the recorded video.  

Example usage in Torg 1100.
```sh
./record 192.168.1.50 id1  
```
press ESC to end recording  

## Camera Parameters
Remember to change cam setting and parameters in code. Current under primary stream, high-speed sensor mode, 2MP, H264, 30fps, 100% Quality.  
 
## Issue
Created a 2hour video in MJPEG and .avi, the file seems to have partial corruption.  
Possibly better to use H.264 codec with .mp4(over.avi)?
Or caused by recording 3 videos simultaneously?
