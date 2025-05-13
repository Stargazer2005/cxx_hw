#pragma once

#include <memory>
#include <string>

class Group;

class User {
 public:
  User(int id, const std::string& username, const std::string& email = "",
       int age = 0);

  int getId() const;
  std::string getUsername() const;
  std::string getEmail() const;
  int getAge() const;
  std::shared_ptr<Group> getGroup() const;

  void setUsername(const std::string& username);
  void setEmail(const std::string& email);
  void setAge(int age);
  void setGroup(std::weak_ptr<Group> group);

  void removeFromGroup();

  void printInfo() const;

 private:
  int id_;
  std::string username_;
  std::string email_;
  int age_;
  std::weak_ptr<Group> group_;
};
