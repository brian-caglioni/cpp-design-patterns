// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.

#include "../AuthenticationMethod.h"

class EmailAuthenticationMethod : public AuthenticationMethod {
  void send() const override;
};