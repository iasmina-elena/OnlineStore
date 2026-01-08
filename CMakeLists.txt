cmake_minimum_required(VERSION 3.20)
project(OnlineStore)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)        # spune compilatorului unde sunt .h-urile

add_executable(OnlineStore
        main.cpp
        Product.h
        Product.cpp
        Clothing.h
        Clothing.cpp
        Footwear.h
        Footwear.cpp
        Order.h
        Order.cpp
        Store.h
        Store.cpp)

