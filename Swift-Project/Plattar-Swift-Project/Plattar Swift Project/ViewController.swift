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

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        // check for internet connection
        if (!ConnectionChecker.checkConnection()) {
            ConnectionChecker.showConnectionMessage()
            
            return
        }
        
        // ensure the app actually supports ARKit before proceeding
        if (!PlattarCVSession.isNativeARSupported()) {
            PlattarUtil.errorNotify("ARKit is not supported!")
            
            return
        }
        
        // grab the app code from the info.plist file as a String
        let appCode:String = Bundle.main.object(forInfoDictionaryKey: "APP_CODE") as! String
        
        // generate our settings, which uses the app code to extract required data
        let settings:PlattarSettings = PlattarSettings(keyString: appCode)
        
        // initialise our ARKit internal instance. This will init and setup all rendering/logic
        // loops and return as a single interface
        let app:PlattarApplication = PlattarCVSession.initNative(with: settings) as! PlattarApplication
        
        app.start()
        
        // register for a callback from the app when a certain event is fired. This event
        // is called when the rendering stack has completed all initialization and is ready for display
        app.register(forEventCallback: onWebGLReady, withCallback: {(dict:[AnyHashable : Any]?)  -> Void in
            // remove any top views, Plattar is ready to show
        })
        
        // ask for permissions and push the view controller on top of the stack
        PlattarPermission.askAccess({() -> Void in
            // permissions was granted by the user, show plattar
            // ensure this code is running on the main thread
            if (Thread.isMainThread) {
                self.launchApp(app: app, animated: animated)
            }
            else {
                DispatchQueue.main.sync {
                    self.launchApp(app: app, animated: animated)
                }
            }
        }, denied: {() -> Void in
            // permissions was denied by the user, show error
            PlattarPermission.denyMessage()
        })
    }
    
    /**
     * Push the ViewController of the Plattar View on top of the stack
     */
    private func launchApp(app:PlattarApplication, animated:Bool) {
        let viewControllers:NSMutableArray = NSMutableArray(array:self.viewControllers)
        
        if (viewControllers.count > 0) {
            viewControllers.replaceObject(at: 0, with: app.getController())
        }
        else {
            viewControllers.add(app.getController())
        }
        
        self.setViewControllers(viewControllers as! [UIViewController], animated: animated)
    }
}
