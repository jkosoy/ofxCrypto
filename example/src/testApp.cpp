#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    string str = "hello";
    
    // md5 and sha1 are one way encryption. no decoders available (unless you count https://github.com/juuso/BozoCrack)
    cout << ofxCrypto::md5(str) << endl;
    cout << ofxCrypto::sha1(str) << endl;
    
    // base 64 encoding
    string base64EncodedStr = ofxCrypto::base64_encode(str);
    cout << base64EncodedStr << endl;
    cout << ofxCrypto::base64_decode(base64EncodedStr) << endl;
    
    // let's decode an image now
    string base64ImageData = "iVBORw0KGgoAAAANSUhEUgAAAHIAAAA8CAYAAAC6j+5hAAAAAXNSR0IArs4c6QAAAAZiS0dEAP8A/wD/oL2nkwAAAAlwSFlzAAALEwAACxMBAJqcGAAAAAd0SU1FB9sLGgwmJX2ZbqEAAAQrSURBVHja7Z2rdxtHFIe/34xspFO+f4BbXIXrD6hQkIMC2qAE1CygMbJBjWpSFhGjmoTJxRUpqniPeMXbZfHOLdjNqRw/9Kj2odm9TEBndefbO/cxd65kZrRVJD2r4DF/mdlC0hHwRUnP+FtVg5TUB74qPv5pZmldIHtyv5f/FHt/azb28j8LG5TwgDTDXvdKBHYEDBwMwPU/KeHR54uZq4tmENIAM2BmZnM6WQuimc17u4Z3gBsFbORRf+mtXP1dbADCw7AAnBr6LRCuO6hPQwTYCcie9A3olUdJYGdbdV/5CzHqyS2KLeqm43cfIoD7v8FCT+4D6BRISvzhCei0J/dB0rCDeBfi1hYpKXFw4ql8UROPLrz8LBDOzWzRQdzSIiUNPboS9VmGsIFHVy2zzkchbgzyUP7Eowug3wDF+h5dHMqftB3iRiC9/LuAHTdNw4Ade/l3EZct5hn2fFXk7taFKGzUWFWxkZeu4oQYXq9TNHH7DvE/mDqKyzLXh7gSZE/6bh8gLltmHD5zM4hPgswLynq1b0sQsOP9jmY3h/goSEl9j37c16Xw6FRS0haIj4J0cNqQFGPr1MTBSVsgPghS0rM6k/0dBj/Dis4ba4f4IEgH38cS93n0Qxsg3gNZWONRRIlYkp/MxA3xHkiH+za2lNrgRewQ74CUlJTUilB7oaDoVogW4h2QB7hjIpUD3ChmiHdABizaI6Hm6FYORCgOliUlnn1MoNcPeiQldR5EizDJYFpW16DLw3S+JnKpW8dbs5syWz9dEa1+GTtIww1i1q8HkMGRiF5qdR2H8icZbB09Z5a9We0jsSR2isJq3XVyYykvvXNNeFsrkn7Myjk66UB20oHspAPZSQcyfpBqw7W1RfQgDf6JnaKh+EGKMIu/IBC3jg4gg+i31th1/BTsRG+RseuY+0izNO6AR/M6p4dUnH6EX+LdVsOkNXlkBtOI9Zy2BqSZpYaie3MNTdowa+DOMIhAGHs0iknBQPi1Edv7ioPhHfpIMLNFTFZpaGZmf7QgIr9faw2EMZBGYo3ntETugcz9iUUQwdr7Ns3hefD049ZsvN95peYZXNMicU/kXm/3dItNM8JZ7AWAtUGa2SLDzvZwS/2pjdMknzxYNrMpewXTzto6QXJlh0C+MM2HmWGXbR4DutZ0yFuzm55EMc6zkZZoLZ/lunbPzq3ZTYY1LQBKM+xtN5B3w+YrM5tm2PN8/ngTUgx7mfvxTjbuojOzNLPsTYZd1mSdae4Ps5ctHLy7O5BLQK8L66ysNmtoUoy8vO7QbRHsPGWdwLmkSw/HoBfs/rJM6tDkI+HaLHQWWAbIz4COgfGBDoaBMCyukG17yysVmoGbfLSPnQ+sCuSyFAs/hfx/QHx+uTNZvjFc3FXsLwdNRbviIoN5VZWZKoI2UY0f/xcfeyq0L/JG7gAAAABJRU5ErkJggg==";
    ofBuffer decodedImage = ofxCrypto::base64_decode_to_buffer(base64ImageData);
    testImage.load(decodedImage);
    
    
    // and now let's re-encode it.
    ofPixels px;
    px.setFromPixels(testImage.getPixels(), testImage.getWidth(), testImage.getHeight(), testImage.getPixelsRef().getImageType());
    
    ofBuffer imageBuffer;
    ofSaveImage(px, imageBuffer);
    
    string reencodedImageData = ofxCrypto::base64_encode(imageBuffer);
    cout << "------------------------------" << endl;
    cout << reencodedImageData << endl; // expect a very long string!
    cout << "------------------------------" << endl;
    
    // or get really meta and test that your encoded image saved
    testImage2.load(ofxCrypto::base64_decode_to_buffer(reencodedImageData));
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    if(testImage.isAllocated()) {
        testImage.draw(0,0);
    }
    
    if(testImage2.isAllocated()) {
        testImage2.draw(0,testImage.getHeight() + 5);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}