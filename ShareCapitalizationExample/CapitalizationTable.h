//
//  CapitalizationTable.h
//  (c) Javaad Ali, Esq.
//  New York, 2024.
//  All rights reserved.
//
//  Created by AdvocatesClose on 12/5/24.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CapitalizationTable : NSObject
/// Suppose realistically that we would like to see each agreement pursuant to which shares were granted
/// Here, we create storage for a list of those documents
@property (nonatomic, strong) NSArray<NSString *> *grantingDocuments;
/// For each grant, we'll want to know that the related grant was duly authorized by the board
@property (nonatomic, strong) NSArray<NSString *> *boardResolutions;
/// For each grant, in the event that the related resolution merely authorized some Authorized Officer to make
/// a given grant,we'll want to confirm that such delegation was proper and to otherwise assess the propriety
/// of the related grant (including, without limitation, the number of shares authorized for grant purposes and
/// other such restrictions that may exist as to such grants, which may point us to problems in various other
/// documents.
@property (nonatomic, strong) NSString *bylaws;
/// As a general matter, we should know what was the number of shares initially authorized and issued and
/// be able to track all movements in both figures from the formation of the company to today
@property (nonatomic, strong) NSString *certificateOfIncorporation;
/// Assume the relevant agreements are stored somewhere and that they are keyed by name and accessible
/// at some URL
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *agreementURLs; 

/// Let's say, for now, that, if we do not have access to at least the above, we won't even bother trying to
/// evaluate the capitalization of the company
-(instancetype)initWithGrantingDocuments:(NSArray<NSString *> *)grantingDocuments
						 boardResolutions:(NSArray<NSString *> *)boardResolutions
								   bylaws:(NSString *)bylaws
			   certificateOfIncorporation:(NSString *)certificateOfIncorporation
							agreementURLs:(NSDictionary<NSString *, NSString *> *)agreementURLs;

@end



NS_ASSUME_NONNULL_END
