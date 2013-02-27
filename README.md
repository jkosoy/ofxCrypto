# ofxCrypto

An openFrameworks library for encryption. Supports MD5, SHA1 and Base64.

## Simple Example

Include the addon in your openFrameworks project as normal. To call, simply:

	ofxCrypto::md5("hello world");
 	ofxCrypto::sha1("hello world");
 	ofxCrypto::base64_encode("hello world");
 	ofxCrypto::base64_decode("aGVsbG8gd29ybGQ="); // hello world.


## Binary Encryption

 You can easily encode and decode ofBuffer objects to Base64 - useful for getting string representations of binary data or in conjunction with HTML5 projects.

 	string encoded = ofxCrypto::base64_encode(myOfBufferObject);
 	ofBuffer decoded = ofxCrypto::base64_decrypt(myEncodedString);

 See the example project for an example of an image being encoded, decoded and then re-displayed.