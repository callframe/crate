module;
#include <stdlib.h>

#include <cstdlib>

export module crate:allocator;
import :defines;

/*
 * Allocator interface
 */

export namespace crate {

struct Allocator {
  using Ref = Allocator*;

  /*
   * Virtual methods
   */

  virtual ~Allocator() = default;

  virtual u8* allocate(usize size, usize align) = 0;
  virtual void deallocate(u8* ptr) = 0;

  /*
   * Helpers for managing T's directly
   */

  template <typename T>
  T* create(usize n) {
    return reinterpret_cast<T*>(this->allocate(sizeof(T) * n, alignof(T)));
  }

  template <typename T>
  void drop(T* ptr) {
    this->deallocate(reinterpret_cast<u8*>(ptr));
  }
};

};  // namespace crate

/*
 * Implementation of C Allocator
 */

namespace crate {

struct C_Allocator : public Allocator {
  u8* allocate(usize size, usize align) override {
    return static_cast<u8*>(aligned_alloc(align, size));
  };

  void deallocate(u8* ptr) override { free(ptr); }
};

export Allocator::Ref c_allocator() {
  static C_Allocator ALLOCATOR{};
  return &ALLOCATOR;
}

};  // namespace crate
