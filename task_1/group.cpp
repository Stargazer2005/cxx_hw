#include "group.hpp"

#include <algorithm>
#include <iostream>

#include "user.hpp"

Group::Group(int id) : id_(id) {}

int Group::getId() const { return id_; }

const std::vector<std::weak_ptr<User>>& Group::getUsers() const {
  return users_;
}

void Group::addUser(std::shared_ptr<User> user) {
  if (user) {
    users_.push_back(user);
    user->setGroup(shared_from_this());
  }
}

void Group::removeUser(std::shared_ptr<User> user) {
  if (!user) return;

  users_.erase(std::remove_if(users_.begin(), users_.end(),
                              [&](const std::weak_ptr<User>& weakUser) {
                                if (auto sharedUser = weakUser.lock()) {
                                  return sharedUser->getId() == user->getId();
                                }
                                return false;
                              }),
               users_.end());

  user->removeFromGroup();
}

void Group::printInfo() const {
  std::cout << "Group ID: " << id_ << "\n";
  std::cout << "Members (" << users_.size() << "):\n";

  for (const auto& weakUser : users_)
    if (auto user = weakUser.lock())
      std::cout << "  - " << user->getUsername() << " (ID: " << user->getId()
                << ")\n";

  std::cout << "------------------\n";
}
