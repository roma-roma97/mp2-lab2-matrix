#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> matrix(6);
	TMatrix<int>copy(matrix);
	EXPECT_EQ(matrix, copy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> matrix(6);
	TMatrix<int>copy(matrix);
	EXPECT_EQ(false, &matrix[0] == &copy[0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> test(10);
	EXPECT_EQ(10, test.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> test(5);
	test[2][2] = 4;
	EXPECT_EQ(4, test[2][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> test(6);
	ASSERT_ANY_THROW(test[-1][-1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> test(6);
	ASSERT_ANY_THROW(test[test.GetSize() + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> test(6);
	EXPECT_EQ(test, test = test);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(6);
	test1[1][1] = 5;
	test2 = test1;
	EXPECT_EQ(test1, test2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(10);
	test2 = test1;
	EXPECT_EQ(6, test2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(10);
	test1[1][1] = 5;
	test2 = test1;
	EXPECT_EQ(test1, test2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(6);
	test1[1][1] = 5;
	test2 = test1;
	EXPECT_EQ(true, test1 == test2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> test1(6);
	test1[1][1] = 5;
	EXPECT_EQ(true, test1 == test1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(10);
	EXPECT_EQ(false, test1 == test2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(6);
	TMatrix<int> test3(6);
	test1[1][1] = 10;
	test1[1][2] = 10;
	test2[1][1] = 4;
	test2[1][2] = 4;
	test3[1][1] = 14;
	test3[1][2] = 14;
	EXPECT_EQ(test3, test1 + test2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(8);
	ASSERT_ANY_THROW(test1 + test2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(6);
	TMatrix<int> test3(6);
	test1[1][1] = 10;
	test1[1][2] = 10;
	test2[1][1] = 4;
	test2[1][2] = 4;
	test3[1][1] = 6;
	test3[1][2] = 6;
	EXPECT_EQ(test3, test1 - test2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> test1(6);
	TMatrix<int> test2(8);
	ASSERT_ANY_THROW(test1 - test2);
}

