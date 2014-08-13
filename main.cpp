#include <iostream>
#include <thread>
#include "udp_server.h"
#include "controlpackage.cpp"

using namespace std;
controlpackage ctrlpkg;

void listen_udp(udp_server serveri){
  cout << "starting UDP-listener thread" << endl;
  serveri.start_server();
}

int main(int argc, char **argv) {
    std::cout << "RPIQuadcopter version 1.0" << std::endl;

    udp_server servu(23456, &ctrlpkg);
    thread udp_listener_thread(listen_udp,servu);

    // just a test
    for(;;){
      std::this_thread::sleep_for(std::chrono::seconds(3));
      cout << "slept three sec" << endl;
    }


}
