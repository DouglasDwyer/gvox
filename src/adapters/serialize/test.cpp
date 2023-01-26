#include <gvox/adapter.h>
#include <gvox/adapters/serialize/test.h>

extern "C" void gvox_serialize_adapter_test_begin([[maybe_unused]] GVoxAdapterContext *ctx, [[maybe_unused]] void *config) {
}

extern "C" void gvox_serialize_adapter_test_end([[maybe_unused]] GVoxAdapterContext *ctx) {
}

extern "C" void gvox_serialize_adapter_test_serialize_region(GVoxAdapterContext *ctx, GVoxRegionRange const *range) {
    auto flags = gvox_query_region_flags(ctx, range);
    if ((flags & GVOX_REGION_FLAG_UNIFORM) == 0u) {
        gvox_serialize_adapter_push_error(ctx, GVOX_ERROR_UNKNOWN, "test format must be provided with a uniform range ");
    }
    auto data = gvox_sample_data(ctx, &range->offset);
    gvox_output_write(ctx, 0, sizeof(data), &data);
}