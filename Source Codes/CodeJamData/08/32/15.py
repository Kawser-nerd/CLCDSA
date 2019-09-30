#!/usr/bin/env python
#
# .py - 
#
# Copyright 2008 (C) Mansour Behabadi
#
# NOTE: this is the solution to code.jam contest problem:
#

ops = [int.__add__, int.__sub__]

ugly_count = 0

def is_ugly(num):
   return num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0

def count_ugly(left_slice_num, right_slice, op):
   global ugly_count
   if is_ugly(op(left_slice_num, int(right_slice))):
      ugly_count += 1
   if len(right_slice) > 1:
      for i in xrange(-1, -len(right_slice), -1):
         for sub_op in ops:
            count_ugly(op(left_slice_num, int(right_slice[:i])),
                       right_slice[i:], sub_op)

# main program
if __name__ == '__main__':
   testsCount = int(raw_input())
   # process each test
   for i in xrange(testsCount):
      ugly_count = 0
      count_ugly(0, raw_input(), int.__add__)
      print "Case #%d: %d" % (i + 1, ugly_count)
