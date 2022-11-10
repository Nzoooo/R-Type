/*
** EPITECH PROJECT, 2022
** Pressed
** File description:
** Pressed
*/

#pragma once
#include "AComponent.hpp"

namespace ecs
{
    class Pressed : public AComponent {
        public:
        /**
         * @brief Construct a new Pressed object
         * 
         */
            Pressed() = default;
            /**
             * @brief Construct a new Pressed object
             * 
             * @param other 
             */
            Pressed(const Pressed &other) = default;
            /**
             * @brief Destroy the Pressed object
             * 
             */
            ~Pressed() = default;
            /**
             * @brief 
             * 
             * @param other 
             * @return Pressed& 
             */
            Pressed &operator=(const Pressed &other) = default;

        protected:
        private:
    };
}
