//
// Created by mrbgn on 3/3/21.
//

#ifndef THREADING_SCHEDULER_HPP
#define THREADING_SCHEDULER_HPP
#include <algorithm>
#include <chrono>
#include <csignal>
#include <mutex>
#include <nlohmann/json.hpp>
#include <queue>
#include <string>
#include <thread>
#include <atomic>
#include <mutex>

#include "Logger.hpp"
#include "picosha2.h"




class Scheduler {
 public:
  Scheduler(std::atomic_int& sig, int count);
  Scheduler(std::atomic_int& sig);
  Scheduler(std::atomic_int& sig, int count, std::string file_name);

  void Stop();
  void Work();
  ~Scheduler() = default;

 private:
  std::vector<std::thread> _threads;
  volatile std::atomic_bool _work;
  Logger _logger;
  std::atomic_int& _sig;
};


#endif  // THREADING_SCHEDULER_HPP
