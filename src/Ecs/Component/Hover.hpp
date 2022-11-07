/*
** EPITECH PROJECT, 2022
** Hover.hpp
** File description:
** Hover.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace ecs
{
    class Hover : public AComponent {
      public:
        /**
         * @brief Construct a new Hover object
         *
         */
        Hover() = default;
        /**
         * @brief Construct a new Hover object
         *
         * @param other
         */
        Hover(const Hover &other) = default;
        /**
         * @brief Destroy the Hover object
         *
         */
        ~Hover() = default;
        /**
         * @brief
         *
         * @param other
         * @return Hover&
         */
        Hover &operator=(const Hover &other) = default;
    };
} // namespace ecs
