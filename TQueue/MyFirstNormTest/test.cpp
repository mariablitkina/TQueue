#include "pch.h"
#include "..\TQueue\TQueue.h"

TEST(TQueue, can_create_queue) 
{
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, can_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}

TEST(TQueue, can_create_queue_zero_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(0));
}
TEST(TQueue, can_create_queue_one_length)
{
	ASSERT_NO_THROW(TQueue<int> q(1));
}

TEST(TQueue, new_created_queue_is_empty)
{
	TQueue<int> q(3);
	ASSERT_TRUE(q.IsEmpty());
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(3);
	ASSERT_NO_THROW(TQueue<int> c=q);
}

TEST(TQueue, copied_queue_is_equal_to_sorce_one)
{
	int size = 3;
	TQueue<int> q(size);
	for (int i = 0; i < size; i++)
	{
		q.Push(i+1);
	}
	TQueue<int> c = q;
	EXPECT_EQ(c, q);
};

TEST(TQueue, can_assign_queues_with_equal_size)
{
	TQueue<int> q1(3);
	for (int i = 0; i < 3; i++)
	{
		q1.Push(1);
	}
	TQueue<int> q2(3);
	q1 = q2;
	EXPECT_EQ(q1, q2);
}

TEST(TQueue, can_assign_queues_with_diffrent_size)
{
	TQueue<int> q1(3);
	for (int i = 0; i < 3; i++)
	{
		q1.Push(1);
	}
	TQueue<int> q2(4);
	q1 = q2;
	EXPECT_EQ(q1, q2);
}

TEST(TQueue, can_assign_queues_to_itself)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
	{
		q.Push(1);
	}
	q = q;
	EXPECT_EQ(q, q);
}

TEST(TQueue, can_push_and_pop)
{
	TQueue<int> q(3);
	int elem = 1;
	int p;
	ASSERT_NO_THROW(q.Push(elem));
	ASSERT_NO_THROW(p=q.Pop());

	EXPECT_EQ(elem, p);
}

