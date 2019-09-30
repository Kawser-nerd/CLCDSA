import sys

cache = {}
def walk(chests, keys, path, opened):
  if sum(opened) == len(opened): return list(path)
  if sum(keys) == 0: return []
  cache_key = tuple(keys), tuple(opened)
  if cache_key in cache: return cache[cache_key]
  for chest_id, [key_id, chest_keys] in enumerate(chests):
    if opened[chest_id]: continue
    if 0 < keys[key_id]:
      keys[key_id] -= 1
      opened[chest_id] = True
      path.append(chest_id)
      for kid in chest_keys: keys[kid] += 1
      path_ = walk(chests, keys, path, opened)
      for kid in chest_keys: keys[kid] -= 1
      path.pop()
      opened[chest_id] = False
      keys[key_id] += 1
      if path_:
        cache[cache_key] = path_
        return path_
  cache[cache_key] = []
  return []


samples = int(sys.stdin.readline().rstrip())
for i in xrange(samples):
  cache.clear()
  [k, n] = sys.stdin.readline().rstrip().split()
  n, k = int(n), int(k)
  key_ids = sys.stdin.readline().rstrip()
  keys = [0] * 26
  for kid in key_ids.split(): keys[int(kid)] += 1
  chests = []
  for chest_id in xrange(n):
    chest_line = sys.stdin.readline().rstrip().split()
    chest_line = map(lambda x: int(x), chest_line)
    chests.append([chest_line[0], chest_line[2:]])
  path = walk(chests, keys, [], [False] * n)
  path = ' '.join(map(lambda x: str(1+x), path)) if path else 'IMPOSSIBLE'
  print "Case #%d: %s" % (i+1, path)
