#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "artifact_export.h"

struct artifact_ctx;

#ifdef __cplusplus
extern "C" {
#endif

int ARTIFACT_EXPORT artifact_new(struct artifact_ctx **ctx);
unsigned long ARTIFACT_EXPORT artifact_unref(struct artifact_ctx *ctx);

#ifdef __cplusplus
}
#endif

#endif
