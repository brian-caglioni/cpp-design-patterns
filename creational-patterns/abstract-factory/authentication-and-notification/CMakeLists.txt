cmake_minimum_required(VERSION 3.10.0)
project(authentication-and-notification VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES
    message/MessageTwoFactor.cpp
    message/MessageAuthenticationMethod.cpp
    message/MessageNotificationMethod.cpp
    email/EmailTwoFactor.cpp
    email/EmailAuthenticationMethod.cpp
    email/EmailNotificationMethod.cpp
    TwoFactorAuthentication.cpp
    main.cpp
)

add_executable(authentication-and-notification ${SOURCES})

