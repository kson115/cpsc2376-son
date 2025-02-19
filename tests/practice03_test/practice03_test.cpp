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
        TEST_METHOD(TestSumRange1)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5));    // case 1: standard ranges
        }
        TEST_METHOD(TestSumRange2)
        {
            Assert::AreEqual(0, MathUtils::sumRange(0, 0));     // case 2: Empty range 
        }
        TEST_METHOD(TestSumRange3)
        {
            Assert::AreEqual(-3, MathUtils::sumRange(-3, 2));   // case 3: mixed Negative to positive range
        }
        TEST_METHOD(TestSumRange4)
        {
            Assert::AreEqual(4, MathUtils::sumRange(4, 4));     // case 4: start == end
        }
        TEST_METHOD(TestSumRange5)
        {
            Assert::AreEqual(6, MathUtils::sumRange(0, 3));     // case 5: Zero to positive range
        }
        TEST_METHOD(TestSumRange6)
        {
            Assert::AreEqual(-15, MathUtils::sumRange(-5, -1)); // case 6: Negative to negative range
        }
        TEST_METHOD(TestContainsNegative1)
        {
            Assert::IsFalse(MathUtils::containsNegative({ 1, 2, 3 }));  // case 1: all positive 
        }
        TEST_METHOD(TestContainsNegative2)
        {
            Assert::IsTrue(MathUtils::containsNegative({ -1, 2, 3 }));  // case 2: Contains negatives 
        }
        TEST_METHOD(TestContainsNegative3)
        {
            Assert::IsFalse(MathUtils::containsNegative({}));           // case 3: Empty vector
        }
        TEST_METHOD(TestContainsNegative4)
        {
            Assert::IsTrue(MathUtils::containsNegative({ -1, -2, -3 }));// case 4: All negatives
        }
        TEST_METHOD(TestContainsNegative5)
        {
            Assert::IsTrue(MathUtils::containsNegative({ -1 }));        // case 5: Single negative element
        }
        TEST_METHOD(TestContainsNegative6)
        {
            Assert::IsFalse(MathUtils::containsNegative({ 1 }));        // case 6: Single positive element
        }
        TEST_METHOD(TestFindMax1)
        {
            Assert::AreEqual(7, MathUtils::findMax({ 3, -1, 5, 7 }));   // case 1: standard input  
        }
        TEST_METHOD(TestFindMax2)
        {
            Assert::AreEqual(0, MathUtils::findMax({}));                // case 2: Empty vector 
        }
        TEST_METHOD(TestFindMax3)
        {
            Assert::AreEqual(5, MathUtils::findMax({ 5, 5, 5 }));       // case 3: All same elements 
        }
        TEST_METHOD(TestFindMax4)
        {
            Assert::AreEqual(10, MathUtils::findMax({ 10 }));           // case 4: Single element
        }
        TEST_METHOD(TestFindMax5)
        {
            Assert::AreEqual(-7, MathUtils::findMax({ -20, -10, -7 }));  // case 5: All negative elements
        }
        TEST_METHOD(TestFindMax6)
        {
            Assert::AreEqual(3, MathUtils::findMax({ 1, 3, 3, 2 }));     // case 6: numbers[1] = maxValue; numbers[2] = maxValue
        }
    };
}
