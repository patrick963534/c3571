#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main()
{
    const char *file;
    lua_State *L;
    
    file = "config.lua";
    L = lua_open();
    luaL_openlibs(L);

    if (luaL_loadfile(L, file) || lua_pcall(L, 0, 0, 0))
    {
        printf("%s\n", lua_tostring(L, -1));
    }

    printf("top: %d\n", lua_gettop(L));

    lua_getglobal(L, "color");
    printf("%d\n", lua_istable(L, -1));
    printf("%d\n", lua_type(L, -1));

    printf("top: %d\n", lua_gettop(L));
    lua_pushstring(L, "r");
    printf("top: %d\n", lua_gettop(L));
    lua_gettable(L, -2);

    printf("top: %d\n", lua_gettop(L));
    printf("%d\n", lua_isnumber(L, -1));
    printf("top: %d\n", lua_gettop(L));
    printf("%d\n", (int)lua_tonumber(L, -1));
    printf("%d\n", (int)lua_tonumber(L, -1));

    lua_pop(L, 1);
    printf("top: %d\n", lua_gettop(L));

    return 0;
}
