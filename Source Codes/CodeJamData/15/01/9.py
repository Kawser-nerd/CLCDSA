num_cases = input()
for case in range(num_cases):
  raw_counts = raw_input().split()[1]
  counts = map(int, list(raw_counts))

  standing = 0
  invited = 0
  for i, count in enumerate(counts):
    if count:
      to_invite = max(i - standing, 0)
      invited += to_invite
      standing += to_invite + count
  print 'Case #%d: %d' % (case + 1, invited)
