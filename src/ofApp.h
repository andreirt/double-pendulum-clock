#pragma once

#include "ofMain.h"
#include "ofxUI.h"


class ofApp : public ofBaseApp{

private:
    
    std::map<string, string> ptStrings;
    std::map<string, string> enStrings;
    std::map<string, string> currentStrings;
    int currentLocale;
    const static string SUPPORT_BUTTON_NAME;
    const static float MAX_STRENGTH_AROUND_PIXEL;
    const static string CHANGE_LOCALE_BUTTON_NAME;
    const static string ENGLISH_LABEL;
    const static string PORTUGUESE_LABEL;
    const static int LOCALE_ENGLISH = 0;
    const static int LOCALE_PORTUGUESE = 1;
    ofxUILabelButton* changeLocaleButton;
    
    ofxUILabel* titleLabel;
    ofxUIDropDownList* pickCameraLabel;
    ofxUILabel* cameraWidthLabel;
    ofxUILabel* cameraHeightLabel;
    ofxUILabel* imageRotationLabel;
    ofxUILabel* maxSpeedLabel;
    ofxUILabel* maxHeightLabel;
    ofxUILabel* minutesLabel;
    ofxUILabelButton* clearButton;
    
    ofxUILabel* credits1Label;
    ofxUILabel* credits2Label;
    ofxUILabel* credits3Label;
    ofxUILabel* credits4Label;
    ofxUILabel* credits5Label;
    
    ofxUILabelButton* saveButton;
    ofxUILabelButton* cancelButton;
    
    ofxUILabel* supportLabel;
    
    ofxUICanvas *gui;
    ofxUICanvas *cameraPanel;
    ofxUICanvas *imagePanel;

    ofVideoGrabber* videoGrabber;
    int selectedCameraIndex;

    ofImage screenImage;

    int step;
    int y;
    int x1, x2;
    int speed;
    int height;

    int maxSpeed;
    int maxHeight;

    int cameraWidth;
    int cameraHeight;

    int imageWidth;
    int imageHeight;

    float lastTimeImageWasSaved;
    int intervalToSaveImage;


    ofxUISpacer* titleSpacer;
    ofxUIDropDownList* cameraList;
    ofxUITextInput* cameraWidthTextInput;
    ofxUITextInput* cameraHeightTextInput;
    ofxUITextInput* maxSpeedTextInput;
    ofxUITextInput* maxHeightTextInput;
    ofxUITextInput* intervalToSaveTextInput;

    ofxUIToggle* zeroRotationToggle;
    ofxUIToggle* ninetyRotationToggle;
    ofxUIToggle* oneHundredEightyRotationToggle;
    ofxUIToggle* twoHundredSeventyRotationToggle;
    int rotations;

    ofxUIToggle* showAtStartupToggle;
    bool showAtStartup;

    ofxUIToggle* fullScreenToggle;
    bool fullScreen;

    ofxUIToggle* saveImageToggle;
    bool saveImage;

    std::vector<ofxUITextInput*> textInputs;

    void pickParameters();
    void pickSpeed();
    void paintPixel( int pixelX, int pixelY, ofPixels pixels, float strength );

    void fillImageWithWhite( ofImage* image );
    void saveCurrentImage();

    void reset();
    void cancelConfigurationChanges();
    void applyConfigurationChanges();
    void hideConfigurationPanel();
    void showConfigurationPanel();
    void unfocusAllTextInputs(ofxUITextInput* except);
    void checkTextInputFocus(ofxUIEventArgs &e);

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // ofxUI
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void cameraPanelEvent(ofxUIEventArgs &e);
    void imagePanelEvent(ofxUIEventArgs &e);

};
