#include "user.hpp"

#include <iostream>

#include "group.hpp"

User::User(int id, const std::string& username, const std::string& email,
           int age)
    : id_(id), username_(username), email_(email), age_(age) {}

int User::getId() const { return id_; }
std::string User::getUsername() const { return username_; }
std::string User::getEmail() const { return email_; }
int User::getAge() const { return age_; }
std::shared_ptr<Group> User::getGroup() const { return group_.lock(); }

void User::setUsername(const std::string& username) { username_ = username; }
void User::setEmail(const std::string& email) { email_ = email; }
void User::setAge(int age) { age_ = age; }
void User::setGroup(std::weak_ptr<Group> group) { group_ = group; }

void User::removeFromGroup() { group_.reset(); }

void User::printInfo() const {
  std::cout << "User ID: " << id_ << "\n";
  std::cout << "Username: " << username_ << "\n";
  std::cout << "Email: " << email_ << "\n";
  std::cout << "Age: " << age_ << "\n";

  if (auto group = group_.lock())
    std::cout << "Group ID: " << group->getId() << "\n";
  else
    std::cout << "Not in any group\n";

  std::cout << "------------------\n";
}
