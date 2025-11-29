// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include <iostream>
#include <memory>

#include "AuthenticationMethod.h"
#include "NotificationMethod.h"

#include "email/EmailTwoFactor.h"
#include "message/MessageTwoFactor.h"

int main(int, char **) {
  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/abstract-factory/"
               "authentication-and-notification/main.cpp####\n\n";

  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth1 =
      std::make_unique<EmailTwoFactor>();
  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth2 =
      std::make_unique<MessageTwoFactor>();

  auto authMethod1 = twoFactorAuth1->authenticationMethod();
  auto notificationMethod1 = twoFactorAuth1->notificationMethod();
  auto authMethod2 = twoFactorAuth2->authenticationMethod();
  auto notificationMethod2 = twoFactorAuth2->notificationMethod();

  authMethod1->send();
  notificationMethod1->sendNotification();

  authMethod2->send();
  notificationMethod2->sendNotification();

  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/abstract-factory/"
               "authentication-and-notification/main.cpp####\n\n";
  return 0;
}
