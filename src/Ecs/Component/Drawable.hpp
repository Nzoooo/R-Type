/*
** EPITECH PROJECT, 2022
** Drawable.hpp
** File description:
** Drawable.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace ecs
{
    class Drawable : public AComponent {
      public:
        Drawable() = default;
        Drawable(const Drawable &other) = default;
        ~Drawable() = default;
        Drawable &operator=(const Drawable &other) = default;
    };
} // namespace ecs
