<h3 align="center">
  <img src="Graphics/icon.png?raw=true" alt="Plattar Logo" width="500">
</h3>

[![Twitter: @plattarglobal](https://img.shields.io/badge/contact-@plattarglobal-blue.svg?style=flat)](https://twitter.com/plattarglobal)
[![Join Slack Chat](https://img.shields.io/badge/chat-slack-orange.svg?style=flat)](https://plattar.slack.com/messages/CB85ZEKNZ)
[![Build Status](https://circleci.com/gh/Plattar/app-ios/tree/master.svg?style=shield&circle-token=97c07a9936d6d90ed3b7725c3a5fa5c4c905a58f)](https://www.plattar.com)
[![WebXR Preview](https://img.shields.io/badge/webxr-setup-000000.svg?style=flat)](https://github.com/Plattar/PlattarSDK-Android-Public/wiki/WebXR---Preview)

_Plattar SDK_ is a native framework which works with the _Plattar CMS_. This is a sample repository with example code to help integrate the _Plattar SDK_ into existing IOS Applications. Looking for [Android Integration](https://github.com/Plattar/PlattarSDK-Android-Public)?

***


### About

Plattar is an Augmented Reality Content Management System (CMS). The Plattar SDK allows developers to add the Plattar UI and 3D Rendering into existing IOS applications. Adding content/interactions will still need to go through the CMS. 

This Plattar Project will compile and run without modifications and uses a sample application from the Plattar Staging Server which is an environment used for testing latest dev code.

### CMS Access

This Plattar Project can be tied into a custom application if required. Please [Generate](https://github.com/Plattar/PlattarSDK-IOS-Public/wiki/Generating-App-Key) the required _App Key_.

Once the _App Key_ is generated, replace the **APP_CODE** String value in **info.plist** file.

Save, recompile and relaunch the app.

### Limitations

Plattar is designed to support multiple AR tracking backends. The following version of the SDK only supports Apple ARKit. Attempting to launch any of the other backends is likely to lead to errors and problems.

Plattar SDK is written in Objective-C and the sample provided in modern Swift. For an Objective-C sample, please make a feature request using the issue tracker!

ARKit is only supported on selected IOS devices. Check the [Supported Device List](https://www.apple.com/au/ios/augmented-reality) for more info.

### Questions and Feature Requests

Please use the [Issue Tracker](https://github.com/Plattar/PlattarSDK-IOS-Public/issues) for any questions, bug reports or feature requests.
