def maximizeFreshChocolate(N, P, groups):
  remainingGroups = groups
  result          = 0
  while len(remainingGroups) > 0:
    optimalSets     = {}
    optimalCounts   = {}
    for index in xrange(len(remainingGroups)):
      tempOptimalSets   = {}
      tempOptimalCounts = {}
      for remainder in optimalCounts:
        possibleRemainder = (remainder + remainingGroups[index]) % P
        if optimalCounts[remainder] + 1 < tempOptimalCounts.get(possibleRemainder, 10**18):
          tempOptimalSets[possibleRemainder] = optimalSets[remainder] + [index]
          tempOptimalCounts[possibleRemainder] = optimalCounts[remainder] + 1
      tempOptimalSets[remainingGroups[index] % P] = [index]
      tempOptimalCounts[remainingGroups[index] % P] = 1
      for remainder in tempOptimalCounts:
        if tempOptimalCounts[remainder] < optimalCounts.get(remainder, 10**18):
          optimalSets[remainder] = tempOptimalSets[remainder]
          optimalCounts[remainder] = tempOptimalCounts[remainder]
    if 0 in optimalCounts:
      result += 1
      remainingGroups = [remainingGroups[i] for i in xrange(len(remainingGroups)) if i not in optimalSets[0]]
    else:
      return result + 1
  return result

with open('../inputs/A-large.in') as infile:
  with open('../outputs/A-large.out', 'wb') as outfile:
    cases = int(infile.readline())
    for i in xrange(cases):
      [N, P] = map(int, infile.readline().split(' '))
      groups = map(int, infile.readline().split(' '))
      outfile.write('Case #' + str(i + 1) + ': ')
      outfile.write(str(maximizeFreshChocolate(N, P, groups)))
      outfile.write('\n')
