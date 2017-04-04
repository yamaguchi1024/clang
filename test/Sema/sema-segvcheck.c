// RUN: %clang_cc1 -fsyntax-only -verify %s
// RUN: %clang_cc1 -fsyntax-only %s; test $? -eq 1

typedef struct {
  union {
    unsigned long long house;
    struct {
      unsigned cat1;
      unsigned cat2;
    };
  };
} struct_0;


typedef struct {
  union {
    struct {
      union {
        unsigned cows;
        struct {
          unsigned char c:1;
        };
      };
    };
  };

  union {
    struct {
      unsigned bird0;
      unsigned bird1;
    };
  };
} struct_1;


typedef struct {
  struct_0 s0;
  struct_1 s1[1];
} struct_2;

struct_2 s = {
  .s0 = {
    .dog = 0x00000000, // expected-error{{field designator}}
  },

  .s1[0] = {
    .cows = 0x00005050,
    .c = 1,
  },
};
