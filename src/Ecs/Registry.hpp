/*
** EPITECH PROJECT, 2022
** registry.hpp
** File description:
** registry.hpp
*/

#pragma once

#include <chrono>
#include <any>
#include <functional>
#include <iostream>
#include <optional>
#include <typeindex>
#include <vector>
#include <unordered_map>
#include "Component/SparseArray.hpp"
#include "Component/component.hpp"
#include "Entities/Entity.hpp"
#include "Enum.hpp"
#include "Exceptions/ExceptionEntityUnobtainable.hpp"
#include "Exceptions/ExceptionIndexComponent.hpp"
#include "Exceptions/ExceptionSparseArrayUnobtainable.hpp"
#include "../Network/Message.hpp"

//convert to milliseconds with std::chrono::milliseconds() operator
#define TRANSFER_TIME_COMPONENT 8

namespace ecs
{
    class Registry {
      public:
        Registry()
        {
            registerComponents<ecs::Ammo>();
            registerComponents<ecs::Clickable>();
            registerComponents<ecs::Collider>();
            registerComponents<ecs::Controllable>();
            registerComponents<ecs::Drawable>();
            registerComponents<ecs::Type>();
            registerComponents<ecs::Hover>();
            registerComponents<ecs::Killable>();
            registerComponents<ecs::Layer>();
            registerComponents<ecs::Link>();
            registerComponents<ecs::Position>();
            registerComponents<ecs::Shootable>();
            registerComponents<ecs::Shooter>();
            registerComponents<ecs::Rectangle>();
            registerComponents<ecs::Text>();
            registerComponents<ecs::TextBox>();
            registerComponents<ecs::CompoScene>();
            registerComponents<ecs::Animation>();
            registerComponents<ecs::Pressed>();
            registerComponents<ecs::CompoServer>();
            registerComponents<ecs::Planet>();
            registerComponents<ecs::WindowSized>();
            registerComponents<ecs::Achievement>();
        };
        ~Registry() = default;
        /**
         * @brief
         *
         * @tparam Component
         * @return SparseArray<Component>&
         */
        template <class Component> SparseArray<Component> &registerComponents()
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
            } catch (const std::out_of_range &e) {
                _components_arrays.emplace(std::type_index(typeid(Component)), SparseArray<Component>());
            }
            _components_eraser.push_back([&](Entity &entity) {
                try {
                    std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).erase(entity);
                } catch (const ExceptionComponentNull &e) {
                    throw ExceptionComponentNull("Component doesn't exist", "_components_eraser -> [&](Entity &entity)");
                } catch (const ExceptionIndexComponent &e) {
                    throw ExceptionIndexComponent("Cannot erase this component, bad index", "_components_eraser -> [&](Entity &entity)");
                }
            });
            _components_find.push_back([&](Registry &registry, Entity &entity) {
                try {
                    registry.getComponents<Component>().at(entity);
                    return (true);
                } catch (const ExceptionComponentNull &e) {
                    return (false);
                } catch (const ExceptionIndexComponent &e) {
                    return (false);
                }
            });
            _components_compare.push_back([&](Registry &registry, Entity &entity) {
                try {
                    if (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(entity).value()
                    == registry.getComponents<Component>().at(entity).value()) {
                        return (true);
                    } else
                        return (false);
                } catch (const ExceptionComponentNull &e) {
                    throw ExceptionComponentNull("Component doesn't exist", "_components_compare -> [&](Registry &registry, Entity &entity)");
                } catch (const ExceptionIndexComponent &e) {
                    throw ExceptionIndexComponent("Bad index", "_components_compare -> [&](Registry &registry, Entity &entity)");
                }
            });
            _net_message_create.push_back([&](std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create) {
                try {
                    network::Message<network::CustomMessage> message;
                    message.header.id = header_id;
                    std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(entity);
                    message << std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(entity).value() << entity << entity << index_component_create;
                    return (message);
                } catch (const ExceptionComponentNull &e) {
                    throw ExceptionComponentNull("Component doesn't exist", "_net_message_create -> [&](std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create)");
                } catch (const ExceptionIndexComponent &e) {
                    throw ExceptionIndexComponent("Bad index", "_net_message_create -> [&](std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create)");
                }
            });
            _net_component_create.push_back([&](network::Message<network::CustomMessage> message) {
                std::size_t entity;
                try {
                    _components_arrays.at(std::type_index(typeid(Component)));
                    Component compo;
                    message >> entity;
                    addEntity(entity);
                    message >> compo;
                    std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).insert_at(entity, compo);
                } catch (const std::out_of_range &e) {
                    throw ExceptionSparseArrayUnobtainable("Cannot find the SparseArray of this component type",
                        "_net_component_create -> [&](network::Message<network::CustomMessage> message)");
                } catch (const std::length_error &e) {
                    try {
                        killEntity(getEntityById(entity));
                    } catch (const ExceptionEntityUnobtainable &err) {
                        return;
                    }
                }
            });
            return (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))));
        }
        /**
         * @brief Get the Components object
         *
         * @tparam Component
         * @return SparseArray<Component>&
         */
        template <class Component> SparseArray<Component> &getComponents()
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable(
                    "Cannot find the SparseArray of this component type", "template <class Component> SparseArray<Component> &getComponents()");
            }
            return (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))));
        }
        /**
         * @brief Get the Components object
         *
         * @tparam Component
         * @return SparseArray<Component> const
         */
        template <class Component> SparseArray<Component> const getComponents() const
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable(
                    "Cannot find the SparseArray of this component type", "template <class Component> SparseArray<Component> const getComponents() const");
            }
            return (const_cast<SparseArray<Component>>(std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component))))));
        }
        /**
         * @brief
         *
         * @tparam Component
         * @param to
         * @param c
         * @return SparseArray<Component>::reference_type
         */
        template <typename Component> typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c)
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
                std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).insert_at(to, std::forward<Component>(c));
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable("Cannot find the SparseArray of this component type",
                    "template <typename Component> typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c)");
            }
            return (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(to));
        }
        /**
         * @brief
         *
         * @tparam Component
         * @param to
         * @param c
         * @return SparseArray<Component>::reference_type
         */
        template <typename Component> typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &c)
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
                std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).insert_at(to, c);
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable("Cannot find the SparseArray of this component type",
                    "template <typename Component> typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &c)");
            }
            return (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(to));
        }
        /**
         * @brief
         *
         * @tparam Component
         * @tparam Params
         * @param to
         * @param args
         * @return SparseArray<Component>::reference_type
         */
        template <typename Component, typename... Params> typename SparseArray<Component>::reference_type emplaceComponent(Entity const &to, Params &&...args)
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
                std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).emplace_at(to, args...);
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable("Cannot find the SparseArray of this component type",
                    "template <typename Component, typename ... Params> typename SparseArray<Component>::reference_type emplaceComponent(Entity const &to, "
                    "Params &&... args)");
            }
            return (std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).at(to));
        }
        /**
         * @brief
         *
         * @tparam Component
         * @param from
         */
        template <typename Component> void removeComponent(Entity const &from)
        {
            try {
                _components_arrays.at(std::type_index(typeid(Component)));
                std::any_cast<SparseArray<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))).erase(from);
            } catch (const std::out_of_range &e) {
                throw ExceptionSparseArrayUnobtainable(
                    "Cannot find the SparseArray of this component type", "template <typename Component> void removeComponent(Entity const &from)");
            }
        }
        /**
         * @brief
         *
         * @param label
         * @return Entity&
         */
        Entity &spawnEntity()
        {
            try {
                _entities.at(_actual_scene);
            } catch (const std::out_of_range &e) {
                _entities.emplace(_actual_scene, std::vector<Entity>());
            }
            std::optional<std::size_t> id = std::nullopt;
            for (int i = _dead_entities.size() - 1; i >= 0; i--) {
                id = _dead_entities.at(i);
                _dead_entities.pop_back();
                break;
            }
            Entity entity(id);
            _entities.at(_actual_scene).push_back(entity);
            return (_entities.at(_actual_scene).back());
        };
        /**
         * @brief
         *
         * @param entity
         */
        void killEntity(Entity &entity)
        {
            _dead_entities.push_back(entity.getId());
            for (auto &it : _components_eraser) {
                try {
                    it(entity);
                } catch (const ExceptionComponentNull &e) {
                    continue;
                } catch (const ExceptionIndexComponent &e) {
                    continue;
                }
            }
            for (std::size_t i = 0; i < _entities.at(_actual_scene).size(); i++) {
                if (_entities.at(_actual_scene).at(i).getId() == entity.getId()) {
                    _entities.at(_actual_scene).erase(std::next(_entities.at(_actual_scene).begin(), i));
                    break;
                }
            }
        };
        /**
         * @brief Get the Entity By Id object
         *
         * @param id
         * @return Entity&
         */
        Entity &getEntityById(std::size_t id)
        {
            for (std::size_t i = 0; i < _entities.at(_actual_scene).size(); i++) {
                if (_entities.at(_actual_scene).at(i).getId() == id)
                    return (_entities.at(_actual_scene).at(i));
            }
            throw ExceptionEntityUnobtainable("Cannot find an entity with this id", "Entity &getEntityById(std::size_t id)");
        };
        /**
         * @brief Get the Entities Id By Ecs Type
         *
         * @param type
         * @return std::vector<std::size_t>
         */
        std::vector<std::size_t> getEntitiesIdByEcsType(ecs::EntityTypes type)
        {
            std::vector<std::size_t> tmp_vector;
            for (auto &it : _entities.at(_actual_scene)) {
                try {
                    if (getComponents<ecs::Type>().at(it).value().getEntityType() == type)
                        tmp_vector.push_back(it.getId());
                } catch (const ecs::ExceptionComponentNull &e) {
                    continue;
                } catch (const ecs::ExceptionIndexComponent &e) {
                    continue;
                }
            }
            return (tmp_vector);
        };
        /**
         * @brief Get the Entities object
         *
         * @return std::vector<Entity>
         */
        std::vector<Entity> getEntities() const
        {
            try {
                if (_entities.at(_actual_scene).size() == 0) {
                    throw Exception("_entities vector is empty", "std::vector<Entity> getEntities() const");
                }
            } catch (const std::out_of_range &e) {
                throw Exception("_entities vector doesn't exist", "std::vector<Entity> getEntities() const");
            }
            return (_entities.at(_actual_scene));
        };
        /**
         * @brief
         *
         * @param id
         * @return Entity&
         */
        Entity &addEntity(std::size_t id)
        {
            try {
                _entities.at(_actual_scene);
            } catch (const std::out_of_range &e) {
                _entities.emplace(_actual_scene, std::vector<Entity>());
            }
            for (auto &it : _entities.at(_actual_scene)) {
                if (id == it.getId())
                    return (it);
            }
            Entity entity(id);
            _entities.at(_actual_scene).push_back(entity);
            return (_entities.at(_actual_scene).back());
        }
        /**
         * @brief Set the Actual Scene object
         *
         * @param scene
         */
        void setActualScene(ecs::Scenes scene)
        {
            _actual_scene = scene;
        };
        /**
         * @brief Get the Actual Scene object
         *
         * @return ecs::Scenes
         */
        ecs::Scenes getActualScene() const
        {
            return (_actual_scene);
        };
        /**
         * @brief Get the Net Message Create object
         *
         * @return std::vector<std::function<network::Message<network::CustomMessage>(std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create)>> 
         */
        std::vector<std::function<network::Message<network::CustomMessage>(std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create)>> getNetMessageCreate() const
        {
            return (_net_message_create);
        }
        /**
         * @brief Get the Net Component Create object
         *
         * @return std::vector<std::function<void(network::Message<network::CustomMessage> message)>> 
         */
        std::vector<std::function<void(network::Message<network::CustomMessage> message)>> getNetComponentCreate() const
        {
            return (_net_component_create);
        }

        std::vector<std::function<bool(Registry &, Entity &)>> getComponentsFind() const
        {
            return (_components_find);
        };

        std::vector<std::function<bool(Registry &, Entity &)>> getComponentsCompare() const
        {
            return (_components_compare);
        };


      private:
        std::unordered_map<std::type_index, std::any> _components_arrays;
        std::vector<std::function<void(Entity &)>> _components_eraser;
        std::vector<std::function<bool(Registry &, Entity &)>> _components_find;
        std::vector<std::function<bool(Registry &, Entity &)>> _components_compare;
        std::unordered_map<ecs::Scenes, std::vector<Entity>> _entities;
        std::vector<std::size_t> _dead_entities;
        ecs::Scenes _actual_scene = ecs::Scenes::MENU;

        std::vector<std::function<network::Message<network::CustomMessage>(std::size_t entity, network::CustomMessage header_id, std::size_t index_component_create)>> _net_message_create;
        std::vector<std::function<void(network::Message<network::CustomMessage> message)>> _net_component_create;
    };
} // namespace ecs
