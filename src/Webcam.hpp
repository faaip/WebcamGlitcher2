//
//  Webcam.hpp
//  WebcamGlitcher
//
//  Created by Frederik Tollund Juutilainen on 12/07/16.
//
//

#ifndef Webcam_h
#define Webcam_h
#include "ofMain.h"

class Webcam{
public:
    ofVideoGrabber vidGrabber;
    ofPixels videoInverted;
    ofTexture videoTexture;
    int camWidth;
    int camHeight;
    float blurAmt = 0.000;
    int shiftAmt = 0;
    int invBright = 0;
    int brghtThrshold = 0;
    
    
    Webcam(){
        camWidth = 1280;  // try to grab at this size.
        camHeight = 720;
        
        //we can now get back a list of devices.
        vector<ofVideoDevice> devices = vidGrabber.listDevices();
        
        for(int i = 0; i < devices.size(); i++){
            if(devices[i].bAvailable){
                ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
            }else{
                ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
            }
        }
        
        vidGrabber.setDeviceID(0);
        vidGrabber.setDesiredFrameRate(60);
        vidGrabber.initGrabber(camWidth, camHeight);
        
        videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
        videoTexture.allocate(videoInverted);
        ofSetVerticalSync(true);
    }
    
    void update(){
        vidGrabber.update();
        
        if(vidGrabber.isFrameNew()){
            ofPixels & pixels = vidGrabber.getPixels();
            for(int i = 0; i < pixels.size(); i++){
                if(pixels[i] > brghtThrshold){
                if(ofRandom(1)>blurAmt){
                videoInverted[i] = (pixels[i] + invBright) << shiftAmt;
                }
                }
            }
            videoTexture.loadData(videoInverted);
        }
    }
};


#endif /* Webcam_h */
