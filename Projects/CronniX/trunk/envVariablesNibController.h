#import <Cocoa/Cocoa.h>
#import "Crontab.h"


@interface envVariablesNibController : NSObject {
    IBOutlet NSPanel  *window;
    IBOutlet id btRemove;
    IBOutlet id envTable;
    Crontab *crontab;
    NSToolbar *toolbar;
    NSMutableDictionary *items;
}

+ (envVariablesNibController *)sharedInstance;
+ (void)showWindow;
+ (void)hideWindow;

// accessors
- (void)setCrontab: (id)aCrontab;

- (NSPanel *)window;
- (NSToolbar *)toolbar;

// workers
- (void)showWindow;
- (void)hideWindow;
- (void)addEnv:(NSString *)env withValue:(NSString *)value;
- (void)removeAllObjects;
- (void)reloadData;

- (int)selectedRow;

- (void)addLine;

- (void)newLine; // identical to addLine

- (void)removeLine;

- (void)duplicateLine;

- (void)clear;

// ib actions
- (IBAction)hideWindow:(id)sender;
- (IBAction)addLine:(id)sender;
- (IBAction)removeLine:(id)sender;
- (IBAction)duplicateLine:(id)sender;

// delegate methods
//- (void)controlTextDidChange:(NSNotification *)aNotification;

// toolbar delegates
- (NSToolbarItem *)toolbar:(NSToolbar *)toolbar itemForItemIdentifier:(NSString *)itemIdentifier willBeInsertedIntoToolbar:(BOOL)flag;
- (NSArray *)toolbarDefaultItemIdentifiers:(NSToolbar*)toolbar;
- (NSArray *)toolbarAllowedItemIdentifiers:(NSToolbar*)toolbar;
- (int)count;

// toolbar menu actions
- (void)customize:(id)sender;
- (void)showhide:(id)sender;

@end