// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include <iostream>
#include <memory>

#include "email/EmailAuthentication.h"
#include "message/MessageAuthentication.h"

int main(int, char **) {
  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/factory/"
               "two-factor-authentication ####\n\n";

  // Client code uses the Creator interface.
  // The concrete creator determines which product is created.
  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth1 =
      std::make_unique<EmailAuthentication>();

  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth2 =
      std::make_unique<MessageAuthentication>();

  twoFactorAuth1->verify(); // Internally uses EmailAuthenticationMethod
  twoFactorAuth2->verify(); // Internally uses MessageAuthenticationMethod

  std::cout << "\n#### "
               "cpp-design-patterns/creational-patterns/factory/"
               "two-factor-authentication ####\n\n";
  return 0;
}
