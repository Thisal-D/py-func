# py-func.h

<hr>

## Introduction
The py-func library offers a comprehensive collection of C++ implementations for common string, vector, and array manipulation tasks. With functions like Slice, Count, Replace, and Join, py-func aims to simplify these operations and seamlessly integrate them into your C++ projects. Whether you're working with strings, vectors, or arrays, py-func provides efficient and user-friendly solutions for your programming needs.

<hr>

### Usage
To use the `py-func` library, include the header file `py-func.h` in your C++ source files:

```
#include "py-func.h"
```

<hr>

## Overview (Functions)

- **range** : 
    - <a href="#generate-seq-nums">Generate a sequence of integers</a>
    - <a href="#slice-str">Slice std::strings</a>
    - <a href="#slice-vector">Slice std::vector</a>
    - <a href="#slice-array">Slice std::array</a>

- **replace** 
    - <a href="#replace-str">Replace std::string</a>
    - <a href="#replace-vector">Replace std::vector</a>
    - <a href="#replace-array">Replace array</a>
    - <a href="#replace-t-array">Replace std::array</a>
- <a href="#split-str">**split** </a>
- **count** :
    - <a href="#count-str">Count in std::string</a>
    - <a href="#count-vector">Count in std::vector</a>
    - <a href="#count-array">Count in array</a>
    - <a href="#count-t-array">Count in std::array</a>
- **join** :
    - <a href="#join-str">Join std::string</a>
    - <a href="#join-vector">Join std::vector</a>
    - <a href="#join-array">Join array</a>
    - <a href="#join-t-array">Join std::array</a>

<hr>

- ### 1. range 
    **The "range" functionality allows you to create a sequence of numbers or extract a sequence of values from iterable data types such as arrays, template arrays, vectors, and strings.**

    <div id="generate-seq-nums">

    #### 1.1. Generate sequence of numbers
        
    - Allows you to generate sequences of numbers(`vector`) in C++, similar to Python's `range()` function. You can create sequences with specified start, end, and step values.

    ### ```py::range<type>(type start, type end, type step)```

    - type
        ``` c++
        int, long int, long long int, unsigned int, unsigned long int, float, double, long double
        ```

    - return type
        ``` c++
        std::vector<type>
        ```

    <br>

    - usage
    
        ``` c++
        // Generate sequence of integers from 0 to 9 with a step of 1
        py::range<int>(0, 10, 1) -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

        // Generate sequence of unsigned integers from 0 to 8 with a step of 2
        py::range<unsigned int>(0, 10, 2) -> {0, 2, 4, 6, 8}

        // Generate sequence of long integers from -1 to -5 with a step of -1
        py::range<long int>(-1, -5, -1) -> {1, -2, -3, -4, -5}

        // Generate sequence of floats from 0.1 to 0.9 with a step of 0.1
        py::range<float>(0, 1, 0.1) -> {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}
        ```

    </div>

    <hr>
    
    <div id="slice-str">

    #### 1.2. Slice std::string

    - It allows you to extract a subsequence from a given string based on specified start, end, and step values.

    ### ``py::range(std::string source, long long start, long long end, long long step)``
    
    - return type
        ``` c++
        std::string
        ```
    
    <br>

    - usage
        ``` c++  
        std::string string = "0123456789"

            py::range(string, 0, 5, 1)** -> "01234"

            py::range(string, 0, 10, 2)** -> "02468"

            py::range(string, -1, -5, -1)** -> "9876"

            py::range(string, -1, -10, -2)** -> "97531"

        ```
    
    </div>

    <hr>

    <div id="slice-vector">

    #### 1.3. Slice std::vector

    - It allows you to extract a subsequence from a given vector based on specified start, end, and step values.

    ### ``py::range(std::vector<type> source,long long start, long long end, long long step)``

    - type
        ```c++
        any type
        ```

    - return type
        ``` c++
        std::vector<type>
        ```
    
    <br>

    - usage
        ``` c++ 
        std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    
            py::range(numbers, 0, 5, 1) -> {0, 1, 2, 3, 4}

            py::range(numbers, 0, 10, 2) -> {0, 2, 4, 6, 8}    

            py::range(numbers, -1, -5, -1) -> {9, 8, 7, 6}

            py::range(numbers, -1, -10, -2) -> {9, 7, 5, 3, 1}
        ```
    </div>

    <hr>

    <div id="slice-array">

    #### 1.4. Slice array

    - It allows you to extract a subsequence from a given array based on specified start, end, and step values.

    ### ``py::range(type *array, size_t size, long long start, long long end, long long step)``

    - type
        ``` c++
        any type
        ```

    - return type
        ``` c++
        *any type
        ```

    <br>

    - usage
        ``` c++
        int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

            py::range(numbers, 10, 0, 5, 1) -> {0, 1, 2, 3, 4}

            py::range(numbers, 10, 0, 10, 2) -> {0, 2, 4, 6, 8}

            py::range(numbers, 10, -1, -5, -1) -> {9, 8, 7, 6}

            py::range(numbers, 10, -1, -10, -2) -> {9, 7, 5, 3, 1}
        ```

        <hr>

        ``` c++
        char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

            py::range(characters, 5, 0, 3, 1) -> {'h', 'e', 'l'}

            py::range(characters, 5, -1, -5, -1) -> {'o', 'l', 'l', 'e'}
        ```
        <hr>

        ``` c++
        const char * characters = "hello"

            py::range(characters, 5, 0, 3, 1) -> {'h', 'e', 'l'}

            py::range(characters, 5, -1, -5, -1) -> {'o', 'l', 'l', 'e'}
        ```

    </div>

<hr>

- ### 2. replace 

    -  replaces a specified value with another value in Iterable data types eg:- arrays, template arrays, vectors and strings.

    <div id="replace-str">

    #### 2.1. replace strings

    ### ``py::replace(std::string source, type1 search, type2 replace)``

    - type1
        ``` c++
        std::string, char
        ```

    - type2
        ``` c++
        char, std::string
        ```
    
    - return type
        ``` c++
        std::string
        ```

    <br>
    
    - usage
        ``` c++
        std::string str = "my name is Name, Name is 10 years old."
 
            py::replace(str, "Name", "john Watson") -> "john Watson is 10 years old.john Watson is 50 years old."

            py::replace(str, '1', "5") -> "my name is Name, Name is 50 years old."
        ```

    </div>

    <hr>

    <div id="replace-vector">

    #### 2.2. replace vectors
    
    ### ``py::replace<type>(std::vector<type>, type search, type replace)``

    - type
        ``` c++
        any type
        ```

    - return type
        ``` c++
        std::vector<any type>
        ```

    <br>

    - usage

        ``` c++
        std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6}

            py::replace(numbers, 1, 100) -> {100, 100, 2, 2, 3, 4, 5, 5, 6}

            py::replace(numbers, 5, 1) -> {1, 1, 2, 2, 3, 4, 1, 1, 6}
        ```

        <hr>

        ``` c++
        std::vector<std::string> strs = {"abc", "def", "ghi"}

            py::replace(strs, "abc", "replaced") -> {"replaced", "def", "ghi"}

            py::replace<std::string>(strs, "def", "replaced") ->  {"abc", "def", "replaced"}
        ```

    </div>

    <hr>

    <div id="replace-array">

    #### 2.3. replace arrays

    ### ``py::replace(type *array, size_t size, type search, type replace)``

    - type
        ``` c++
        any type
        ```
    
    - return type
        ``` c++
        *any type
        ```

    <br>

    - usage

        ``` c++
        int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4, 5}
     
            py::replace(numbers,10, 0, 100)** -> {100, 100, 100, 1, 2, 3, 3, 4, 4, 5}
        ```

        <hr>

        ``` c++
        char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

            py::replace(characters, 5, 'l', 'L')** -> {'h', 'e', 'L', 'L', 'o', '\0'}
        ```

    </div>

    <hr>

    <div id="replace-t-array">

    #### 2.4. replace templatize arrays

    ### ``py::replace(std::array<type, size_t size>, type search, type replace)``

    - type 
        ``` c++
        any type
        ```

    - return type
        ``` c++
        std::array<any type, size>
        ```

    <br>

    - usage
    
        ``` c++
        std::array<int, 5> numbers= {0, 0, 0, 1, 2}

            py::replace(numbers, 0, 100) -> {100, 100, 100, 1, 2}
        ```

        <hr>

        ``` c++
        std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'}

            py::replace(characters, 'l', 'L') -> {'h', 'e', 'L', 'L', 'o', '\0'}
        ```

    </div>

    <hr>

    <div id="split-str">

- ### 3. split 

    - Split a std::string into a std::vector< std::string> where each word is a list item

    ### ``py::split(std::string source, type splitter)``

    - type
        ``` c++
        char, std::string
        ```
    
    - return type
        ``` c++
        std::vector<std::string>
        ```
        

    <br>

    - usage
        ``` c++
        std::string str = "1,2,3,4,5";`

            py::split(str, ",")** -> {"1", "2", "3", "4", "5"}
        ```

        <hr>

        ``` c++
        std::string str = "1>>432>>3>>4213>>5"

            py::split(str, ">>") -> {"1", "432", "3", "4213", "5"}

            py::split(str, '>') -> {"1", "", "432", "", "3", "", "4213", "", "5"}
        ```

        <hr>

        ``` c++
        std::string str = "c:/users/user/appdata";`

            py::split(str, "/") -> {"c:", "users", "user", "appdata"}
        ```

    </div>

<hr>

- ### 4. count 

    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    <div id="count-str">

    #### 4.1. count in strings

    ### ``py::count<type2>(std::string source, type search)``

    - type
        ``` c++
        std::string, char
        ```

    - type2
        ``` c++
        int, long int, long long int, unsigned long, unsigned long long, double, float 
        ```

    <br>

    - usage
    ``` c++
        std::string str = "11234123"

            py::count<int>(str, "1") -> 3

            py::count<long long int>(str, "2") -> 2

            py::count<int>(str, "123") -> 2
    ```

    </div>

    <hr>

    <div id="count-vector">

    #### 4.2. count in vectors

    ### ``py::count<type, type2>(std::vector<type>, type search)``

    - type
        ``` c++
        any type
        ```
    
    - type2
        ``` c++
        int, long int, long long int, unsigned long, unsigned long long, double, float 
        ```

    <br>

    - usage

        ``` c++
        std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6}

            py::count<int, int>(numbers, 1)** -> 2

            py::count<int, int>(numbers, 6)** -> 1
        ```

        <hr>
        
        ``` c++
        std::vector<std::string> strs = {"abc", "def", "ghi", "abc", "abc"}

            py::count<std::string, long long int>(strs, "abc") -> 3
        ```

    </div>

    <hr>

    <div id="count-array">

    #### 4.3. count in arrays

    ### ``py::count<type, type2>(type *array, size_t size, type search)``

    - type
        ``` c++
        any type
        ```

    - type2
        ``` c++
        int, long int, long long int, unsigned long, unsigned long long, double, float 
        ```

    - return type
        ``` c++
        unsigned long long
        ```

    <br>

    - usage

        ``` c++
        int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4, 1}

            py::count<int, int>(numbers, 10, 0) -> 3
        ```

        <hr>

        ``` c++
        char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

            py::count<char, int>(characters, 5, 'l') -> 2
        ```

    </div>

    <hr>

    <div id="count-t-array">

    #### 4.4 . count in templatize arrays

    ### ``py::count<type, size, type2>(std::array<type, size_t size>, type search)``

    - type 
        ``` c++
        any type
        ```

    - type2
        ``` c++
        int, long int, long long int, unsigned long, unsigned long long, double, float 
        ```
        
    <br>

    - usage

        ``` c++
        std::array<int, 5> numbers= {0, 0, 0, 1, 2}

            py::count<int, 5, int>(numbers, 0)** -> 3

            py::count<int, 5, long int>(numbers, 0)** -> 3  
        ```

        <hr>

        ``` c++
        std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'}

            py::count<char, 5, int>(characters, 'l') -> 3
        ```

    </div>

<hr>

- ### 5 . join 

    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    <div id="join-str">

    #### 5.1 . join strings

    ### ``py::join(std::string source, type join_by)``

    - type
        ``` c++
        std::string, char
        ```
    
    <br>

    - usage

        ``` c++
        std::string str = "2468";
      
            py::join(str, ",") -> "2,4,6,8"

            py::join(str, "--") -> "2--4--6--8"

            py::join(str, '|') -> "2|4|6|8"
        ```

    </div>

    <hr>

    <div id="join-vector">

    #### 5.2 . join 
    
    ### ``py::join(std::vector<type> source, type join_by)``

    - type
        ``` c++
        std::string, char
        ```

    <br>

    - usage

        ``` c++
        std::vector<std::string> strs = {"abc","def","ghi","jkl"}
 
            py::join(strs, "+") -> "abc+def+ghi+jkl"

            py::join(strs, "_____") -> "abc_____def_____ghi_____jkl"

            py::join(strs, '|') -> "abc|def|ghi|jkl"
        ```

    </div>

    <hr>
    
    <div id="join-array">

    #### 5.3 . join arrays

    ### ``py::join(type *array, size_t size, type join_by);``

    - type
        ``` c++
        std::string, char
        ```
    
    - return type
        ``` c++
        std::string
        ```
    
    <br>

    - usage

        ``` c++
        std::string strs[] = {"abc","def","ghi","jkl"}
     
            py::join(strs, 4, "||||") -> "abc||||def||||ghi||||jkl"

            py::join(strs, 4, "-") -> "abc-def-ghi-jkl" 
        ```

        <hr>

        ``` c++
        char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}
        
            py::join(characters, 5, ',') -> "h,e,l,l,o"
        ```

    </div>

    <div id="join-t-array">

    <hr>

    #### 5.4 . join templatize arrays

    ### ``py::join(std::array<type, size_t size>, type join_by)``

    - type 
        ``` c++
        std::string, char
        ```
    
    - return type
        ``` c++
        std:string
        ```

    <br>

    - usage 
        ``` c++
        std::array<char, 5> characters= {'0', '0', '0', '1', '2'}

            py::join(characters, '=') -> "0=0=0=1=2"
        ```
        
        <hr>

        ``` c++
        std::array<std::string, 4> strs= {"a","b","c","d"}

            py::join(strs, ">") -> "a>b>c>d"
        ```

    </div>
