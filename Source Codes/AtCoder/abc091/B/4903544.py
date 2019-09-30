N = int(input())
blue = {}
for _ in range(N):
    s = input().rstrip()
    if blue.get(s) == None:
        blue[s] = 1
    else:
        blue[s] += 1
M = int(input())
red = {}
for _ in range(M):
    t = input().rstrip()
    if red.get(t) == None:
        red[t] = 1
    else:
        red[t] += 1
answer = 0
for i, blue_elem in blue.items():
    red_elem = red[i] if red.get(i) != None else 0
    answer = blue_elem - red_elem if answer < blue_elem - red_elem else answer
print(answer)