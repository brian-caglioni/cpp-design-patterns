// Copyright (c) 2025 Brian Caglioni
// Licensed under the MIT License. See LICENSE file in the project root.
#include "EmailNotificationMethod.h"

#include <iostream>

void EmailNotificationMethod::sendNotification() const {
  std::cout << "- Email has been sent!\n";
};
