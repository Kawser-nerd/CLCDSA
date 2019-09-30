#! /usr/bin/python

fd = open("input.in")

num_cases = int(fd.readline())

for i in range(0, num_cases):
  (n, m, X, Y, Z) = [int(item) for item in fd.readline().split(" ")]

  A = [0] * n
  for j in range(0, m):
    A[j] = int(fd.readline())

  speeds = []

  for j in range(0, n):
    speeds.append(A[j % m])
    A[j % m] = (X * A[j % m] + Y * (j + 1)) % Z

  num_sets = [1] * len(speeds)

  for j in range(len(speeds)-1, -1, -1):
    for k in range(j+1,len(speeds)):
      if speeds[k] > speeds[j]:
        num_sets[j] += num_sets[k]
  
  tot_sets = 0
  for j in range(0, len(speeds)):
    tot_sets += num_sets[j]
  print "Case #%d:" % (i+1), tot_sets % 1000000007
