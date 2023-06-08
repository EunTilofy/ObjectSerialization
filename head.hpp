#ifndef _IO_HPP_
#define _IO_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>

/***************************************************
*  format of output of STL types
****************************************************/

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& out, const std::pair<T1, T2> &o);
template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T> &o);
template<typename T>
std::ostream& operator << (std::ostream& out, const std::set<T> &o);
template<typename T>
std::ostream& operator << (std::ostream& out, const std::list<T> &o);
template<typename T1, typename T2>
std::ostream& operator << (std::ostream& out, const std::map<T1, T2> &o);


template<typename T1, typename T2>
std::ostream& operator << (std::ostream& out, const std::pair<T1, T2> &o) {
  out << "{ " << o.first << ", " << o.second << " }";
  return out;
}
template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T> &o) {
  out << "{ ";
  bool Flag = 0;
  for(auto & item : o) {
    if(Flag) out << ", ";
    else Flag = 1;
    out << item;
  }
  out << " }";
  return out;
}
template<typename T>
std::ostream& operator << (std::ostream& out, const std::set<T> &o) {
  out << "{ ";
  bool Flag = 0;
  for(auto & item : o) {
    if(Flag) out << ", ";
    else Flag = 1;
    out << item;
  }
  out << " }";
  return out;
}
template<typename T>
std::ostream& operator << (std::ostream& out, const std::list<T> &o) {
  out << "{ ";
  bool Flag = 0;
  for(auto & item : o) {
    if(Flag) out << ", ";
    else Flag = 1;
    out << item;
  }
  out << " }";
  return out;
}
template<typename T1, typename T2>
std::ostream& operator << (std::ostream& out, const std::map<T1, T2> &o) {
  out << "{ ";
  bool Flag = 0;
  for(auto & [key, value] : o) {
    if(Flag) out << ", ";
    else Flag = 1;
    out << "{ " << key << ": " << value << " }";
  }
  out << " }";
  return out;
}

// register function for members
// const function
template <typename Func, typename... Members>
void register_const_func(const Func& func, const Members&... members) {
    (func(members), ...);
}
// normal function
template <typename Func, typename... Members>
void register_normal_func(const Func& func, Members&... members) {
    (func(members), ...);
}

#endif