//===---------------------------------------------------------*- objC++ -*-===//
//
//  TestStringUtilities.mm
//  TestHiltmonLibrary
//
//  Created by Hilton Lipschitz on 2019-02-09.
//  Copyright © 2019 Hiltmon.com. All rights reserved.
//
//===----------------------------------------------------------------------===//

#import <XCTest/XCTest.h>

#include "../../Maths/Maths/Vector3.hpp"

@interface TestStringUtilities : XCTestCase

@end

@implementation TestStringUtilities

- (void)testCaseChanges {
  XCTAssert(Vector3(1, 2, 3) + Vector3(4, 5, 6) == Vector3(5, 7, 9));
}

@end
