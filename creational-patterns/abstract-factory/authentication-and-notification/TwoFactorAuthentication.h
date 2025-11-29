// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

#include <memory>

class AuthenticationMethod;
class NotificationMethod;

class TwoFactorAuthentication {
public:
  virtual ~TwoFactorAuthentication();
  virtual std::unique_ptr<AuthenticationMethod>
  authenticationMethod() const = 0; // Factory method
  virtual std::unique_ptr<NotificationMethod>
  notificationMethod() const = 0; // Factory method

  void verify() const;
  void notify() const;
};
