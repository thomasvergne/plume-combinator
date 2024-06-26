add_rules("mode.debug", "mode.release")

target("ppm-ffi")
  set_kind("shared")
  add_includedirs("plume/include")
  add_includedirs("include")
  add_files("ffi.export.txt")
  add_rules("utils.symbols.export_list")
  add_files("src/**.c")
  set_targetdir("..")
  set_basename("combinator-ffi")
  set_prefixname("")
  set_extension(".plmc")
