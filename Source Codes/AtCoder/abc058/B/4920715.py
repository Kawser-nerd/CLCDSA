O = input()
E = input()

res = ""
o_cnt = 0
e_cnt = 0
while True:
    if o_cnt == len(O) and e_cnt == len(E):
        break
    if o_cnt < len(O):
        res += O[o_cnt]
        o_cnt += 1

    if e_cnt < len(E):
        res += E[e_cnt]
        e_cnt += 1

print(res)