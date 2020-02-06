file(REMOVE_RECURSE
  "include11_automoc.cpp"
  "ekf_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/state_estimator_gennodejs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
