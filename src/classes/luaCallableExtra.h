#ifndef LUACALLABLEEXTRA_H
#define LUACALLABLEEXTRA_H
#include "core/object/ref_counted.h"
#include "core/core_bind.h"

#include <lua/lua.hpp>

class LuaCallableExtra : public RefCounted {
    GDCLASS(LuaCallableExtra, RefCounted);

    protected:
        static void _bind_methods();

    public:
        static LuaCallableExtra* withTuple(Callable function, int argc);
        static LuaCallableExtra* withRef(Callable function);

        void setInfo(Callable function, int argc, bool isTuple, bool wantsRef);

        static int call(lua_State *state);

    private:
        bool isTuple = false;
        bool wantsRef = false;
        int argc = 0;

        Callable function;
};
#endif