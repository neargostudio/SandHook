//
// Created by swift on 2019/5/23.
//

#pragma once

#include "hook.h"
#include <vector>

namespace SandHook {
    namespace Hook {
        class InlineHookArm64Android : public InlineHook {
        public:
            void *Hook(void *origin, void *replace) override;
            bool BreakPoint(void *point, void (*callback)(REG[])) override;

            void *SingleInstHook(void *origin, void *replace) override;

            void ExceptionHandler(int num, sigcontext *context) override;

        private:
            std::vector<HookInfo> hook_infos;
        };
    }
}
