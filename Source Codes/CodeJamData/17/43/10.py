import itertools

def bruteForce(R, C, grid):
  beamShooters      = set()
  unoccupiedSquares = set()
  for r in xrange(R):
    for c in xrange(C):
      if grid[r][c] in '|-':
        beamShooters.add((r, c))
      if grid[r][c] == '.':
        unoccupiedSquares.add((r, c))
  possibleOrientations = {}
  occupiedSquares      = {}
  for (r, c) in beamShooters:
    possibleOrientations[(r, c)] = ''
    # Orientation -
    squares = set()
    possible = True
    for velocity in [(0, 1), (0, -1)]:
      beamR = r
      beamC = c
      while True:
        beamR, beamC = beamR + velocity[0], beamC + velocity[1]
        if beamR < 0 or beamR >= R or beamC < 0 or beamC >= C or grid[beamR][beamC] == '#':
          break
        elif grid[beamR][beamC] in '|-':
          possible = False
          break
        elif grid[beamR][beamC] == '\\':
          velocity = (velocity[1], velocity[0])
        elif grid[beamR][beamC] == '/':
          velocity = (-velocity[1], -velocity[0])
        elif grid[beamR][beamC] == '.':
          squares.add((beamR, beamC))
    if possible:
      possibleOrientations[(r, c)] = possibleOrientations.get((r, c), '') + '-'
      occupiedSquares[(r, c, '-')] = squares
    # Orientation |
    squares = set()
    possible = True
    for velocity in [(1, 0), (-1, 0)]:
      beamR = r
      beamC = c
      while True:
        beamR, beamC = beamR + velocity[0], beamC + velocity[1]
        if beamR < 0 or beamR >= R or beamC < 0 or beamC >= C or grid[beamR][beamC] == '#':
          break
        if grid[beamR][beamC] in '|-':
          possible = False
          break
        if grid[beamR][beamC] == '\\':
          velocity = (velocity[1], velocity[0])
        if grid[beamR][beamC] == '/':
          velocity = (-velocity[1], -velocity[0])
        if grid[beamR][beamC] == '.':
          squares.add((beamR, beamC))
    if possible:
      possibleOrientations[(r, c)] = possibleOrientations.get((r, c), '') + '|'
      occupiedSquares[(r, c, '|')] = squares
    # Small optimization to ignore useless directions
    if len(possibleOrientations[(r, c)]) == 2:
      if len(occupiedSquares[(r, c, '|')]) == 0:
        possibleOrientations[(r, c)] = '-'
      elif len(occupiedSquares[(r, c, '-')]) == 0:
        possibleOrientations[(r, c)] = '|'
  # Small optimization to force directions that are mandatory, and quit early if some square is never touched
  reverseMapping = {}
  for square in unoccupiedSquares:
    reverseMapping[square] = []
  for beamShooter in beamShooters:
    for orientation in possibleOrientations[beamShooter]:
      for square in occupiedSquares[(beamShooter[0], beamShooter[1], orientation)]:
        reverseMapping[square] = reverseMapping[square] + [(beamShooter[0], beamShooter[1], orientation)]
  for square in unoccupiedSquares:
    if len(reverseMapping[square]) == 0:
      return 'IMPOSSIBLE'
    elif len(reverseMapping[square]) == 1:
      (r, c, orientation) = reverseMapping[square][0]
      possibleOrientations[(r, c)] = ''.join(filter(lambda x: x == orientation, possibleOrientations[(r, c)]))
  # Give up if some shooter has no orientations left
  for beamShooter in beamShooters:
    if len(possibleOrientations[beamShooter]) == 0:
      return 'IMPOSSIBLE'
  # Compute the answer
  beamShootersList = list(beamShooters)
  for choice in itertools.product(*[possibleOrientations[beamShooter] for beamShooter in list(beamShooters)]):
    coveredSquares = set()
    for i in xrange(len(beamShootersList)):
      (r, c) = beamShootersList[i]
      coveredSquares = coveredSquares.union(occupiedSquares[(r, c, choice[i])])
    if len(coveredSquares) == len(unoccupiedSquares):
      for i in xrange(len(beamShootersList)):
        (r, c) = beamShootersList[i]
        grid[r][c] = choice[i]
      return '\n'.join(['POSSIBLE'] + map(lambda row: ''.join(row), grid))
  return 'IMPOSSIBLE'

with open('../inputs/C-small-attempt0.in') as infile:
  with open('../outputs/C-small-attempt0.out', 'wb') as outfile:
    cases = int(infile.readline())
    for i in xrange(cases):
      [R, C] = map(int, infile.readline().split(' '))
      grid = []
      for _ in xrange(R):
        grid.append(list(infile.readline().strip()))
      outfile.write('Case #' + str(i + 1) + ': ')
      outfile.write(bruteForce(R, C, grid))
      outfile.write('\n')
