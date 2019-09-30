n = int(input())
plist = list(map(int, input().split()))

prevp = plist[0]
swap = 0
is_swap = False
for i, p in enumerate(plist[1:]):
  if is_swap:
    is_swap = False
  elif i+1 == prevp:
    is_swap = True
    swap += 1
  prevp = p

print(swap + (1 if not is_swap and plist[-1] == len(plist) else 0))