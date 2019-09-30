def tri(n):
  return n * (n - 1) / 2

def scf(o, e):
  return (e - o) * N - tri(e - o)

MAUDE = 1000002013
T = input()
for tc in range(1, T+1):
  N, M = [int(x) for x in raw_input().split(" ")]
  ev = []
  honor = 0
  for i in range(M):
    o, e, p = [int(x) for x in raw_input().split(" ")]
    ev.append([o, p])
    ev.append([e, -p])
    honor += p * scf(o, e)
  ev.sort()
  deler = 0
  for i in range(1, 2*M):
    if ev[i-1-deler][0] == ev[i-deler][0]:
      ev[i-1-deler][1] += ev[i-deler][1]
      del ev[i-deler]
      deler += 1
  people = []
  dishonor = 0
  for o, p in ev:
    if p > 0:
      people.append([o, p])
    loc = -1
    while p < 0:
      disem = min(-p, people[loc][1])
      dishonor += scf(people[loc][0], o) * disem
      p += disem
      people[loc][1] -= disem
      loc -= 1
  print "Case #" + str(tc) + ":", (honor - dishonor) % MAUDE