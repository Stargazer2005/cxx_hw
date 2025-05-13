#pragma once

#include <functional>
#include <iostream>
#include <string>

#include "group_manager.hpp"
#include "user_manager.hpp"

class CommandProcessor {
 public:
  CommandProcessor(UserManager& userManager, GroupManager& groupManager);

  void printUsage(const std::string& command) const;
  void processCommand(const std::string& command);
  void printHelp() const;

 private:
  UserManager& userManager_;
  GroupManager& groupManager_;

  const std::unordered_map<std::string, std::string> usages = {
      {"createUser", "createUser {userId} {username} [email] [age]"},
      {"deleteUser", "deleteUser {userId}"},
      {"allUsers", "allUsers"},
      {"getUser", "getUser {userId}"},
      {"createGroup", "createGroup {groupId}"},
      {"deleteGroup", "deleteGroup {groupId}"},
      {"allGroups", "allGroups"},
      {"getGroup", "getGroup {groupId}"},
      {"addUserToGroup", "addUserToGroup {userId} {groupId}"}};

  const std::unordered_map<std::string,
                           std::function<void(const std::vector<std::string>&)>>
      commands = {{"createUser",
                   [this](const auto& args) {
                     if (args.size() < 3 || args.size() > 5) {
                       printUsage("createUser");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       std::string username = args[2];
                       std::string email = args.size() > 3 ? args[3] : "";
                       int age = args.size() > 4 ? std::stoi(args[4]) : 0;
                       userManager_.createUser(id, username, email, age);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("createUser");
                     }
                   }},
                  {"deleteUser",
                   [this](const auto& args) {
                     if (args.size() != 2) {
                       printUsage("deleteUser");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       userManager_.deleteUser(id);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("deleteUser");
                     }
                   }},
                  {"allUsers",
                   [this](const auto& args) {
                     if (args.size() != 1) {
                       printUsage("allUsers");
                       return;
                     }
                     userManager_.printAllUsers();
                   }},
                  {"getUser",
                   [this](const auto& args) {
                     if (args.size() != 2) {
                       printUsage("getUser");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       userManager_.printUser(id);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("getUser");
                     }
                   }},
                  {"createGroup",
                   [this](const auto& args) {
                     if (args.size() != 2) {
                       printUsage("createGroup");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       groupManager_.createGroup(id);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("createGroup");
                     }
                   }},
                  {"deleteGroup",
                   [this](const auto& args) {
                     if (args.size() != 2) {
                       printUsage("deleteGroup");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       groupManager_.deleteGroup(id);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("deleteGroup");
                     }
                   }},
                  {"allGroups",
                   [this](const auto& args) {
                     if (args.size() != 1) {
                       printUsage("allGroups");
                       return;
                     }
                     groupManager_.printAllGroups();
                   }},
                  {"getGroup",
                   [this](const auto& args) {
                     if (args.size() != 2) {
                       printUsage("getGroup");
                       return;
                     }
                     try {
                       int id = std::stoi(args[1]);
                       groupManager_.printGroup(id);
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("getGroup");
                     }
                   }},
                  {"addUserToGroup", [this](const auto& args) {
                     if (args.size() != 3) {
                       printUsage("addUserToGroup");
                       return;
                     }
                     try {
                       int userId = std::stoi(args[1]);
                       int groupId = std::stoi(args[2]);
                       auto user = userManager_.getUser(userId);
                       if (user) {
                         groupManager_.addUserToGroup(user, groupId);
                       } else {
                         std::cerr << "User with ID " << userId
                                   << " not found.\n";
                       }
                     } catch (const std::exception& e) {
                       std::cerr << "Error: " << e.what() << "\n";
                       printUsage("addUserToGroup");
                     }
                   }}};
};
