//
// Created by mrbgn on 3/3/21.
//


#include <Scheduler.hpp>

std::mutex lock;


ToFile finder() {
  std::string data = std::to_string(std::rand());
  std::string hash = picosha2::hash256_hex_string(data);
  return ToFile{data, hash, data};
}

Scheduler::Scheduler(std::atomic_int& sig)
    : _sig(sig), _work(true), _logger(){
  for (uint32_t i = 0; i < 5; i++)
    _threads.emplace_back(&Scheduler::Work, this);
  _threads.emplace_back(&Scheduler::Stop, this);
  for (auto& worker : _threads)
    if (worker.joinable()) worker.join();
}

Scheduler::Scheduler(std::atomic_int& sig, int count)
    : _sig(sig), _work(true), _logger() {
  for (uint32_t i = 0; i < count; i++)
    _threads.emplace_back(&Scheduler::Work, this);
  _threads.emplace_back(&Scheduler::Stop, this);
  for (auto& worker : _threads)
    if (worker.joinable()) worker.join();
}

Scheduler::Scheduler(std::atomic_int& sig, int count, std::string file_name)
    : _sig(sig), _work(true), _logger(file_name) {
  for (uint32_t i = 0; i < count; i++)
    _threads.emplace_back(&Scheduler::Work, this);
  _threads.emplace_back(&Scheduler::Stop, this);
  for (auto& worker : _threads)
    if (worker.joinable()) worker.join();
}

void Scheduler::Stop() {
  while (_work) {
    if (_sig == 2)
      _work = false;
  }
}




void Scheduler::Work() {
  while (_work) {
    auto info = finder();
    std::unique_lock<std::mutex> ulock(lock);
    _logger << info;
  }
}
