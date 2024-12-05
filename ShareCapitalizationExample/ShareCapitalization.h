//
//  ShareCapitalization.h
//  (c) Javaad Ali, Esq.
//  New York, 2024.
//  All rights reserved.
//
//  Created by AdvocatesClose on 12/5/24.
//

#import <Foundation/Foundation.h>
#import "CapitalizationTable.h"

NS_ASSUME_NONNULL_BEGIN

@interface ShareCapitalization : NSObject

	// Properties to hold share-related data
@property (nonatomic, strong) NSNumber *totalSharesIssued;
@property (nonatomic, strong) CapitalizationTable *capitalizationTable; // Abstracted capitalization data

	// Initializer
- (instancetype)initWithCapitalizationTable:(CapitalizationTable *)capitalizationTable;

	// Methods to answer specific questions
- (NSArray<NSNumber *> *)issuedAndOutstandingShares;

	// Method to compute total shares outstanding based on documents
- (NSNumber *)computeSharesOutstandingUsingDocuments:(NSArray<NSString *> *)documentURLs
								 shareDetailsFetcher:(NSNumber *(^)(NSString *documentURL))fetchShareDetails;


@end

NS_ASSUME_NONNULL_END
