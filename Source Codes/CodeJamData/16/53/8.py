import os, inspect
import heapq

problemName  = 'C'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 2

def distanceBetween(a1, a2, t):
  return ((a1[0] + a1[3] * t - a2[0] - a2[3] * t) ** 2 + (a1[1] + a1[4] * t - a2[1] - a2[4] * t) ** 2 + (a1[2] + a1[5] * t - a2[2] - a2[5] * t) ** 2)**0.5

def buildUpTransitions(N, S, asteroids):
  # transitions = {}
  # # (time, index)

  # maxIndex = 10000
  # transitions['start'] = {}
  # t = 0
  # index = -1
  # while index < maxIndex - 1:
  #   index += 1
  #   t      = (0.0001 * index) * S
  #   transitions['start'][(index, 0)] = 0
  #   for i in xrange(N):
  #     transitions[(index, i)] = {}
  #     for j in xrange(N):
  #       if i != j:
  #         transitions[(index, i)][(index, j)] = distanceBetween(asteroids[i], asteroids[j], t)
  #     transitions[(index, i)][(index + 1, i)] = 0
  # transitions[(maxIndex, 1)] = { 'finish' : 0 }

  # return transitions

  transitions = {}

  transitions['start'] = { 0 : 0 }
  for i in xrange(N):
    transitions[i] = {}
    for j in xrange(N):
      if i != j:
        transitions[i][j] = distanceBetween(asteroids[i], asteroids[j], 0)
  transitions[1] = { 'finish' : 0 }

  return transitions

def solution(N, S, asteroids):
  transitions = buildUpTransitions(N, S, asteroids)
  # start -> finish

  queue = [(0, 'start')]
  seen = set()
  while len(queue) > 0:
    (cost, vertex) = heapq.heappop(queue)
    if vertex not in seen:
      seen.add(vertex)
      if vertex == 'finish':
        return cost
      if vertex in transitions:
        for newVertex, distance in transitions[vertex].iteritems():
          if newVertex not in seen:
            heapq.heappush(queue, (max(cost, distance), newVertex))
  return float('inf')

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
if testCase in ['large', 'example']:
  inputString  = problemName + ('-%s' % testCase)
  outputString = problemName + ('-%s' % testCase)
else:
  inputString  = problemName + ('-%s-attempt%d' % (testCase, attempt))
  outputString = problemName + ('-%s' % testCase)

inFile       = os.path.join(currentDir, 'inputfiles', '%s.in' % inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.out' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    N, S = map(int, inputfile.readline().split(' '))
    asteroids = []
    for _ in xrange(N):
      asteroids.append(map(int, inputfile.readline().split(' ')))

    # Get the result here
    result = solution(N, S, asteroids)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %f\n' % (case, result))
