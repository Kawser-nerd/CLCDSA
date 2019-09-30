h, w, t = map(int, input().split())
sw = [[""] * (w+2)]
Stt=[]
End=[]
for i in range(1, h+1):
    tmp = [""] + list(input()) + [""]
    sw.append(tmp)
    for j in range(len(tmp)):
        if tmp[j] == "S":
            Stt = [i, j]
        elif tmp[j] == "G":
            End = [i, j]
sw.append([""]*(w+2))

def belmanford(x):
    count_sw = [[t+1]*(w+2) for _ in range(h+2)]
    count_sw[Stt[0]][Stt[1]] = 0
    next_turn = [Stt]
    while next_turn:
        n = next_turn.pop(0)
        for d in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
            tmpn = [n[0]+d[0], n[1]+d[1]]
            if sw[tmpn[0]][tmpn[1]] == "":
                continue
            elif sw[tmpn[0]][tmpn[1]] == "#":
                if count_sw[n[0]][n[1]] + x < count_sw[tmpn[0]][tmpn[1]]:
                    count_sw[tmpn[0]][tmpn[1]] = count_sw[n[0]][n[1]] + x
                    next_turn.append(tmpn)
            else:
                if count_sw[n[0]][n[1]] + 1 < count_sw[tmpn[0]][tmpn[1]]:
                    count_sw[tmpn[0]][tmpn[1]] = count_sw[n[0]][n[1]] + 1
                    next_turn.append(tmpn)
    if count_sw[End[0]][End[1]] <= t:
        return True
    else:
        return False

bi_hi = t
bi_lo = 0
while bi_hi - bi_lo != 1:
        tmp = (bi_hi+bi_lo)//2
        if(belmanford(tmp)):
            bi_lo = tmp
        else:
            bi_hi = tmp
print(bi_lo)