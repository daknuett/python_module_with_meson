project('test_project', version:'0.0.0')

pymod = import('python')
python = pymod.find_installation('python3')

python.install_sources(
  'src/test.py',
  pure:true,
  subdir:'test_module'
)

