// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include <iostream>
#include <memory>

class AuthenticationMethod {
public:
  virtual ~AuthenticationMethod() = default;
  virtual void send() const = 0;
};

class EmailAuthenticationMethod : public AuthenticationMethod {
  void send() const override { std::cout << "- Email has been sent!\n"; };
};

class MessageAuthenticationMethod : public AuthenticationMethod {
  void send() const override { std::cout << "- Message has been sent!\n"; };
};

class TwoFactorAuthentication {
public:
  virtual ~TwoFactorAuthentication() = default;
  virtual std::unique_ptr<AuthenticationMethod> authMethod() const = 0;

  void verify() const { this->authMethod()->send(); }
};

class EmailAuthentication : public TwoFactorAuthentication {
  std::unique_ptr<AuthenticationMethod> authMethod() const override {
    return std::make_unique<EmailAuthenticationMethod>();
  }
};

class MessageAuthentication : public TwoFactorAuthentication {
  std::unique_ptr<AuthenticationMethod> authMethod() const override {
    return std::make_unique<MessageAuthenticationMethod>();
  }
};

int main(int, char **) {
  std::cout
      << "\n#### cpp-design-patterns/creational-patterns/factory ####\n\n";

  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth1 =
      std::make_unique<EmailAuthentication>();

  std::unique_ptr<TwoFactorAuthentication> twoFactorAuth2 =
      std::make_unique<MessageAuthentication>();

  twoFactorAuth1->verify();
  twoFactorAuth2->verify();

  std::cout
      << "\n#### cpp-design-patterns/creational-patterns/factory ####\n\n";
  return 0;
}
