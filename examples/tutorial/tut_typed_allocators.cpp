//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// Created by David Beckingsale, david@llnl.gov
// LLNL-CODE-747640
//
// All rights reserved.
//
// This file is part of Umpire.
//
// For details, see https://github.com/LLNL/Umpire
// Please also see the LICENSE file for MIT license.
//////////////////////////////////////////////////////////////////////////////
#include "umpire/ResourceManager.hpp"
#include "umpire/Allocator.hpp"

#include "umpire/TypedAllocator.hpp"

int main(int, char**) {
  auto& rm = umpire::ResourceManager::getInstance();
  auto alloc = rm.getAllocator("HOST");

  // Create a TypedAllocator for doubles
  umpire::TypedAllocator<double> double_alloc(alloc);

  double* my_doubles = double_alloc.allocate(1024);

  double_alloc.deallocate(my_doubles);


  std::vector< double, umpire::TypedAllocator<double> > 
    my_vector(double_allocator);

  my_vector.resize(100);

  return 0;
}
