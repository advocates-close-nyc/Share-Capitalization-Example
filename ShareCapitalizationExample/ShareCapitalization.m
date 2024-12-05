//
//  ShareCapitalization.m
//  (c) Javaad Ali, Esq.
//  New York, 2024.
//  All rights reserved.
//
//  Created by AdvocatesClose on 12/5/24.
//

#import "ShareCapitalization.h"

@implementation ShareCapitalization

	// Initializer
- (instancetype)initWithCapitalizationTable:(CapitalizationTable *)capitalizationTable {
	self = [super init];
	if (self) {
		_capitalizationTable = capitalizationTable;
		_totalSharesIssued = @0; // Default to 0, computed dynamically as needed
	}
	return self;
}

	// Method to return issued and outstanding shares as an array of changes
- (NSArray<NSNumber *> *)issuedAndOutstandingShares {
	NSMutableArray<NSNumber *> *changes = [NSMutableArray array];

	for (NSString *documentURL in self.capitalizationTable.agreementURLs.allValues) {
			// Placeholder for actual share computation logic
		NSNumber *sharesChange = [self fetchSharesChangeFromDocument:documentURL];
		if (sharesChange) {
			[changes addObject:sharesChange];
		}
	}

	return [changes copy];
}

	// Method to compute total shares outstanding
- (NSNumber *)computeSharesOutstandingUsingDocuments:(NSArray<NSString *> *)documentURLs
								 shareDetailsFetcher:(NSNumber *(^)(NSString *documentURL))fetchShareDetails {
	__block NSInteger total = 0;

	for (NSString *documentURL in documentURLs) {
		NSNumber *sharesChange = fetchShareDetails(documentURL);
		if (sharesChange) {
			total += sharesChange.integerValue;
		}
	}

	return @(total);
}

	// Helper method to simulate fetching shares change from a document
- (NSNumber *)fetchSharesChangeFromDocument:(NSString *)documentURL {
		// Simulate fetching shares data
		// Replace this stub with actual logic or integrate with the shareDetailsFetcher block
	return @(arc4random_uniform(100) - 50); // Random change between -50 and +50 for demonstration
}

@end
