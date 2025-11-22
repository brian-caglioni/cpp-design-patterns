cmake_minimum_required(VERSION 3.10.0)
project(two-factor-authentication VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES
    email/EmailAuthentication.cpp
    email/EmailAuthenticationMethod.cpp
    message/MessageAuthentication.cpp
    message/MessageAuthenticationMethod.cpp
    TwoFactorAuthentication.cpp
    main.cpp
)

add_executable(two-factor-authentication ${SOURCES})

