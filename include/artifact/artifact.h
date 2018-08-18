#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "artifact_export.h"

struct artifact_ctx;

#ifdef __cplusplus
extern "C" {
#endif

ARTIFACT_EXPORT int artifact_get_version_major(void);
ARTIFACT_EXPORT int artifact_get_version_minor(void);
ARTIFACT_EXPORT int artifact_get_version_patch(void);
ARTIFACT_EXPORT int artifact_get_version_tweak(void);
ARTIFACT_EXPORT const char *artifact_get_version_string(void);

int ARTIFACT_EXPORT artifact_new(struct artifact_ctx **ctx);
unsigned long ARTIFACT_EXPORT artifact_unref(struct artifact_ctx *ctx);

#ifdef __cplusplus
}
#endif

#endif
