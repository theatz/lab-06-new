#include <Scheduler.hpp>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int sig;
void Interupt(int i) {
  std::cout << i << std::endl;
  sig = i;
}
1

int main(int argc, char** argv) {
  signal(SIGTERM, Interupt);
  signal(SIGINT, Interupt);
  if (argc == 1)
    Scheduler work(sig);
  else if (argc == 2)
    Scheduler work(sig, boost::lexical_cast<unsigned>(argv[1]));
  else if (argc == 3)
    Scheduler work(sig, boost::lexical_cast<unsigned>(argv[1]), argv[2]);

  return 0;
}