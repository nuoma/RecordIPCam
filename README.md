# RecordIPCam
Read video stream from Oncam and write video.

## Usage
```sh
./record ip VideoName
```
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
