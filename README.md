<h3 align="center">
  <img src="icon.png?raw=true" alt="Plattar Logo" width="500">
</h3>

[![Twitter: @plattarglobal](https://img.shields.io/badge/contact-@plattarglobal-blue.svg?style=flat)](https://twitter.com/plattarglobal)
[![Join the chat at https://gitter.im/Plattar-SDK-Devs/Lobby](https://img.shields.io/badge/chat-gitter/PlattarSDK-green.svg?style=flat)](https://gitter.im/Plattar-SDK-Devs/Lobby)

_Plattar SDK_ is a native framework which works with the _Plattar CMS_. This is a sample repository with example code to help integrate the _Plattar SDK_ into existing IOS Applications.

***


### About

Plattar is an Augmented Reality Content Management System (CMS). The Plattar SDK allows developers to add the Plattar UI and 3D Rendering into existing IOS applications. Adding content/interactions will still need to go through the CMS. 

This Plattar Project will compile and run without modifications and uses a sample application from the Plattar Staging Server which is an environment used for testing latest dev code.

### CMS Access

This Plattar Project can be tied into a custom application if required. Please use the issue tracker for the Setup instructions and the app key.

Once the app key is recieved, replace the **APP_CODE** String value in **info.plist** file.

Save, recompile and relaunch the app.

### Limitations

Plattar is designed to support multiple AR tracking backends. The following version of the SDK only supports Apple ARKit. Attempting to launch any of the other backends is likely to lead to errors and problems.

Plattar SDK is written in Objective-C and the sample provided in modern Swift. For an Objective-C sample, please make a feature request using the issue tracker!

### Questions and Feature Requests

Please use the issue tracker for any questions, bug reports or feature requests. We check the issue tracker regularly.
