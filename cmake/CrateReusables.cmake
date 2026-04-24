
# create an atom that has the same name as value
macro(crate_atom name)
  set(${name} "${name}")
endmacro(crate_atom name)
