/*	
    WebBaseResourceHandleDelegate.h
    Copyright (c) 2002, Apple Computer, Inc. All rights reserved.
*/

#import <Foundation/Foundation.h>

#import <WebKit/WebViewPrivate.h>

@class NSError;
@class NSURLAuthenticationChallenge;
@class NSURLConnection;
@class NSURLConnectionAuthenticationChallenge;
@class NSURLCredential;
@class NSURLRequest;
@class NSURLResponse;
@class WebDataSource;
@class WebResource;
@class WebView;

@interface WebBaseResourceHandleDelegate : NSObject
{
@protected
    WebDataSource *dataSource;
    NSURLConnection *connection;
    NSURLRequest *request;
@private
    WebView *webView;
    NSURLResponse *response;
    id identifier;
    id resourceLoadDelegate;
    id downloadDelegate;
    NSURLAuthenticationChallenge *currentConnectionChallenge;
    NSURLAuthenticationChallenge *currentWebChallenge;
    BOOL cancelledFlag;
    BOOL reachedTerminalState;
    BOOL defersCallbacks;
    BOOL waitingToDeliverResource;
    WebResourceDelegateImplementationCache implementations;
    NSURL *originalURL;
    NSMutableData *resourceData;
    WebResource *resource;
}

- (BOOL)loadWithRequest:(NSURLRequest *)request;

- (void)setDataSource:(WebDataSource *)d;
- (WebDataSource *)dataSource;

- (id)resourceLoadDelegate;
- (id)downloadDelegate;

- (void)cancel;
- (void)cancelWithError:(NSError *)error;

- (void)setDefersCallbacks:(BOOL)defers;
- (BOOL)defersCallbacks;

- (NSError *)cancelledError;

- (void)setIdentifier:(id)ident;

- (void)releaseResources;
- (NSURLResponse *)response;

- (NSData *)resourceData;

// Connection-less callbacks allow us to send callbacks using data attained from a WebResource instead of an NSURLConnection.
- (NSURLRequest *)willSendRequest:(NSURLRequest *)newRequest redirectResponse:(NSURLResponse *)redirectResponse;
- (void)didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
- (void)didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
- (void)didReceiveResponse:(NSURLResponse *)r;
- (void)didReceiveData:(NSData *)data lengthReceived:(long long)lengthReceived;
- (void)didFinishLoading;
- (void)didFailWithError:(NSError *)error;

@end

// Note: This interface can be removed once this method is declared
// in Foundation (probably will be in Foundation-485).
@interface NSObject (WebBaseResourceHandleDelegateExtras)
- (void)connection:(NSURLConnection *)con didReceiveData:(NSData *)data lengthReceived:(long long)lengthReceived;
@end