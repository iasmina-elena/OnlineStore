cmake_minimum_required(VERSION 3.20)
project(OnlineStore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(OnlineStore
        main.cpp
        Product.cpp
        Clothing.cpp
        Footwear.cpp
        PremiumClothing.cpp
        PaymentMethod.cpp
        CashOnDelivery.cpp
        CardPayment.cpp
        Customer.cpp
        Order.cpp
        Store.cpp
)

# dacă header-ele sunt în același folder cu CMakeLists.txt, asta e suficient
target_include_directories(OnlineStore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
