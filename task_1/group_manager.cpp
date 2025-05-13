#include "group_manager.hpp"

#include <iostream>

#include "group.hpp"
#include "user.hpp"

bool GroupManager::createGroup(int id) {
  if (groups_.find(id) != groups_.end()) {
    std::cerr << "Group with ID " << id << " already exists.\n";
    return false;
  }

  auto group = std::make_shared<Group>(id);
  groups_[id] = group;
  return true;
}

bool GroupManager::deleteGroup(int id) {
  auto it = groups_.find(id);
  if (it == groups_.end()) {
    std::cerr << "Group with ID " << id << " not found.\n";
    return false;
  }

  for (const auto& weakUser : it->second->getUsers())
    if (auto user = weakUser.lock()) user->removeFromGroup();

  groups_.erase(it);
  return true;
}

void GroupManager::printAllGroups() const {
  if (groups_.empty()) {
    std::cout << "No groups found.\n";
    return;
  }

  for (const auto& pair : groups_) pair.second->printInfo();
}

void GroupManager::printGroup(int id) const {
  auto it = groups_.find(id);
  if (it == groups_.end()) {
    std::cerr << "Group with ID " << id << " not found.\n";
    return;
  }

  it->second->printInfo();
}

std::shared_ptr<Group> GroupManager::getGroup(int id) const {
  auto it = groups_.find(id);
  if (it == groups_.end()) return nullptr;
  return it->second;
}

bool GroupManager::addUserToGroup(std::shared_ptr<User> user, int groupId) {
  if (!user) return false;

  auto group = getGroup(groupId);
  if (!group) {
    std::cerr << "Group with ID " << groupId << " not found.\n";
    return false;
  }

  if (auto oldGroup = user->getGroup()) oldGroup->removeUser(user);

  group->addUser(user);
  return true;
}