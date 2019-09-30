def solve():
  n = int(raw_input())
  levels = []
  for i in range(n):
    ai, bi = map(int, raw_input().split())
    levels.append((i, ai, bi)) #(level, one-start, two-star)
  current = 0
  status = [0] * n
  answer = 0

  max_level = (9999999, 9999999, 9999999)

  def get_min_two_star_level():
    try:
      return min(levels, key=lambda x: x[2])
    except ValueError:
      return max_level

  def get_max_satisfying_level(current):
    try:
      return max(filter(lambda x: x[1] <= current and status[x[0]] == 0, levels), key=lambda x: x[2])
    except ValueError:
      return max_level

  while len(levels) > 0:
    level, one_star, two_star = get_min_two_star_level()
    if two_star <= current:
      levels.remove((level, one_star, two_star))
      if status[level] == 0:
        current += 2
      else:
        current += 1
      status[level] = 2
      answer += 1
    else:
      level, one_star, two_star = get_max_satisfying_level(current)
      if one_star > current:
        return -1
      else:
        current += 1
        status[level] = 1
      answer += 1

  return answer

def main():
  t = int(raw_input())
  for i in range(t):
    ans = solve()
    if ans < 0:
      ans = "Too Bad"
    print "Case #%d: %s" % (i + 1, str(ans))

if __name__ == '__main__':
  main()
