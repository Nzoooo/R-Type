/*
** EPITECH PROJECT, 2022
** Message
** File description:
** Message
*/

#pragma once
#include <cstdint>
#include <vector>
#include <iostream>
#include <cstring>

namespace network
{
    enum CustomMessage {
        PingServer
    };
    template <class T>
    struct Header {
        T id;
        uint32_t size = 0;
    };
    template <class T>
    struct Message {
        Header<T> header{};
        std::vector<uint8_t> body;
        /**
         * @brief 
         * 
         * @return std::size_t 
         */
        std::size_t size() const
        {
            return (sizeof(Header<T>) + body.size());
        }
        /**
         * @brief 
         * 
         * @param os 
         * @param msg 
         * @return std::ostream& 
         */
        friend std::ostream &operator << (std::ostream &os, const Message<T> &msg)
        {
            os << "message type: " << static_cast<int>(msg.header.id) << " size: " << msg.header.size << std::endl;
            return (os);
        }
        /**
         * @brief 
         * 
         * @tparam U 
         * @param msg 
         * @param data 
         * @return Message<T>& 
         */
        template <class U>
        friend Message<T> &operator << (Message<T> &msg, const U &data)
        {
            static_assert(std::is_standard_layout<U>::value, "Data is too complex to be pushed into vector");
            std::size_t i = msg.body.size();
            msg.body.resize(msg.body.size() + sizeof(U));
            std::memcpy(msg.body.data() + i, &data, sizeof(U));
            msg.header.size = msg.size();
            return (msg);
        }
        /**
         * @brief 
         * 
         * @tparam U 
         * @param msg 
         * @param data 
         * @return Message<T>& 
         */
        template <class U>
        friend Message<T> &operator >> (Message<T> &msg, U &data)
        {
            static_assert(std::is_standard_layout<U>::value, "Data is too complex to be pulled from vector");
            std::size_t i = msg.body.size() - sizeof(U);
            std::memcpy(&data, msg.body.data() + i, sizeof(U));
            msg.body.resize(i);
            msg.header.size = msg.size();
            return (msg);
        }
    };
}
