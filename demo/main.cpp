#include <Scheduler.hpp>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int sig;
void Interupt(int i) {
  std::cout << i << std::endl;
  sig = i;
}

int main() {
  sig = 0;
  std::string filename = "check";
  signal(SIGTERM, Interupt);
  signal(SIGINT, Interupt);
  Scheduler w(sig, 8, filename);
  return 0;
}