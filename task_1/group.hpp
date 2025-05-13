#pragma once

#include <memory>
#include <string>
#include <vector>

class User;

class Group : public std::enable_shared_from_this<Group> {
 public:
  Group(int id);

  int getId() const;
  const std::vector<std::weak_ptr<User>>& getUsers() const;

  void addUser(std::shared_ptr<User> user);
  void removeUser(std::shared_ptr<User> user);

  void printInfo() const;

 private:
  int id_;
  std::vector<std::weak_ptr<User>> users_;
};
