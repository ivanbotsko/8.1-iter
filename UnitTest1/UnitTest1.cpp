#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../PR 8.1/PR 8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(YourTestClass)
    {
    public:

        TEST_METHOD(TestCountFunction)
        {
            const char* testString1 = "abcabcabc";  // тестовий рядок з трьома групами "abc"
            const char* testString2 = "ababab";     // тестовий рядок без груп "abc"
            const char* testString3 = "";           // порожній рядок

            const char* cs = "abc";

            // Очікувані результати
            int expectedCount1 = 3;
            int expectedCount2 = 0;
            int expectedCount3 = 0;

            // Перевірка роботи функції Count
            int result1 = Count(testString1, cs);
            int result2 = Count(testString2, cs);
            int result3 = Count(testString3, cs);

            // Перевірка результатів тестів
            Assert::AreEqual(expectedCount1, result1);
            Assert::AreEqual(expectedCount2, result2);
            Assert::AreEqual(expectedCount3, result3);
        }
    };
}
