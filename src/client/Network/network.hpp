/*
** EPITECH PROJECT, 2022
** net
** File description:
** net
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include "shared.hpp"

#define IPADDRESS     "127.0.0.1"
#define SRVR_UDP_PORT 10251

using boost::asio::ip::address;
using boost::asio::ip::udp;

class network_player {
  public:
    network_player();
    ~network_player();
    void init_player(void);
    void process_player(shared_memory_t *shr);

  private:
    int _port;
    int _sock;
    int _id;
    fd_set read_fd_copy;
    fd_set read_fd_registered;
    struct sockaddr_in addr;
    bool _start;
    shared_memory_t *_s;
};
