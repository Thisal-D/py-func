# py-func
<hr>
<br>

#### you need to include header file before use ,include could be like 

> #include "py-func.h"

## Mainly there are 5 functions. 
### All functions are wrapped by namespace "py"
>  - range 
>  - replace 
>  - split
>  - count 
>  - join

<br>

- ## 1 . range 
    - Create a sequence of numbers or get sequence of values from Iterable data types eg:- arrays, template arrays, vectors and strings

    ### 1 . get sequence of numbers

    ### ``py::range<type>(long long start, long long end, long long step); ``

    - types 
    
    ```
    int, long int, long long int, unsigned int, unsigned long int, float, double, long double
    ```
    - ` `
        - `std::vector<int> num_sequence = py::range<int>(0, 10, 1);`
            num_sequence is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
        - `std::vector<unsigned int> num_sequence = py::range<unsigned int>(0, 10, 2);`
            num_sequence is {0, 2, 4, 6, 8}
        - `std::vector<long int> num_sequence = py::range<long int>(-1, -5, -1);`
            num_sequence is {-1, -2, -3, -4, -5}
        - `std::vector<float> num_sequence = py::range<float>(0, 1, 0.1);`
            num_sequence is {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}


    

    ### 2 . get sequence std::string of std::string 

    ### ``py::range(std::string source, long long start ,long long end ,long long step); ``

    - `std::string string = "0123456789";`
        - `std::string string_sequence = py::range(string, 0, 5, 1);`    
            string_sequence is "01234"
        - `std::string string_sequence = py::range(string, 0, 10, 2);`
            string_sequence is "02468"
        - `std::string string_sequence = py::range(string, -1, -5, -1);`
            string_sequence is "9876" 
        - `std::string string_sequence = py::range(string, -1, -10, -2);`
            string_sequence is "97531" 


    ### 3 . get sequence of std::vector of std::vector 

    ### ``py::range(std::vector<type> source,long long start ,long long end ,long long step); ``

    - types 
    
    ```
    any type
    ```

    - `std::vector<int> numbers = {0, 1, 2, 3, 5, 6, 7, 8, 9};`
        - `std::vector<int> numbers_sequence = py::range(numbers, 0, 5, 1);`  
            numbers_sequence is {0, 1, 2, 3, 4}
        - `std::vector<int> numbers_sequence = py::range(numbers, 0, 10, 2);`
            numbers_sequence is {0, 2, 4, 6, 8}
        - `std::vector<int> numbers_sequence = py::range(numbers, -1, -5, -1);`
            numbers_sequence is {9, 8, 7, 6}
        - `std::vector<int> numbers_sequence = py::range(numbers, -1, -10, -2);`
            numbers_sequence is {9, 7, 5, 3, 1}
    
    ### 4 . get sequence of array of array 

    ### ``py::range<type,size>(*array, long long start ,long long end ,long long step); ``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    array size
    ```

    - `int numbers[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9};`
        - `int *numbers_sequence = py::range<int, 10>(numbers, 0, 5, 1);`        
            numbers_sequence is {0, 1, 2, 3, 4}
        - `int *numbers_sequence = py::range<int, 10>(numbers, 0, 10, 2);`
            numbers_sequence is {0, 2, 4, 6, 8}
        - `int *numbers_sequence = py::range<int, 10>(numbers, -1, -5, -1);`
            numbers_sequence is {9, 8, 7, 6}
        - `int *numbers_sequence = py::range<int, 10>(numbers, -1, -10, -2);`
            numbers_sequence is {9, 7, 5, 3, 1}
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        - `char *characters_sequence = py::range<char, 5>(characters, 0, 3, 1);`
            characters_sequence is {'h', 'e', 'l'}
        - `char *characters_sequence = py::range<char, 5>(characters, -1, -5, -1);`
            characters_sequence is {'o', 'l', 'l', 'e'}
    - `const char * characters = "hello" ;`
        - `char *characters_sequence = py::range<char, 5>(characters, 0, 3, 1);`
            characters_sequence is {'h', 'e', 'l'}
        - `char *characters_sequence = py::range<char, 5>(characters, -1, -5, -1);`
            characters_sequence is {'o', 'l', 'l', 'e'}


- ## 1 . replace 
    -  replaces a specified value with another value in Iterable data types eg:- arrays, template arrays, vectors and strings.


    ### 1 . replace strings

    ### ``py::range(std::string source, type1 search ,type1 replace);``

    - types 
    
    ```
    std::string ,char
    ```
    - `std::string str = "my name is Name, Name is 10 years old.";`
        - `std::string replaced_str = py::replace(str, "Name", "john Watson");`
            replaced_str is "my name is john Watson, john Watson is 10 years old.";
        - `std::string replaced_str = py::replace(str, '1', "5");`
            replaced_str is "my name is Name, Name is 50 years old.";

        

    ### 2 . replace vectors
    ### ``py::range(std::vector<type>, type search, type replace);``

    - types 
    
    ```
    any type
    ```
    - `std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6};`
        - `std::vector<int> replaced_numbers = py::range(numbers, 1, 100);`s
            replaced_numbers is {100, 100, 2, 2, 3, 4, 5, 5, 6}
         - `std::vector<int> replaced_numbers = py::range(numbers, 5, 1);`
            replaced_numbers is {1, 1, 2, 2, 3, 4, 1, 1, 6}
    - `std::vector<std::string> strs = {"abc", "def", "ghi"};`
        - `std::vector<std::string> replaced_strs = py::range(strs, "abc", "abcdef");`        
            replaced_strs is {"abcdef", "def", "ghi"}



    ### 3 . replace arrays

    ### ``py::range<type,size>(*array, type search, type replace);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    array size
    ```

    - `int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4};`
        - `int *replaced_numbers = py::replace<int, 10>(numbers, 0, 100);`           
            replaced_numbers is {100, 100, 100, 1, 2, 3, 3, 4, 4}
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        - `char *replaced_characters = py::range<char, 5>(characters, 'l', 'L');`              
            characters_sequence is {'h', 'e', 'L', 'L', 'o', '\0';}

    ### 4 . replace templatize arrays

    ### ``py::range<type, size>(std::array<type, size_t size>, type search, type replace);``
    ### ``py::range(std::array<type, size_t size>, type search, type replace);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    templatize array size
    ```

    - `std::array<int, 5> numbers= {0, 0, 0, 1, 2};`
        - `std::array<int, 5> replaced_numbers = py::replace<int, 5>(numbers, 0, 100);`              
            replaced_numbers is {100, 100, 100, 1, 2};
    - `std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'};`
        - `char *replaced_characters = py::range<char, 5>(characters, 'l', 'L');`     
            replaced_characters is {'h', 'e', 'L', 'L', 'o', '\0';}
