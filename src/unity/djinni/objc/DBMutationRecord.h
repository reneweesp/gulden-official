// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBTransactionStatus.h"
#import <Foundation/Foundation.h>

@interface DBMutationRecord : NSObject
- (nonnull instancetype)initWithChange:(int64_t)change
                             timestamp:(int64_t)timestamp
                                txHash:(nonnull NSString *)txHash
                                status:(DBTransactionStatus)status
                                 depth:(int32_t)depth;
+ (nonnull instancetype)mutationRecordWithChange:(int64_t)change
                                       timestamp:(int64_t)timestamp
                                          txHash:(nonnull NSString *)txHash
                                          status:(DBTransactionStatus)status
                                           depth:(int32_t)depth;

@property (nonatomic, readonly) int64_t change;

@property (nonatomic, readonly) int64_t timestamp;

@property (nonatomic, readonly, nonnull) NSString * txHash;

@property (nonatomic, readonly) DBTransactionStatus status;

@property (nonatomic, readonly) int32_t depth;

@end