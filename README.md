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

    ### 1.1 . get sequence of numbers

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


    

    ### 1.2 . get sequence std::string of std::string 

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


    ### 1.3 . get sequence of std::vector of std::vector 

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
    
    ### 1.4 . get sequence of array of array 

    ### ``py::range(*array, size_t size, long long start ,long long end ,long long step); ``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    array size
    ```

    - `int numbers[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9};`
        - `int *numbers_sequence = py::range(numbers, 10, 0, 5, 1);`       

            numbers_sequence is {0, 1, 2, 3, 4}
        - `int *numbers_sequence = py::range(numbers, 10, 0, 10, 2);`

            numbers_sequence is {0, 2, 4, 6, 8}
        - `int *numbers_sequence = py::range(numbers, 10, -1, -5, -1);`

            numbers_sequence is {9, 8, 7, 6}
        - `int *numbers_sequence = py::range(numbers, 10, -1, -10, -2);`

            numbers_sequence is {9, 7, 5, 3, 1}
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        - `char *characters_sequence = py::range(characters, 5, 0, 3, 1);`

            characters_sequence is {'h', 'e', 'l'}
        - `char *characters_sequence = py::range(characters, 5, -1, -5, -1);`

            characters_sequence is {'o', 'l', 'l', 'e'}
    - `const char * characters = "hello" ;`
        - `char *characters_sequence = py::range(characters, 5, 0, 3, 1);`

            characters_sequence is {'h', 'e', 'l'}
        - `char *characters_sequence = py::range(characters, 5, -1, -5, -1);`

            characters_sequence is {'o', 'l', 'l', 'e'}


- ## 2 . replace 
    -  replaces a specified value with another value in Iterable data types eg:- arrays, template arrays, vectors and strings.


    ### 2.1 . replace strings

    ### ``py::range(std::string source, type1 search ,type1 replace);``

    - types 
    
    ```
    std::string ,char
    ```
    - `std::string str = "my name is Name, Name is 10 years old.";`
        - `std::string replaced_str = py::replace(str, "Name", "john Watson");`

            replaced_str is "my name is john Watson, john Watson is 10 years old."
        - `std::string replaced_str = py::replace(str, '1', "5");`

            replaced_str is "my name is Name, Name is 50 years old."

        

    ### 2.2 . replace vectors
    ### ``py::range(std::vector<type>, type search, type replace);``

    - types 
    
    ```
    any type
    ```
    - `std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6};`
        - `std::vector<int> replaced_numbers = py::replace(numbers, 1, 100);`

            replaced_numbers is {100, 100, 2, 2, 3, 4, 5, 5, 6}
         - `std::vector<int> replaced_numbers = py::replace(numbers, 5, 1);`

            replaced_numbers is {1, 1, 2, 2, 3, 4, 1, 1, 6}
    - `std::vector<std::string> strs = {"abc", "def", "ghi"};`
        - `std::vector<std::string> replaced_strs = py::replace(strs, "abc", "abcdef");`  

            replaced_strs is {"abcdef", "def", "ghi"}



    ### 2.3 . replace arrays

    ### ``py::replace(*array, size_t size, type search, type replace);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    array size
    ```

    - `int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4};`
        - `int *replaced_numbers = py::replace(numbers,10, 0, 100);`     

            replaced_numbers is {100, 100, 100, 1, 2, 3, 3, 4, 4}
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        - `char *replaced_characters = py::replace(characters, 5, 'l', 'L');`  

            replaced_characters is {'h', 'e', 'L', 'L', 'o', '\0'}

    ### 2.4 . replace templatize arrays

    ### ``py::replace(std::array<type, size_t size>, type search, type replace);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    templatize array size
    ```

    - `std::array<int, 5> numbers= {0, 0, 0, 1, 2};`
        - `std::array<int, 5> replaced_numbers = py::replace(numbers, 0, 100);`    

            replaced_numbers is {100, 100, 100, 1, 2}
    - `std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'};`
        - `char *replaced_characters = py::replace(characters, 'l', 'L');`     

            replaced_characters is {'h', 'e', 'L', 'L', 'o', '\0'}
- ## 3 . split 
    - Split a std::string into a std::vector< std::string> where each word is a list item

    

    ### ``py::split(std::string source, type splitter); ``

    - types 
    
    ```
    char, std::string
    ```
    - `std::string str = "1,2,3,4,5";`
        - `std::vector<std::string> splitted_str = py::split(str, ",");`

            splitted_str is {"1", "2", "3", "4", "5"}
        - `std::vector<std::string> splitted_str = py::split(str, ',');`

            splitted_str is {"1", "2", "3", "4", "5"}
    
    - `std::string str = "1>>432>>3>>4213>>5";`
        - `std::vector<std::string> splitted_str = py::split(str, ">>");`

            splitted_str is {"1", "432", "3", "4213", "5"}
        - `std::vector<std::string> splitted_str = py::split(str, '>');`

            splitted_str is {"1", "", "432", "", "3", "", "4213", "", "5"}
    - `std::string str = "c:/users/user/appdata";`
        - `std::vector<std::string> splitted_str = py::split(str, "/");`
        
            splitted_str is {"c:", "users", "user", "appdata"}

- ## 4 . count 
    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    ### 4.1 . count on strings

    ### ``py::count<type2>(std::string source, type search);``

    - types 
    
    ```
    std::string ,char
    ```

    - types 2
    
    ```
    int ,long int, long long int, unsigned long, unsigned long long, double, float 
    ```
    - `std::string str = "11234123";`
        - `int count = py::count<int>(str, "1");`

            count is 3
        - `long long int count = py::count<long long int>(str, "2");`

            count is 2
        - `int count = py::count<int>(str, "123");`

            count is 2


        

    ### 4.2 . count on  vectors
    ### ``py::count<type2>(std::vector<type>, type search);``

    - types 
    
    ```
    any type
    ```

    - types 2
    
    ```
    int ,long int, long long int, unsigned long, unsigned long long, double, float 
    ```
    - `std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6};`
        - `int count = py::count<int>(numbers, 1);`

            count is 2
        - `int count = py::count<int>(numbers, 6);`

           count is 1
    - `std::vector<std::string> strs = {"abc", "def", "ghi", "abc", "abc"};`
        - `int count = py::count<int>(strs, "abc");`  

            count is 3
    



    ### 4.3 . count on arrays

    ### ``py::count<type, type2>(*array, size_t size, type search);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    array size
    ```
    - types 2
    
    ```
    int ,long int, long long int, unsigned long, unsigned long long, double, float 
    ```

    - `int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4};`
        - `int count = py::count<int, int>(numbers, 10, 0);` 
        - `unsigned long long count = py::count<int, unsigned long long>(numbers, 10, 0);`       

           count is 3
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        -  `int count = py::count<char, int>(characters, 5, 'l');`    

            count is 2

    ### 4.4 . count on templatize arrays

    ### ``py::count<type, size, type2>(std::array<type, size_t size>, type search);``

    - types 
    
    ```
    any type
    ```

    - size 
    
    ```
    templatize array size
    ```
    - types 2
    
    ```
    int ,long int, long long int, unsigned long, unsigned long long, double, float 
    ```

    - `std::array<int, 5> numbers= {0, 0, 0, 1, 2};`
        - `int count = py::count<int, 5, int>(numbers, 0);`
        - `long int count = py::count<int, 5, long int>(numbers, 0);`    

            count is 3
    - `std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'};`
        - `int count = py::count<char, 5, int>(characters, 'l');`     

            count is 2


- ## 5 . join 
    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    ### 5.1 . join strings

    ### ``py::join(std::string source, type join_by);``

    - types 
    
    ```
    std::string ,char
    ```

    - `std::string str = "2468";`
        - `std::string joined_str = py::join(str, ",");`

            joined_str is "2,4,6,8"
        - `std::string joined_str = py::join(str, "--");`

            joined_str is "2--4--6--8"
        - `std::string joined_str = py::join(str, '|');`

            joined_str is "2|4|6|8"


        

    ### 5.2 . join vectors
    ### ``py::join(std::vector<type> source, type join_by);``

    - types 
    
    ```
    std::string, char
    ```

    - `std::vector<std::string> strs = {"abc","def","ghi","jkl"};`
        - `std::string joined_str = py::join(strs, "+");`

            joined_str is "abc+def+ghi+jkl"
        - `std::string joined_str = py::join(strs, "_____");`

            joined_str is "abc_____def_____ghi_____jkl"
        - `std::string joined_str = py::join(strs, '|');`

            joined_str is "abc|def|ghi|jkl"
    



    ### 5.3 . join arrays

    ### ``py::join(*array, size_t size, type search);``

    - types 
    
    ```
    std::string, char
    ```

    - size 
    
    ```
    array size
    ```

    - `std::string strs[] = {"abc","def","ghi","jkl"};`
        - `std::string joined_str  = py::join(strs, 4, "||||");`    

            joined_str is "abc||||def||||ghi||||jkl"

        - `std::string joined_str  = py::join(strs, 4, "-");` 

            joined_str is "abc-def-ghi-jkl" 
    - `char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
        -  `std::string joined_str = py::join(characters, 5, ',');`    

            joined_str is "h,e,l,l,o"

    ### 5.4 . join templatize arrays

    ### ``py::join(std::array<type, size_t size>, type2 search);``

    - types 
    
    ```
    std::string, char
    ```
    - types 2
    
    ```
    std::string, char 
    ```

    - `std::array<char, 5> characters= {'0', '0', '0', '1', '2'};`
        - `std::string joined_str = py::join(characters, '=');`    

            joined_str is "0=0=0=1=2"
    - `std::array<std::string, 4> strs= {"a","b","c","d"};`
        - `std::string joined_str = py::join(strs, ">");`    

            joined_str is "a>b>c>d"
