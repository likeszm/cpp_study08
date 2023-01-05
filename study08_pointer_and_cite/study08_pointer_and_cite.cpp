/*
* 名称：指针和引用测试
* 
* 收获：
* 1、指针是会保存范围信息的，通过指针的类型来实现，就比如array[4][4]，
*   利用sizeof读取时 array 大小为16，*array即array[0] 大小为4，**array大小为1
* 2、只有静态的局部变量才允许用指针或者引用返回，否则刚返回就被销毁了
* 3、引用只允许创建时初始化，不允许修改，这一点类似const
*   引用不允许为空，创建时必须初始化，这也和const类似
* 4、引用作为参数和返回值的时候有奇效
* 
*/

#include <iostream>
#include <ctime>

void dual_pointer_test(void);
void null_pointer_test(void);
void pointer_operation_test(void);
void pointer_pointer_test(void);
void time_test_1(unsigned int* ptr);
unsigned int* time_test_2(void);
void cite_test(void);
int& cite_as_return_test(int);
int& cite_as_return_test_(void);

int global_array[] = { 0,1,2,3,4,5,6,7,8,9 };

int main()
{
    unsigned int time = 0;

    //dual_pointer_test();
    //null_pointer_test();
    //pointer_operation_test();
    //pointer_pointer_test();
    //std::cout << "time = " << (time_test_1(&time), time) << std::endl;
    //std::cout << "time = " << *(time_test_2()) << std::endl;
    //cite_test();

 //   std::cout << "修改前：array[5] = " << global_array[5] << std::endl;
 //   std::cout << "修改后：array[5] = " << (cite_as_return_test(5) = 1112, global_array[5]) << std::endl;

 //   for (int i = 0; i < 3; i++) std::cout << " x = " << cite_as_return_test_()++ << std::endl;

    std::cout << "\n完成测试\n";
    return 0;
}

void dual_pointer_test(void)
{
    char test_array[4][4] = { 0 };
    char* p = NULL;
    std::cout << "创建array[4][4]和*p" << std::endl;
    std::cout << "sizeof( p ) = " << sizeof(p) << std::endl;
 // std::cout << "( p ) = " << (p) << std::endl;           //空指针，不可访问
    std::cout << "sizeof( *p ) = " << sizeof(*p) << std::endl;
 // std::cout << "( *p ) = " << (*p) << std::endl;        //空指针，不可访问
    std::cout << "sizeof( array ) = " << sizeof(test_array) << std::endl;
    std::cout << "( array ) = " << (test_array) << std::endl;
    std::cout << "sizeof( *array ) = " << sizeof(*test_array) << std::endl;
    std::cout << "( *array ) = " << (*test_array) << std::endl;
    std::cout << "sizeof( **array ) = " << sizeof(**test_array) << std::endl;   
    std::cout << "( **array ) = " << (**test_array) << std::endl;
    std::cout << "sizeof( array ) = " << sizeof(test_array) << std::endl;
    std::cout << "( array ) = " << (test_array) << std::endl;
    std::cout << "sizeof( array[0] ) = " << sizeof(test_array[0]) << std::endl;
    std::cout << "( array[0] ) = " << (test_array[0]) << std::endl;
    std::cout << "sizeof( array[0][0] ) = " << sizeof(test_array[0][0]) << std::endl;
    std::cout << "( array[0][0] ) = " << test_array[0][0] << std::endl;

}

void null_pointer_test(void)
{
    int test = 1112;
    int* p_test = &test;
    std::cout << "修改前测试：" << std::endl;
    if (p_test)
    {
        std::cout << "这不是一个空指针" << std::endl;
    }
    else
    {
        std::cout << "这是一个空指针!" << std::endl;
    }
    std::cout << "指针地址为：" << p_test << "\t指针内容为：" << *p_test << std::endl;

    p_test = NULL;
    std::cout << "修改后测试：" << std::endl;
    if (p_test)
    {
        std::cout << "这不是一个空指针" << std::endl;
    }
    else
    {
        std::cout << "这是一个空指针!" << std::endl;
    }
  //  std::cout << "指针地址为：" << p_test << "指针内容为：" << *p_test << std::endl;
    std::cout << "指针地址为：" << p_test <<"\t无法读取指针内容!"<< std::endl;

}

void pointer_operation_test(void)
{
    const int lenth = 10;
    
    int test_array[lenth] = { 0 };
    
    for (int i = 0; i < lenth; i++)
    {
        test_array[i] = 10 * i;
    }

    int* p_max = test_array + lenth - 1;
    int* p_min = test_array;

    for (int i = 0; i < lenth; i++, p_min++)
    {
        std::cout << "p_min = " << p_min << "\t*p_min = " << *p_min << std::endl;
    }
    for (int i = 0; i < lenth; i++, p_max--)
    {
        std::cout << "p_max = " << p_max << "\t*p_max = " << *p_max << std::endl;
    }

}

void pointer_pointer_test(void)
{
    int test = 1112;
    int* p_test = &test;
    int** p_p_test = &p_test;

    std::cout << "test = " << test << std::endl;
    std::cout << "&test = " << &test << std::endl;

    std::cout << "p_test = " << p_test << std::endl;
    std::cout << "*p_test = " << *p_test << std::endl;
    std::cout << "&p_test = " << &p_test << std::endl;

    std::cout << "p_p_test = " << p_p_test << std::endl;
    std::cout << "*p_p_test = " << *p_p_test << std::endl;
    std::cout << "**p_p_test = " << **p_p_test << std::endl;

}

void time_test_1(unsigned int* ptr)
{
    *ptr = time(NULL);
    return;
}

unsigned int* time_test_2(void)
{
    static unsigned int time_ = 0;
    time_ = time(NULL);
    return &time_;
}

void cite_test(void)
{
    int test = 11;
    int& c_test = test;

    std::cout << "test = " << test << std::endl;
    std::cout << "c_test = " << c_test << std::endl;

    std::cout << "&test = " << &test << std::endl;
    std::cout << "&c_test = " << &c_test << std::endl;

    std::cout << "通过原变量修改：" << std::endl;
    test++;

    std::cout << "test = " << test << std::endl;
    std::cout << "c_test = " << c_test << std::endl;

    std::cout << "通过引用修改：" << std::endl;
    c_test++;

    std::cout << "test = " << test << std::endl;
    std::cout << "c_test = " << c_test << std::endl;

}

int& cite_as_return_test(int i)
{
    int& test = global_array[i];
    return test;
}

int& cite_as_return_test_(void)
{
    static int x = 0;
    return x;
}
