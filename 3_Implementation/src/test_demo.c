/**
 * @file test_demo.c
 * @author Aashish Kalra(aashish.kalra1999@.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "unity.h"
#include "header.h"
void setUp()
{
} 
void tearDown()
{
}
void test_displayContact(void)
{
    TEST_ASSERT_EQUAL(0, displayContact(100));
}

void test_displayAllContacts(void)
{
    TEST_ASSERT_EQUAL(0, displayAllContacts());
}
void test_contactlistfull(void)
{
    TEST_ASSERT_EQUAL(100,addContact(100));
}

int test_main() // main function for test_demo file
{
    UNITY_BEGIN(); // Initialize Unity Test 
    RUN_TEST(test_displayContact); // Test to chech if contacts exist
    RUN_TEST(test_displayAllContacts); // test to display all contacts
    // RUN_TEST(test_contactlistfull); // test to check if the contact list is full or no
    return UNITY_END(); // End Unity Test 
}