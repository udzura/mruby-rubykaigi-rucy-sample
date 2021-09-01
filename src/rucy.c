/*
** mrb_rubykaigirucysample.c - RubykaigiRucySample class
**
** Copyright (c) Uchio Kondo 2021
**
** See Copyright Notice in LICENSE
*/

#include <mruby.h>
#include <mruby/data.h>
#include <mruby/error.h>

#include "rucy_bpf.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

static void mrb_rucy_free(mrb_state *mrb, void *p)
{
  struct rucy *obj = (struct rucy *)p;
  rucy__destroy(obj);
}

static const struct mrb_data_type mrb_rucy_data_type = {
  "rucy", mrb_rucy_free,
};

static mrb_value mrb_rucy_init(mrb_state *mrb, mrb_value self)
{
  struct rucy *data;
  char *str;
  mrb_int len;

  DATA_TYPE(self) = &mrb_rucy_data_type;
  DATA_PTR(self) = NULL;

  data = rucy__open_and_load();
  if (!data)
    mrb_sys_fail(mrb, "rucy__open_and_load");

  DATA_PTR(self) = (void *)data;

  return self;
}

static mrb_value mrb_rucy_attach(mrb_state *mrb, mrb_value self)
{
  struct rucy *data = DATA_PTR(self);
  return mrb_fixnum_value(rucy__attach(data));
}

void mrb_mruby_rubykaigi_rucy_sample_gem_init(mrb_state *mrb)
{
  struct RClass *klass;
  klass = mrb_define_class(mrb, "BPF", mrb->object_class);
  mrb_define_method(mrb, klass, "initialize", mrb_rucy_init, MRB_ARGS_NONE());
  mrb_define_method(mrb, klass, "attach", mrb_rucy_attach, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_rubykaigi_rucy_sample_gem_final(mrb_state *mrb)
{
}
