#include "artifact_private.h"

#include <stdlib.h>

const int VERSION_MAJOR = 0;
const int VERSION_MINOR = 2;
const int VERSION_PATCH = 0;
const int VERSION_TWEAK = 0;
const char *VERSION_STRING = "0.2.0";

int artifact_get_version_major(void) { return VERSION_MAJOR; }

int artifact_get_version_minor(void) { return VERSION_MINOR; }

int artifact_get_version_patch(void) { return VERSION_PATCH; }

int artifact_get_version_tweak(void) { return VERSION_TWEAK; }

const char *artifact_get_version_string(void) { return VERSION_STRING; }

int artifact_new(struct artifact_ctx **ctx)
{
    struct artifact_ctx *c = calloc(1, sizeof(struct artifact_ctx));
    if (!c)
        return -1;

    c->ref_count++;
    *ctx = c;

    return 0;
}

unsigned long ARTIFACT_EXPORT artifact_unref(struct artifact_ctx *ctx)
{
    unsigned long ref_count = 0;

    if (ctx) {
        if (ctx->ref_count > 0) {
            ctx->ref_count--;
        }

        if (ctx->ref_count == 0) {
            free(ctx);
        }
    }

    return ref_count;
}
