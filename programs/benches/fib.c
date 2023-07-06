#include <dlfcn.h>
#include <stddef.h>
#include <stdint.h>


typedef struct fib_return_values
{
    uint64_t remaining_gas;
    struct {
        uint8_t discriminant;
        union {
            uint64_t ok[4];
            struct {
                void *ptr;
                uint32_t len;
                uint32_t cap;
            } err;
        };
    } result;
} fib_return_values_t;


static void run_bench(fib_return_values_t *, void *, uint64_t)
    __attribute__((weakref("_mlir_ciface_fib::fib::main")));


int main()
{
    fib_return_values_t return_values;

    run_bench(&return_values, NULL, 0);

    return 0;
}