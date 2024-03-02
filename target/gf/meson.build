gf_ss = ss.source_set()
gf_ss.add(files(
  'cpu.c',
  'cpu_helper.c',
  'translate.c',
))

subdir('tcg')

target_arch += {'gf': gf_ss}
