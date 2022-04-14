/*
 *  Thomas Whitworth
 *  04/13/22
 *  Lab 10
 *
 * */

/*  @output_no_errors:
 *
 *  intArr:
 *      -> 0 1 2 3 4 5 6 7 8 9
 *  charArr:
 *      -> A B C D E F G H I J
 *
 *  Search for value: 7
 *      -> 7 was found at position: 7
 *
 *  Search for value: C
 *      -> C was found at position: 2
 *
 * */

/*  @output_with_integer_that_is_out_of_bounds:
 *
 *  What will cause error: (out of bounds)
 *       const int intSearchVal = 11;
 *
 *  intArr:
 *      -> 0 1 2 3 4 5 6 7 8 9
 *  charArr:
 *      -> A B C D E F G H I J
 *
 *  Search for value: 11
 *      -> 11 was not found in the array
 *
 * */

/*  @output_with_char_that_is_out_of_bounds:
 *
 *  What will cause error: (out of bounds)
 *       const char charSearchVal = Z;
 *
 *  intArr:
 *      -> 0 1 2 3 4 5 6 7 8 9
 *
 *  charArr:
 *      -> A B C D E F G H I J
 *
 *  Search for value: 3
 *      -> 3 was found at position: 3
 *
 *  Search for value: Z
 *      -> Z was not found in the array
 *
 * */

#include <iostream>

template <typename T, typename S>
void display( T* arr, S const sz ) {
    for ( int i = 0; i < sz; i++ ) { std::cout << arr[i] << " "; }
    std::cout << std::endl;
}

template<typename T>
int search( const T searchVal, T* elem, const T sz ) {
    for ( int i = 0; i < sz; i++ )
        if ( elem[i] == searchVal )
            return i;

    return -1;
}

int main()
{
    const int intSearchVal = 3;
    const char charSearchVal = 'Z';
    const int size = 10;
    const int delimiter = -1;
    int result;

    int* _intPtr = nullptr;
    char* _charPtr = nullptr;

    int intArr[ size ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    char charArr[ size ] = { 'A', 'B', 'C', 'D', 'E',
                             'F', 'G', 'H', 'I', 'J' };

    _intPtr = &intArr[0];
    _charPtr = &charArr[0];

    std::cout << "intArr: \n\t-> ";
    display<int, int>( _intPtr, size );

    std::cout << std::endl;

    std::cout << "charArr: \n\t-> ";
    display<char, int>( _charPtr, size );

    std::cout << std::endl;

    result = search<int>(intSearchVal, _intPtr, size);

    std::cout << "Search for value: " << intSearchVal << std::endl;
    if ( result == delimiter )
        std::cout << "\t-> "<< intSearchVal << " was not found in the array" << std::endl;
    else
        std::cout << "\t-> " << intSearchVal << " was found at position: " << result << std::endl;

    std::cout << std::endl;

    result = search<char>(charSearchVal, _charPtr, size);

    std::cout << "Search for value: " << charSearchVal << std::endl;
    if ( result == delimiter )
        std::cout << "\t-> "<< charSearchVal << " was not found in the array" << std::endl;
    else
        std::cout << "\t-> " << charSearchVal << " was found at position: " << result << std::endl;

    return 0;
}