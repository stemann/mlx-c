#ifndef MLX_STREAM_PRIVATE_H
#define MLX_STREAM_PRIVATE_H

#include "mlx/c/private/object.h"
#include "mlx/mlx.h"

struct mlx_stream_ : mlx_object_ {
  mlx_stream_(mlx::core::Stream ctx) : mlx_object_(), ctx(ctx){};
  virtual char* tostring() override;
  mlx::core::Stream ctx;
};

#endif