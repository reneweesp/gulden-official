// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBBlockInfoRecord.h"


@implementation DBBlockInfoRecord

- (nonnull instancetype)initWithHeight:(int32_t)height
                             timeStamp:(int64_t)timeStamp
                             blockHash:(nonnull NSString *)blockHash
{
    if (self = [super init]) {
        _height = height;
        _timeStamp = timeStamp;
        _blockHash = [blockHash copy];
    }
    return self;
}

+ (nonnull instancetype)blockInfoRecordWithHeight:(int32_t)height
                                        timeStamp:(int64_t)timeStamp
                                        blockHash:(nonnull NSString *)blockHash
{
    return [[self alloc] initWithHeight:height
                              timeStamp:timeStamp
                              blockHash:blockHash];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p height:%@ timeStamp:%@ blockHash:%@>", self.class, (void *)self, @(self.height), @(self.timeStamp), self.blockHash];
}

@end
