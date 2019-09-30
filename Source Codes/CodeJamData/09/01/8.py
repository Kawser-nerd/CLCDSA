#!/usr/bin/env python

import sys, string
from subprocess import Popen, PIPE

input = sys.stdin.readlines()
specs = [int(num) for num in input[0].split()]
L = specs[0]
D = specs[1]
N = specs[2]

words = input[1:1+D]
table = string.maketrans('()', '[]')
case = 1
for exp in input[1+D:]:
  exp = '^' + exp.strip().translate(table) + '$'
  cmd = "grep '%s'" % exp
  p = Popen(cmd, shell=True, bufsize=4096, stdin=PIPE, stdout=PIPE, close_fds=True)
  (child_stdin, child_stdout) = (p.stdin, p.stdout)
  for word in words:
    print >> child_stdin, word 
  child_stdin.close()
  count = 0
  for line in child_stdout:
    count += 1
  print 'Case #%d: %d' % (case, count)
  child_stdout.close()
  case += 1
