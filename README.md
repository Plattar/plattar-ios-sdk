<h3 align="center">
  <a href="https://www.plattar.com/">
    <img src="Graphics/icon.png?raw=true" alt="Plattar Logo" width="500">
  </a>
</h3>

[![Twitter: @plattarglobal](https://img.shields.io/badge/contact-@plattarglobal-blue.svg?style=flat)](https://twitter.com/plattarglobal)
[![Join Slack Chat](https://img.shields.io/badge/chat-slack-orange.svg?style=flat)](https://join.slack.com/t/plattar-public/shared_invite/enQtMzkyNjIxOTM1NjE4LTNkZmRiNWRkOTQ2MWQ4MTRlYTgyY2U0MGQxNjkyYzQ3MTc0NDAyZjE3MmU4MzRjNWQzYWM0NDA4YzRhNDBmNzA)
[![Build Status](https://circleci.com/gh/Plattar/app-ios/tree/master.svg?style=shield&circle-token=97c07a9936d6d90ed3b7725c3a5fa5c4c905a58f)](https://www.plattar.com)
[![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg?style=flat)](LICENSE)

_Plattar SDK_ is a native framework which works with the _Plattar CMS_. This is a sample repository with example code to help integrate the _Plattar SDK_ into existing IOS Applications. Looking for [Android Integration](https://github.com/Plattar/PlattarSDK-Android-Public)?

***

### About

_Plattar is the Augmented Reality platform for product experiences._ Plattar’s simple AR creator, iOS and Android apps, 3D web viewers, developer-friendly SDKs & APIs empower brands to build amazing experiences that put virtual products directly into your customers hands.

- The Plattar SDK for iOS lets you embed Plattar AR UI and 3D Rendering direct into your own apps and supports ARKit out of the box.
- Use the Plattar [Experience Builder](https://www.plattar.com/) to curate and enrich 3D content, and build and deploy updates direct to your SDK powered app.
- Create 3D content once and also deliver it dynamically to Plattar [3D Viewers](https://www.plattar.com/product) that can be embedded on your website.

3D content, rich media and interactions are created in the web based [Experience Builder](https://www.plattar.com/). Free trials are available at [plattar.com](https://www.plattar.com/).

This Plattar Project will compile and run without modifications and uses a sample application from the Plattar Staging Server which is an environment used for testing latest dev code.

### CMS Access

This Plattar Project can be tied into a custom application if required. Please [Generate](https://github.com/Plattar/PlattarSDK-Android-Public/wiki/Generating-App-Key) the required _App Key_.

Once the _App Key_ is generated, replace the **APP_CODE** String value in **info.plist** file.

Save, recompile and relaunch the app.

### Limitations

Plattar is designed to support multiple AR tracking backends. The following version of the SDK only supports Apple ARKit. Attempting to launch any of the other backends is likely to lead to errors and problems.

Plattar SDK is written in Objective-C and the sample provided in modern Swift. For an Objective-C sample, please make a feature request using the issue tracker!

ARKit is only supported on selected IOS devices. Check the [Supported Device List](https://www.apple.com/au/ios/augmented-reality) for more info.

### Questions and Feature Requests

Please use the [Issue Tracker](https://github.com/Plattar/PlattarSDK-IOS-Public/issues) for any questions, bug reports or feature requests.

### Documentation

Visit our dedicated [Wiki](https://github.com/Plattar/PlattarSDK-IOS-Public/wiki) page for additional documentation.

### License

This project is licensed under the terms of the Apache 2.0 license. See the [LICENSE](LICENSE) file.
