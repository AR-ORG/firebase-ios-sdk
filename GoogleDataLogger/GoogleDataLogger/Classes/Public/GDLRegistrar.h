/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import <GoogleDataLogger/GDLLogPrioritizer.h>
#import <GoogleDataLogger/GDLLogTargets.h>
#import <GoogleDataLogger/GDLLogUploader.h>

NS_ASSUME_NONNULL_BEGIN

/** Manages the registration of log targets with the logging SDK. */
@interface GDLRegistrar : NSObject

/** Creates and/or returns the singleton instance.
 *
 * @return The singleton instance of this class.
 */
+ (instancetype)sharedInstance;

/** Registers a backend implementation with the GoogleDataLogger infrastructure.
 *
 * @param backend The backend object to register.
 * @param logTarget The logTarget this backend object will be responsible for.
 */
- (void)registerUploader:(id<GDLLogUploader>)backend logTarget:(GDLLogTarget)logTarget;

/** Registers a log prioritizer implementation with the GoogleDataLogger infrastructure.
 *
 * @param prioritizer The prioritizer object to register.
 * @param logTarget The logTarget this prioritizer object will be responsible for.
 */
- (void)registerPrioritizer:(id<GDLLogPrioritizer>)prioritizer logTarget:(GDLLogTarget)logTarget;

@end

NS_ASSUME_NONNULL_END