//
//  GUI.hpp
//  WebcamGlitcher
//
//  Created by Frederik Tollund Juutilainen on 12/07/16.
//
//

#ifndef GUI_h
#define GUI_h
#include "Webcam.hpp"
#include "ofxDatGui.h"

class GUI{
public:
    GUI(Webcam* cam){
        this->cam = cam;
        gui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
        gui->addHeader(" press space to hide"); // Header
        
        blurAmtSlider = gui->addSlider("blur", 0.0, 0.999);
        blurAmtSlider->setPrecision(3);
        blurAmtSlider->setValue(cam->blurAmt);
        blurAmtSlider->onSliderEvent(this, &GUI::onSliderEvent);
        
        shiftAmtSlider = gui->addSlider("rgb shift", 0,7);
        shiftAmtSlider->setPrecision(0);
        shiftAmtSlider->setValue(cam->shiftAmt);
        shiftAmtSlider->onSliderEvent(this, &GUI::onSliderEvent);
        
        brghtThrsholdSlider = gui->addSlider("brgh thrshold", 0,255);
        brghtThrsholdSlider->setPrecision(0);
        brghtThrsholdSlider->setValue(cam->shiftAmt);
        brghtThrsholdSlider->onSliderEvent(this, &GUI::onSliderEvent);
        
        invBrightSlider = gui->addSlider("inv brght", 0,255);
        invBrightSlider->setPrecision(0);
        invBrightSlider->setValue(cam->invBright);
        invBrightSlider->onSliderEvent(this, &GUI::onSliderEvent);
        
    }
    
    bool hidden;
    void hide(){
        if(hidden){
            gui->setVisible(true);
            hidden = false;
        }else{
            gui->setVisible(false );
            hidden = true;
        }
    }
    
    Webcam* cam;
    
    void onSliderEvent(ofxDatGuiSliderEvent e){
        if(e.target == blurAmtSlider){
            cam->blurAmt = e.value;
        }
        
        if(e.target == shiftAmtSlider){
            cam->shiftAmt = e.value;
        }
        
        if(e.target == brghtThrsholdSlider){
            cam->brghtThrshold = e.value;
        }
        
        if(e.target == invBrightSlider){
            cam->invBright = e.value;
        }
    }
    
    
    
    // GUI Elements
    ofxDatGui* gui;
    ofxDatGuiSlider* blurAmtSlider;
    ofxDatGuiSlider* shiftAmtSlider;
    ofxDatGuiSlider* brghtThrsholdSlider;
    ofxDatGuiSlider* invBrightSlider;
    ofxDatGuiToggle* mirrorToggle;
};

#endif /* GUI_h */
