#include "artifact_private.h"

#include <stdlib.h>

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
