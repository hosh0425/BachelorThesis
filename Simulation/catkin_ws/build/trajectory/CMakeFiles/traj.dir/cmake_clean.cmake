file(REMOVE_RECURSE
  "includesss1_automoc.cpp"
  "traj_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/traj.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
