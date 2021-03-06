//"Copyright [year] <Copyright Owner>"
//
// Created by mrbgn on 3/3/21.
//

#ifndef INCLUDE_LOGGER_HPP_
#define INCLUDE_LOGGER_HPP_

#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <thread>

struct ToFile {
  std::string data;
  std::string hash;
  std::string time;
};


class Logger {
 public:
  Logger();
  explicit Logger(std::string& fileName);
  void operator << (ToFile data);
  static bool Matching(std::string hash);
  void Init();
  ~Logger();
 private:
  nlohmann::json _result;
  std::string _fileName;
};

#endif  // INCLUDE_LOGGER_HPP_
