#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""atcoder ARC007 D

????????????????????????????
???0???????????????0???
???0?????1???????????????

???????????????2???????????????????

?2?????????????????????????????????
???:
  10021: ???0???
  20020: ???1???
"""

def seconds(S, i):
    for j in range(i+1, len(S)):
        if j != "0":
            yield j, int(S[i:j])
    yield len(S), int(S[i:])

def is_ok(S, j, a2, d):
    if j == len(S): return True

    ak = a2 + d
    while True:
        s_ak = str(ak)
        if S[j:].startswith(s_ak):
            j  += len(s_ak)
            ak += d
            if j == len(S): return True
        elif s_ak.startswith(S[j:]):
            return True
        else:
            return False

def main():
    S = input()

    if S.startswith("0"):
        S = "1" + S

    # ?? a1 ????
    # i:?2??????
    i = 1
    for i in range(1, len(S)):
        if S[i] != "0": break
    if i < len(S) and S[i] == "0": i += 1
    a1 = int(S[:i])

    # ??????????1?????
    if i == len(S):
        d = 1
        print(a1, d)
        return

    # ?2? a2 ???????????
    # j:?3??????
    for j, a2 in seconds(S, i):
        if a2 <= a1: continue
        d = a2 - a1
        if is_ok(S, j, a2, d):
            print(a1, d)
            return

    # ????????????2???????????????????
    # ????
    s_a1 = str(a1)
    s_a2 = S[i:]
    if s_a1.startswith(s_a2):
        if a1 <= 9: # 11, 22, ..., 99
            d = 10*int(s_a2) - a1
        else: # 1010, 10010, 30003 ??
            if s_a1 == s_a2:
                d = 10*int(s_a2) - a1
            else:
                d = 1
        print(a1, d)
    else:
        s_a2 += "0" * (len(s_a1)-len(s_a2))
        if a1 < int(s_a2):
            d = int(s_a2) - a1
        else:
            d = int(s_a2+"0") - a1
        print(a1, d)

if __name__ == "__main__": main()