add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")

set_languages("c++23")

add_requires("sfml", "imgui", "imgui-sfml")

target("app")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("backend/sources/*.cpp")
    add_files("frontend/sources/*.cpp")
    add_includedirs("backend/includes/")
    add_includedirs("frontend/includes/")
    add_packages("sfml", "imgui-sfml", "imgui")
    add_syslinks("GL")
    set_rundir("$(projectdir)")
