//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
#ifndef UMPIRE_MemoryResourceRegistry_HPP
#define UMPIRE_MemoryResourceRegistry_HPP

#include "umpire/resource/MemoryResource.hpp"
#include "umpire/resource/MemoryResourceFactory.hpp"

#include <memory>
#include <vector>

namespace umpire {
namespace resource {

class MemoryResourceRegistry {
  public:
    static MemoryResourceRegistry& getInstance() noexcept;

    std::unique_ptr<resource::MemoryResource>
    makeMemoryResource(const std::string& name, int id);

    std::unique_ptr<resource::MemoryResource>
    makeMemoryResource(const std::string& name, int id, MemoryResourceTraits traits);

    void registerMemoryResource(std::unique_ptr<MemoryResourceFactory>&& factory);

    MemoryResourceRegistry(const MemoryResourceRegistry&) = delete;
    MemoryResourceRegistry& operator=(const MemoryResourceRegistry&) = delete;
    ~MemoryResourceRegistry() = default;

  private:
    MemoryResourceRegistry() noexcept;

    std::vector<std::unique_ptr<MemoryResourceFactory> > m_allocator_factories;
};

} // end of namespace resource
} // end of namespace umpire

#endif // UMPIRE_MemoryResourceRegistry_HPP
