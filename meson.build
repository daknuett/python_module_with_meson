project('test_project', 'c', version:'0.0.0')

pymod = import('python')
python = pymod.find_installation('python3')
pydep = python.dependency('python3')

python.install_sources(
  'src/test.py',
  pure:true,
  subdir:'mymath'
)

mymath = python.extension_module('mymath.mymath', 'src/mymath.c', dependencies:pydep, install:true, subdir:'mymath')
