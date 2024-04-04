# py-func Header

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
    - Create a sequence of numbers or get sequence of values from Iterable data types eg:- arrays, template arrays, vectors and strings

    <div id="generate-seq-nums">

    #### 1.1. Generate sequence of numbers

    ### ``py::range<type>(type start, type end, type step)``

    - types

        int, long int, long long int, unsigned int, unsigned long int, float, double, long double

    <br>
  
    **py::range<int>(0, 10, 1)** -> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

    **py::range<unsigned int>(0, 10, 2)** -> {0, 2, 4, 6, 8}

    **py::range<long int>(-1, -5, -1)** -> {1, -2, -3, -4, -5}

    **py::range<float>(0, 1, 0.1)** -> {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9}

    </div>

    <hr>
    
    <div id="slice-str">

    #### 1.2. Slice std::string

    ### ``py::range(std::string source, long long start, long long end, long long step)``

    - std::string string = "0123456789"

        **py::range(string, 0, 5, 1)** -> "01234"
      
        **py::range(string, 0, 10, 2)** -> "02468"
      
        **py::range(string, -1, -5, -1)** -> "9876"
        
        **py::range(string, -1, -10, -2)** -> "97531"

    </div>

    <hr>

    <div id="slice-vector">

    #### 1.3. Slice std::vector of std::vector 

    ### ``py::range(std::vector<type> source,long long start, long long end, long long step)``

    - types 

        any type
    
    <br>

    - std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

        **py::range(numbers, 0, 5, 1)** -> {0, 1, 2, 3, 4}

        **py::range(numbers, 0, 10, 2)** -> {0, 2, 4, 6, 8}    

        **py::range(numbers, -1, -5, -1)** -> {9, 8, 7, 6}

        **py::range(numbers, -1, -10, -2)** -> {9, 7, 5, 3, 1}

    </div>

    <hr>

    <div id="slice-array">

    #### 1.4. get sequence of array of array 

    ### ``py::range(type *array, size_t size, long long start, long long end, long long step)``

    - types 

        any type
    
    - size
    
        array 
        
    <br>

    - int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

        **py::range(numbers, 10, 0, 5, 1)** -> {0, 1, 2, 3, 4}

        **py::range(numbers, 10, 0, 10, 2)** -> {0, 2, 4, 6, 8}

        **py::range(numbers, 10, -1, -5, -1)** -> {9, 8, 7, 6}

        **py::range(numbers, 10, -1, -10, -2)** -> {9, 7, 5, 3, 1}

        <hr>

    - char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}
    
        **py::range(characters, 5, 0, 3, 1)** -> {'h', 'e', 'l'}

        **py::range(characters, 5, -1, -5, -1)** -> {'o', 'l', 'l', 'e'}

        <hr>

    - const char * characters = "hello"

        **py::range(characters, 5, 0, 3, 1)** -> {'h', 'e', 'l'}

        **py::range(characters, 5, -1, -5, -1)** -> {'o', 'l', 'l', 'e'}
    
    </div>

<hr>

- ### 2. replace 

    -  replaces a specified value with another value in Iterable data types eg:- arrays, template arrays, vectors and strings.

    <div id="replace-str">

    #### 2.1. replace strings

    ### ``py::replace(std::string source, type1 search, type2 replace)``

    - types 1

        std::string, char
    
    - types 2

        char, std::string

    <br>

    - std::string str = "my name is Name, Name is 10 years old."

        **py::replace(str, "Name", "john Watson")** -> "john Watson is 10 years old.john Watson is 50 years old."

        **py::replace(str, '1', "5")** -> "my name is Name, Name is 50 years old."

    </div>

    <hr>

    <div id="replace-vector">

    #### 2.2. replace vectors
    
    ### ``py::replace<type>(std::vector<type>, type search, type replace)``

    - types 

        any type
    
    <br>

    - std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6}

        **py::replace(numbers, 1, 100)** -> {100, 100, 2, 2, 3, 4, 5, 5, 6}

        **py::replace(numbers, 5, 1)** -> {1, 1, 2, 2, 3, 4, 1, 1, 6}
    
        <hr>

    - std::vector<std::string> strs = {"abc", "def", "ghi"}

        **py::replace(strs, "abc", "replaced")** -> {"replaced", "def", "ghi"}

        **py::replace<std::string>(strs, "def", "replaced")** ->  {"abc", "def", "replaced"}

    </div>

    <hr>

    <div id="replace-array">

    #### 2.3. replace arrays

    ### ``py::replace(type *array, size_t size, type search, type replace)``

    - types 

        any type

    - size 

        array size
   
    <br>

    - int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4, 5}

        **py::replace(numbers,10, 0, 100)** -> {100, 100, 100, 1, 2, 3, 3, 4, 4, 5}

        <hr>

    - char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

        **py::replace(characters, 5, 'l', 'L')** -> {'h', 'e', 'L', 'L', 'o', '\0'}

    </div>

    <hr>

    <div id="replace-t-array">

    #### 2.4. replace templatize arrays

    ### ``py::replace(std::array<type, size_t size>, type search, type replace)``

    - types 

        any type

    - size 

        templatize array size
    
    <br>

    - std::array<int, 5> numbers= {0, 0, 0, 1, 2}

        **py::replace(numbers, 0, 100)** -> {100, 100, 100, 1, 2}

        <hr>

    - std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'}

        **py::replace(characters, 'l', 'L')** -> {'h', 'e', 'L', 'L', 'o', '\0'}

    </div>

    <hr>

    <div id="split-str">

- ### 3. split 

    - Split a std::string into a std::vector< std::string> where each word is a list item

    ### ``py::split(std::string source, type splitter)``

    - types 

        char, std::string

    <br>
    
    - std::string str = "1,2,3,4,5";`

        **py::split(str, ",")** -> {"1", "2", "3", "4", "5"}

        <hr>

    - std::string str = "1>>432>>3>>4213>>5"

        **py::split(str, ">>")** -> {"1", "432", "3", "4213", "5"}

        **py::split(str, '>')** -> {"1", "", "432", "", "3", "", "4213", "", "5"}
        
        <hr>
    
    - std::string str = "c:/users/user/appdata";`

        **py::split(str, "/")** -> {"c:", "users", "user", "appdata"}

    </div>

<hr>

- ### 4. count 

    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    <div id="count-str">

    #### 4.1. count in strings

    ### ``py::count<type2>(std::string source, type search)``

    - types 
    
        std::string, char

    - types 2

        int, long int, long long int, unsigned long, unsigned long long, double, float 
    
    <br>

    - std::string str = "11234123"

        **py::count<int>(str, "1")** -> 3

        **py::count<long long int>(str, "2")** -> 2

        **py::count<int>(str, "123")** -> 2

    </div>

    <hr>

    <div id="count-vector">

    #### 4.2. count in vectors

    ### ``py::count<type, type2>(std::vector<type>, type search)``

    - types 

        any type
    
    - types 2

        int, long int, long long int, unsigned long, unsigned long long, double, float 
    
    <br>

    - std::vector<int> numbers = {1, 1, 2, 2, 3, 4, 5, 5, 6}

        **py::count<int, int>(numbers, 1)** -> 2

        **py::count<int, int>(numbers, 6)** -> 1
        
        <hr>
        
    - std::vector<std::string> strs = {"abc", "def", "ghi", "abc", "abc"}

        **py::count<std::string, long long int>(strs, "abc")** -> 3

    </div>

    <hr>

    <div id="count-array">

    #### 4.3. count in arrays

    ### ``py::count<type, type2>(type *array, size_t size, type search)``

    - types 

        any type

    - size 

        array size
    
    - types 2

        int, long int, long long int, unsigned long, unsigned long long, double, float 
    
    <br>

    - int numbers[10] = {0, 0, 0, 1, 2, 3, 3, 4, 4, 1}

        **py::count<int, int>(numbers, 10, 0)** -> 3

        <hr>
    
    - char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

        **py::count<char, int>(characters, 5, 'l')** -> 2

    </div>

    <hr>

    <div id="count-t-array">

    #### 4.4 . count in templatize arrays

    ### ``py::count<type, size, type2>(std::array<type, size_t size>, type search)``

    - types 

        any type

    - size

        templatize array size

    - types 2

        int, long int, long long int, unsigned long, unsigned long long, double, float 
    
    <br>

    - std::array<int, 5> numbers= {0, 0, 0, 1, 2}

        **py::count<int, 5, int>(numbers, 0)** -> 3

        **py::count<int, 5, long int>(numbers, 0)** -> 3  

        <hr>

    - std::array<char, 5> characters= {'h', 'e', 'l', 'l', 'o'}

        **py::count<char, 5, int>(characters, 'l')** -> 3

    </div>

<hr>

- ### 5 . join 

    - The count method returns the number of elements with the specified value in Iterable. eg:- arrays, template arrays, vectors and strings

    <div id="join-str">

    #### 5.1 . join strings

    ### ``py::join(std::string source, type join_by)``

    - types 

        std::string, char
    
    <br>

    - std::string str = "2468";

        **py::join(str, ",")** -> "2,4,6,8"

        **py::join(str, "--")** -> "2--4--6--8"

        **py::join(str, '|')** -> "2|4|6|8"

    </div>

    <hr>

    <div id="join-vector">

    #### 5.2 . join 
    
    ### ``py::join(std::vector<type> source, type join_by)``

    - types 

        std::string, char

    <br>

    - std::vector<std::string> strs = {"abc","def","ghi","jkl"}
    
        **py::join(strs, "+")** -> "abc+def+ghi+jkl"

        **py::join(strs, "_____")** -> "abc_____def_____ghi_____jkl"

        **py::join(strs, '|')** -> "abc|def|ghi|jkl"

    </div>

    <hr>
    
    <div id="join-array">

    #### 5.3 . join arrays

    ### ``py::join(type *array, size_t size, type2 join_by);``

    - types 

        std::string, char
    
    - types 2

        std::string, char

    - size 

        array size
    
    <br>

    - std::string strs[] = {"abc","def","ghi","jkl"}

        **py::join(strs, 4, "||||")** -> "abc||||def||||ghi||||jkl"

        **spy::join(strs, 4, "-")** -> "abc-def-ghi-jkl" 
    
        <hr>

    - char characters[6] = {'h', 'e', 'l', 'l', 'o', '\0'}

        -  **py::join(characters, 5, ',')** -> "h,e,l,l,o"

    </div>

    <div id="join-t-array">

    <hr>

    #### 5.4 . join templatize arrays

    ### ``py::join(std::array<type, size_t size>, type2 join_by)``

    - types 

        std::string, char
    
    - types 2

        std::string, char 
    
    <br>

    - std::array<char, 5> characters= {'0', '0', '0', '1', '2'}

        **py::join(characters, '=')** -> "0=0=0=1=2"
        
        <hr>

    - std::array<std::string, 4> strs= {"a","b","c","d"}
    
        **py::join(strs, ">")** -> "a>b>c>d"
            
    </div>
