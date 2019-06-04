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

class ViewController: UIViewController {
    
    var app:PlattarEngine?

    @IBOutlet weak var contentViewFullscreen: UIView!
    @IBOutlet weak var contentView: UIView!
    @IBOutlet weak var mainView: UIView!
    @IBOutlet weak var headerView: UIView!
    
    var isSetup:Bool = false
    
    override func viewDidLoad() {
        // ensure the app does not go into sleep mode if user
        // events do not occur
        UIApplication.shared.isIdleTimerDisabled = true;
        
        super.viewDidLoad()
    }
    
    override var prefersStatusBarHidden: Bool {
        return true;
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
        // NOTE -> isARSupported() returns NO for simulators, however we can still
        // visualise the UI system (just no AR functionality)
        if (!PlattarCVSession.isARSupported() && !PlattarCVSession.isSimulator()) {
            PlattarUtil.showAlert("Sorry this device does not support this Augmented Reality experience. We are unable to launch the experience.", withTitle: "Uh Oh!", exitButton: "OK")
            
            return
        }
        
        // initialise our primary Plattar engine instance. Although multiple instances
        // can be created per app, this is not supported nor encouraged as the memory footprint
        // per app is very large. Store this variable somewhere and re-use it throughout the app.
        // NOTE -> all functions in PlattarEngine are asynchrnous and thread safe
        app = PlattarCVSession.initPlattarView() as? PlattarEngine
    }
    
    // this is called via the goAR function
    func setupAR(parentView: UIView) {
        // don't do multiple setups
        if (self.isSetup) {
            // the view might have changed, remove from parent and re-add
            app!.removeFromParentView()
            
            // re-add to our new parent view
            parentView.addSubview(app!.getParentView())
            
            // ensure the viewports take into account the new sizing
            app!.resize(parentView.frame.size)
            
            return
        }
        
        // grab the app code from the info.plist file as a String
        let appCode:String = Bundle.main.object(forInfoDictionaryKey: "APP_CODE") as! String
        
        // this will allocate and setup all critical required systems and memory. This operation
        // should only be performed once per app if battery drain is an issue. Do this before performing
        // any other interactions with the Plattar Engine.
        app!.setup(PlattarSettings(keyString: appCode))
        
        // this will launch the UI and setup the View hierarchy internally. Use this when you'd like
        // to actually start using Plattar. This function is asynchronous and load time is dependant
        // on internet connection speed and general device speed.
        // NOTE -> this function will ask for camera access for AR, this function will also show an
        // error message if AR is not supported. Use PlattarCVSession.isARSupported()
        app!.start()
        
        // register for a callback from the app when a certain event is fired. This event
        // is called when the rendering stack has completed all initialization and is ready for display
        app!.register(forEventCallback: onWebGLReady, withCallback: {(dict:[AnyHashable : Any]?)  -> Void in
            // remove any top views, Plattar is ready to show
            print("Plattar renderer has finished loading!")
        })
        
        // Plattar contains a parent view which manages the order of its internal views. We will need
        // to put the parent view into display. Since we will be making the Plattar view as a child of this
        // View Controller, we make the parent view completly transparent.
        parentView.addSubview(app!.getParentView())
        
        // since we added our main view into a different view hierarchy, ensure that the main view
        // is the same size as the screen size.
        app!.resize(parentView.frame.size)
        
        // pause the AR for the moment, we will call resume when
        // the user wishes to navigate back into the AR view.
        app!.pause()
        
        self.isSetup = true
    }
    
    @IBAction func goHome(_ sender: Any) {
        contentView.isHidden = true
        contentViewFullscreen.isHidden = true
        mainView.isHidden = false
        headerView.isHidden = false
        
        // pause our AR view
        app!.pause()
    }
    
    // This function will launch the AR View with a full-screen mode.
    // in this mode, the UIView takes up the entire screen.
    @IBAction func goARFullscreen(_ sender: Any) {
        contentView.isHidden = true
        headerView.isHidden = true
        contentViewFullscreen.isHidden = false
        mainView.isHidden = true
        
        self.setupAR(parentView: contentViewFullscreen)
        
        // resume our AR view
        self.app!.resume()
    }
    
    // This function will launch the AR View with partial screen mode.
    // in this mode, the UIView takes up only a portion of the screen.
    @IBAction func goAR(_ sender: Any) {
        contentView.isHidden = false
        headerView.isHidden = false
        contentViewFullscreen.isHidden = true
        mainView.isHidden = true
        
        self.setupAR(parentView: contentView)
        
        // resume our AR view
        self.app!.resume()
    }
    
    @IBAction func openSpecificScene(_ sender: Any) {
        // this function will open a specific scene by a provided UUID. Opening
        // by name is also supported, see findSceneByName() functionality
        if isSetup == true {
            self.app!.getAsyncBridge()?.openScene("f584ab37-c542-4536-9b63-dd41a167144a")
        }
    }
    
    @IBAction func openSpecificApp(_ sender: Any) {
        // this function will open a specific application on top of the currently
        // launched app. Application UUID's must be known and they cannot be searched via
        // names
        if isSetup == true {
            self.app!.getAsyncBridge()?.openApplication("3543b61c-7b44-4f90-a92f-4352952e5fe1")
        }
    }
    
    @IBAction func openSpecificPage(_ sender: Any) {
        // this function will open a specific page by a provided UUID. Opening
        // by name is also supported, see findPageByName() functionality
        if isSetup == true {
            self.app!.getAsyncBridge()?.openPage("471b2ac7-f873-498f-a1b9-a51ba6c1e385")
        }
    }
}
