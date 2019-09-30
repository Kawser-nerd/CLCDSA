from copy import deepcopy

def smallest(cnt):
  result = ''
  for i in range(0, 10):
    for j in range(0, cnt[i]):
      result += chr(i+ord('0'))
  return result

def build(N, pos, cnt):
  new_cnt = deepcopy(cnt)
  for ch in N[:pos]:
    new_cnt[ord(ch)-ord('0')] -= 1
  result = N[:pos]
  d = None
  for i in range(ord(N[pos])-ord('0')+1, 10):
    if new_cnt[i]:
      d = i
      break
  if d is None:
    return None
  result += chr(d+ord('0'))
  new_cnt[d] -= 1
  result += smallest(new_cnt)
  return result

def main():
  T = int(raw_input())
  for i in range(1, T+1):
    print 'Case #%d: ' % i,
    N = raw_input()
    cnt = [0] * 10
    for n in N:
      cnt[ord(n)-ord('0')] += 1
    solution = None
    for i in range(len(N)-1, -1, -1):
      t = build(N, i, cnt)
      if t:
        solution = t
        break
    if solution is None:
      cnt[0] += 1
      for i in range(1, 10):
        if cnt[i]:
          solution = chr(i+ord('0'))
          cnt[i] -= 1
          break
      solution += smallest(cnt)
    print solution

if __name__ == '__main__':
  main()

