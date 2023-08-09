#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<std::string> parse(const std::string &line);
bool check_username_exists(const std::string &username);

#endif // UTILS_H