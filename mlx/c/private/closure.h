#ifndef MLX_CLOSURE_PRIVATE_H
#define MLX_CLOSURE_PRIVATE_H

#include "mlx/c/closure.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

// std::function<std::vector<array>(std::vector<array>)>

struct mlx_closure_ : mlx_object_ {
  mlx_closure_(
      std::function<std::vector<mlx::core::array>(
          const std::vector<mlx::core::array>&)> ctx,
      void* payload = nullptr,
      void (*dtor)(void*) = nullptr)
      : mlx_object_(), ctx(ctx), payload(payload), dtor(dtor){};
  virtual char* tostring() override;
  std::function<std::vector<mlx::core::array>(
      const std::vector<mlx::core::array>&)>
      ctx;
  void* payload;
  void (*dtor)(void*);
  virtual ~mlx_closure_() {
    if (payload && dtor) {
      dtor(payload);
    }
  };
};

#endif