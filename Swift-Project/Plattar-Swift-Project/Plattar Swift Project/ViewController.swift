//
//  ViewController.swift
//  Plattar Swift Project
//
//  Created by David Arayan on 4/5/18.
//  Copyright © 2018 Plattar. All rights reserved.
//

import UIKit
import AVFoundation
import PlattarSDK

class ViewController: UINavigationController {
    
    var app:PlattarEngine?

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        // check for internet connection. Plattar requires
        // a constant internet connection to function properly.
        if (!ConnectionChecker.checkConnection()) {
            ConnectionChecker.showConnectionMessage()
            
            return
        }
        
        // ensure the app actually supports ARKit before proceeding.
        // ARKit is only supported from IOS 11.0 onwards. Handle fallback
        // functionality here
        if (!PlattarCVSession.isARSupported()) {
            PlattarUtil.errorNotify("ARKit is not supported!")
            
            return
        }
        
        // initialise our primary Plattar engine instance. Although multiple instances
        // can be created per app, this is not supported nor encouraged as the memory footprint
        // per app is very large. Store this variable somewhere and re-use it throughout the app.
        // NOTE -> all functions in PlattarEngine are asynchrnous and thread safe
        app = PlattarCVSession.initPlattarView() as? PlattarEngine
        
        // grab the app code from the info.plist file as a String
        let appCode:String = Bundle.main.object(forInfoDictionaryKey: "APP_CODE") as! String
        
        // this will allocate and setup all critical required systems and memory. This operation
        // should only be performed once per app if battery drain is an issue. Do this before performing
        // any other interactions with the Plattar Engine.
        app!.setup(PlattarSettings(keyString: appCode));
        
        // this will launch the UI and setup the View hierarchy internally. Use this when you'd like
        // to actually start using Plattar. This function is asynchronous and load time is dependant
        // on internet connection speed and general device speed.
        app!.start();
        
        // register for a callback from the app when a certain event is fired. This event
        // is called when the rendering stack has completed all initialization and is ready for display
        app!.register(forEventCallback: onWebGLReady, withCallback: {(dict:[AnyHashable : Any]?)  -> Void in
            // remove any top views, Plattar is ready to show
            print("Plattar renderer has finished loading!");
        })
        
        // Plattar contains a parent view which manages the order of its internal views. We will need
        // to put the parent view into display. Since we will be making the Plattar view as a child of this
        // View Controller, we make the parent view completly transparent.
        self.view.isOpaque = false;
        self.view.backgroundColor = UIColor.clear;
        
        let parentView:UIView = app!.getParentView()
        
        self.view = parentView
    }
}
