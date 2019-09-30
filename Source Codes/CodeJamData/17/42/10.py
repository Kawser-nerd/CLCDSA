def optimalResult(N, C, positionsByPerson):
  fewestRides = 0
  for position in xrange(1, N + 1):
    # At each position consider the number of rides that must be forward of it
    # Also consider the frequencies per passenger
    totalRides = 0
    for B in positionsByPerson:
      rides = 0
      for P in positionsByPerson[B]:
        if P <= position:
          rides += 1
      fewestRides = max(rides, fewestRides)
      totalRides += rides
    fewestRides = max(fewestRides, (totalRides + position - 1) / position)
  # Count number of forced upgrades
  upgrades = 0
  for position in xrange(1, N + 1):
    frequency = 0
    for B in positionsByPerson:
      for P in positionsByPerson[B]:
        if P == position:
          frequency += 1
    upgrades += max(0, frequency - fewestRides)
  return ' '.join(map(str, [fewestRides, upgrades]))

with open('../inputs/B-large.in') as infile:
  with open('../outputs/B-large.out', 'wb') as outfile:
    cases = int(infile.readline())
    for i in xrange(cases):
      [N, C, M]         = map(int, infile.readline().split(' '))
      positionsByPerson = {}
      for _ in xrange(M):
        [P, B] = map(int, infile.readline().split(' '))
        positionsByPerson[B] = positionsByPerson.get(B, []) + [P]
      for B in positionsByPerson:
        positionsByPerson[B] = sorted(positionsByPerson[B])
      outfile.write('Case #' + str(i + 1) + ': ')
      outfile.write(optimalResult(N, C, positionsByPerson))
      outfile.write('\n')
