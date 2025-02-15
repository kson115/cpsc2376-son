#include "pch.h"
#include "CppUnitTest.h"
#include "practice03.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
    TEST_CLASS(practice03test)
    {
    public:
        TEST_METHOD(TestSumRange)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5));    // case 1: standard ranges            
            Assert::AreEqual(0, MathUtils::sumRange(0, 0));     // case 2: Empty range           
            Assert::AreEqual(-3, MathUtils::sumRange(-3, 2));   // case 3: mixed Negative to positive range
            Assert::AreEqual(4, MathUtils::sumRange(4, 4));     // case 4: start == end
            Assert::AreEqual(6, MathUtils::sumRange(0, 3));     // case 5: Zero to positive range
            Assert::AreEqual(-15, MathUtils::sumRange(-5, -1)); // case 6: Negative to negative range
        }
        TEST_METHOD(TestContainsNegative)
        {        
            Assert::IsFalse(MathUtils::containsNegative({ 1, 2, 3 }));  // case 1: all positive           
            Assert::IsTrue(MathUtils::containsNegative({ -1, 2, 3 }));  // case 2: Contains negatives            
            Assert::IsFalse(MathUtils::containsNegative({}));           // case 3: Empty vector
            Assert::IsTrue(MathUtils::containsNegative({ -1, -2, -3 }));// case 4: All negatives
            Assert::IsTrue(MathUtils::containsNegative({ -1 }));        // case 5: Single negative element
            Assert::IsFalse(MathUtils::containsNegative({ 1 }));        // case 6: Single positive element
        }
        TEST_METHOD(TestFindMax)
        {         
            Assert::AreEqual(7, MathUtils::findMax({ 3, -1, 5, 7 }));   // case 1: standard input            
            Assert::AreEqual(0, MathUtils::findMax({}));                // case 2: Empty vector            
            Assert::AreEqual(5, MathUtils::findMax({ 5, 5, 5 }));       // case 3: All same elements 
            Assert::AreEqual(10, MathUtils::findMax({ 10 }));           // case 4: Single element
            Assert::AreEqual(-7, MathUtils::findMax({ -20, -10, -7}));  // case 5: All negative elements
            Assert::AreEqual(3, MathUtils::findMax({ 1, 3, 3, 2}));     // case 6: Vector with zeros and positive elements
        }
    };
}
