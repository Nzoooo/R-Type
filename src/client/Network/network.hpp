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
#include <memory>
#include <string>
#include <thread>
#include "shared.hpp"
#include <atomic>
#include <csignal>

using boost::asio::ip::udp;

#define IPADDRESS "127.0.0.1"
#define SRVR_UDP_PORT 10251

using boost::asio::ip::udp;

class network_player {
  public:
    network_player();
    ~network_player();
    void process_player(std::shared_ptr<void()> s);
    void sender_binary(udp::endpoint receiver_endpoint, udp::socket socket());
    void receiver_binary(udp::socket socket);
  private:
};
