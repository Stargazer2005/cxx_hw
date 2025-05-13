#include "user_manager.hpp"

#include <iostream>

#include "user.hpp"

bool UserManager::createUser(int id, const std::string& username,
                             const std::string& email, int age) {
  if (users_.find(id) != users_.end()) {
    std::cerr << "User with ID " << id << " already exists.\n";
    return false;
  }

  auto user = std::make_shared<User>(id, username, email, age);
  users_[id] = user;
  return true;
}

bool UserManager::deleteUser(int id) {
  auto it = users_.find(id);
  if (it == users_.end()) {
    std::cerr << "User with ID " << id << " not found.\n";
    return false;
  }

  if (auto group = it->second->getGroup()) group->removeUser(it->second);

  users_.erase(it);
  return true;
}

void UserManager::printAllUsers() const {
  if (users_.empty()) {
    std::cout << "No users found.\n";
    return;
  }

  for (const auto& pair : users_) pair.second->printInfo();
}

void UserManager::printUser(int id) const {
  auto it = users_.find(id);
  if (it == users_.end()) {
    std::cerr << "User with ID " << id << " not found.\n";
    return;
  }

  it->second->printInfo();
}

std::shared_ptr<User> UserManager::getUser(int id) const {
  auto it = users_.find(id);
  if (it == users_.end()) return nullptr;
  return it->second;
}