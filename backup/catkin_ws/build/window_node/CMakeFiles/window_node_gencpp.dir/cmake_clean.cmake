file(REMOVE_RECURSE
  "include_window_node_automoc.cpp"
  "window_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/window_node_gencpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
