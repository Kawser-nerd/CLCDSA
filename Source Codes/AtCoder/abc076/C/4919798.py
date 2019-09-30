Sd = input()
T = input()

Sd = Sd[::-1]
T = T[::-1]
flg = False
for s in range(len(Sd) - len(T)+1):
    # print(Sd[s:s + len(T)])
    cnt = 0
    for t in range(len(T)):
        # print(Sd[s+t:s + t+1], T[t])
        if Sd[s+t:s + t+1] == T[t] or Sd[s+t:s + t+1] == "?":
            cnt += 1
        else:
            continue
    if cnt == len(T):
        S = Sd.replace(Sd[s:s + len(T)], T, 1)
        S = S.replace("?", "a")
        print(S[::-1])
        flg = True
        break

if flg is False:
    print("UNRESTORABLE")