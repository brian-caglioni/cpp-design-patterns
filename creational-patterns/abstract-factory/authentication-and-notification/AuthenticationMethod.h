// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#pragma once

class AuthenticationMethod {
public:
  virtual ~AuthenticationMethod() = default;
  virtual void send() const = 0;
};
