// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

#include <memory>

class AuthenticationMethod;

class TwoFactorAuthentication {
public:
  virtual ~TwoFactorAuthentication();
  virtual std::unique_ptr<AuthenticationMethod>
  authMethod() const = 0; // Factory method

  void verify() const;
};
