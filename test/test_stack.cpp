#include "stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, move_constructor_works) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2(std::move(s1));
    ASSERT_EQ(s2.size(), 2);
    ASSERT_EQ(s2.top(), 2);
    ASSERT_TRUE(s1.empty());
}

TEST(Stack, move_assignment_operator_works) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2;
    s2 = std::move(s1);
    ASSERT_EQ(s2.size(), 2);
    ASSERT_EQ(s2.top(), 2);
    ASSERT_TRUE(s1.empty());
}

TEST(Stack, swap_works_correctly) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);

    Stack<int> s2;
    s2.push(3);
    s2.push(4);

    s1.swap(s2);

    ASSERT_EQ(s1.size(), 2);
    ASSERT_EQ(s1.top(), 4);
    s1.pop();
    ASSERT_EQ(s1.top(), 3);

    ASSERT_EQ(s2.size(), 2);
    ASSERT_EQ(s2.top(), 2);
    s2.pop();
    ASSERT_EQ(s2.top(), 1);
}


TEST(Stack, swap_works_with_empty_stacks) {
    Stack<int> s1;
    Stack<int> s2;
    s1.swap(s2);
    ASSERT_TRUE(s1.empty());
    ASSERT_TRUE(s2.empty());
}


TEST(Stack, swap_works_with_one_empty_stack) {
    Stack<int> s1;
    s1.push(1);

    Stack<int> s2;

    s1.swap(s2);

    ASSERT_TRUE(s1.empty());
    ASSERT_EQ(s2.size(), 1);
    ASSERT_EQ(s2.top(), 1);
}

TEST(Stack, can_push_element)
{
    Stack<int> s;
    ASSERT_NO_THROW(s.push(5));
}

TEST(Stack, can_pop_element)
{
    Stack<int> s;
    s.push(10);
    ASSERT_NO_THROW(s.pop());
}

TEST(Stack, can_get_top_element)
{
    Stack<int> s;
    s.push(5);
    ASSERT_EQ(s.top(), 5);
}

TEST(Stack, top_throws_when_empty)
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.top());
}

TEST(Stack, pop_throws_when_empty)
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_check_is_empty)
{
    Stack<int> s;
    ASSERT_TRUE(s.empty());
    s.push(10);
    ASSERT_FALSE(s.empty());
}

TEST(Stack, can_get_size) {
    Stack<int> s;
    ASSERT_EQ(s.size(), 0);
    s.push(1);
    ASSERT_EQ(s.size(), 1);
    s.push(2);
    ASSERT_EQ(s.size(), 2);
}

TEST(Stack, can_clear_stack) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();
    ASSERT_TRUE(s.empty());
    ASSERT_EQ(s.size(), 0);
}


TEST(Stack, copy_constructor_works) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2(s1);
    ASSERT_EQ(s1.size(), s2.size());
    ASSERT_EQ(s1.top(), s2.top());
    s2.pop();
    ASSERT_NE(s1.size(), s2.size());
}


TEST(Stack, assignment_operator_works)
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2;
    s2 = s1;
    ASSERT_EQ(s1.size(), s2.size());
    ASSERT_EQ(s1.top(), s2.top());
    s2.pop();
    ASSERT_NE(s1.size(), s2.size());
}

TEST(Stack, equality_operator_works) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2 = s1;
    ASSERT_TRUE(s1 == s2);

    s2.pop();
    ASSERT_FALSE(s1 == s2);


    Stack<int> s3;
    s3.push(2);
    s3.push(1);
    ASSERT_FALSE(s1 == s3);
}


TEST(Stack, inequality_operator_works) {
    Stack<int> s1;
    s1.push(1);
    Stack<int> s2;
    s2.push(2);
    ASSERT_TRUE(s1 != s2);

    Stack<int> s3 = s1;
    ASSERT_FALSE(s1 != s3);
}