num_cases = int(raw_input())

for case_num in xrange(1, num_cases + 1):
  line = raw_input().split()
  N = int(line[0])

  colors = []
  moves = {'O': [], 'B': []}
  positions = {'O': 1, 'B': 1}
  count = 0

  for i in xrange(N):
    r, p = line[2*i+1], int(line[2*i+2])
    colors.append(r)
    moves[r].append(p)

  # reverse to pop easily
  colors = colors[::-1]
  moves['O'] = moves['O'][::-1]
  moves['B'] = moves['B'][::-1]

  while colors:
    color = colors.pop()
    other_color = 'O' if color == 'B' else 'B'
    current = positions[color]
    other_current = positions[other_color]
    target = moves[color].pop()
    if moves[other_color]:
      other_target = moves[other_color][-1]
    time_to_push = abs(target - current) + 1

    # move current
    count += time_to_push
    positions[color] = target

    # move other
    delta = other_target - other_current
    if abs(delta) <= time_to_push:
      positions[other_color] = other_target
    else:
      sign = -1 if delta < 0 else 1
      positions[other_color] += sign * time_to_push

  print "Case #%d: %d" % (case_num, count)
