//
//  iReSignAppDelegate.h
//  iReSign
//
//  Created by Maciej Swic on 2011-05-16.
//  Copyright (c) 2011 Maciej Swic, Licensed under the MIT License.
//  See README.md for details
//

#import <Cocoa/Cocoa.h>
#import "IRTextFieldDrag.h"
#include "ObjSSH.h"
#import "EMKeychainItem.h"



@interface iReSignAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *__unsafe_unretained window;
    
    NSUserDefaults *defaults;
    
    NSTask *unzipTask;
    NSTask *copyTask;
    NSTask *provisioningTask;
    NSTask *codesignTask;
    NSTask *generateEntitlementsTask;
    NSTask *verifyTask;
    NSTask *zipTask;
    NSString *sourcePath;
    NSString *appPath;
    NSString *frameworksDirPath;
    NSString *pluginsDirPath;
    NSString *frameworkPath;
    NSString *workingPath;
    NSString *appName;
    NSString *fileName;
    
    NSString *entitlementsResult;
    NSString *codesigningResult;
    NSString *verificationResult;
    
    NSMutableArray *frameworks;
    Boolean hasFrameworks;
    
    IBOutlet IRTextFieldDrag *pathField;
    IBOutlet IRTextFieldDrag *provisioningPathField;
    IBOutlet IRTextFieldDrag *entitlementField;
    IBOutlet IRTextFieldDrag *bundleIDField;
    IBOutlet NSButton    *browseButton;
    IBOutlet NSButton    *provisioningBrowseButton;
    IBOutlet NSButton *entitlementBrowseButton;
    IBOutlet NSButton    *resignButton;
    IBOutlet NSTextField *statusLabel;
    IBOutlet NSProgressIndicator *flurry;
    IBOutlet NSButton *changeBundleIDCheckbox;
    
    IBOutlet NSComboBox *certComboBox;
    NSMutableArray *certComboBoxItems;
    NSTask *certTask;
    NSArray *getCertsResult;
    ObjSSH *sshSession;
    BOOL isSending;
    BOOL atvAvailable;
    NSString *finalDestination;

    
}

@property (nonatomic, strong) ObjSSH *sshSession;
@property (unsafe_unretained) IBOutlet NSWindow *window;
@property (nonatomic, strong) NSString *workingPath;
@property (readwrite, assign) BOOL isSending;
@property (readwrite, assign) BOOL atvAvailable;
@property (nonatomic, strong) NSString *bundleID;

- (IBAction)checkSyslog:(id)sender;
- (IBAction)showLogFolder:(id)sender;

- (void)resetServerSettings;
- (void)showATVWarning;
- (BOOL)hasASU;
- (BOOL)isJailbroken;
- (void)showNotJailbrokenWarning;
- (IBAction)resign:(id)sender;
- (IBAction)browse:(id)sender;
- (IBAction)provisioningBrowse:(id)sender;
- (IBAction)entitlementBrowse:(id)sender;
- (IBAction)changeBundleIDPressed:(id)sender;

- (void)checkUnzip:(NSTimer *)timer;
- (void)checkCopy:(NSTimer *)timer;
- (void)doProvisioning;
- (void)checkProvisioning:(NSTimer *)timer;
- (void)doCodeSigning;
- (void)checkCodesigning:(NSTimer *)timer;
- (void)doVerifySignature;
- (void)checkVerificationProcess:(NSTimer *)timer;
- (void)doZip;
- (void)checkZip:(NSTimer *)timer;
- (void)disableControls;
- (void)enableControls;

@end
