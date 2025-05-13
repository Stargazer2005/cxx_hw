#pragma once

#include <memory>
#include <unordered_map>

#include "group.hpp"
#include "user.hpp"

class GroupManager {
 public:
  bool createGroup(int id);
  bool deleteGroup(int id);
  void printAllGroups() const;
  void printGroup(int id) const;
  std::shared_ptr<Group> getGroup(int id) const;
  bool addUserToGroup(std::shared_ptr<User> user, int groupId);

 private:
  std::unordered_map<int, std::shared_ptr<Group>> groups_;
};
