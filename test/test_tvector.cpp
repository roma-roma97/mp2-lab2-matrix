#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> matrix(6);
	TVector<int> copy(matrix);
	EXPECT_EQ(matrix, copy);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> matrix(6);
	TVector<int> copy(matrix);
	EXPECT_EQ(false, &matrix[0] == &copy[0]);//адреса первых элементов pVector
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> test(6);
	ASSERT_ANY_THROW(test[-1] = 0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> test(6);
	ASSERT_ANY_THROW(test[test.GetSize() + 1] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> test(5);
	EXPECT_EQ(test, test = test);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> test1(5);
	TVector<int> test2(5);
	test1[2] = 5;
	test2 = test1;
	EXPECT_EQ(test1, test2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> test1(5);
	TVector<int> test2(6);
	test1[3] = 6;
	test2 = test1;
	EXPECT_EQ(5, test2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> test1(5);
	TVector<int> test2(6);
	test1[3] = 6;
	test2 = test1;
	EXPECT_EQ(test1, test2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> test1(5);
	TVector<int> test2(6);
	test1[3] = 6;
	test2 = test1;
	EXPECT_EQ(true, test1 == test2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> test1(5);
	test1[3] = 6;
	EXPECT_EQ(true, test1 == test1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> test1(5);
	TVector<int> test2(6);
	EXPECT_EQ(false, test1 == test2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> test1(6);
	TVector<int> test2(6);
	for (int i = 0; i < test1.GetSize(); i++)
		test1[i] = 1;
	test2 = test2 + 1;
	EXPECT_EQ(test1, test2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> test1(6);
	TVector<int> test2(6);
	for (int i = 0; i < test1.GetSize(); i++)
		test1[i] = -1;
	test2 = test2 - 1;
	EXPECT_EQ(test1, test2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> test1(6);
	TVector<int> test2(6);
	for (int i = 0; i < test1.GetSize(); i++)
	{
		test1[i] = 1;
		test2[i] = 3;
	}
	test1 = test1 * 3;
	EXPECT_EQ(test2, test1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> test1(6);
	TVector<int> test2(6);
	TVector<int> test3(6);
	for (int i = 0; i < test1.GetSize(); i++)
	{
		test1[i] = 1;
		test2[i] = 3;
		test3[i] = 4;
	}
	test1 = test1 + test2;
	EXPECT_EQ(test3, test1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> test1(6);
	TVector<int> test2(10);
	ASSERT_ANY_THROW(test1 + test2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> test1(6);
	TVector<int> test2(6);
	TVector<int> test3(6);
	for (int i = 0; i < test1.GetSize(); i++)
	{
		test1[i] = 5;
		test2[i] = 1;
		test3[i] = 4;
	}
	test1 = test1 - test2;
	EXPECT_EQ(test3, test1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> test1(6);
	TVector<int> test2(10);
	ASSERT_ANY_THROW(test1 - test2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> test1(3);
	TVector<int> test2(3);
	int mul = 12;
	for (int i = 0; i < test1.GetSize(); i++)
	{
		test1[i] = 2;
		test2[i] = 2;
	}
	mul = test1 * test2;
	EXPECT_EQ(12, mul);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> test1(6);
	TVector<int> test2(10);
	ASSERT_ANY_THROW(test1 * test2);
}

