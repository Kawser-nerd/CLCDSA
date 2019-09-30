#!/usr/bin/env python3

def main():
    n = int(input())
    wn = input().split()
    strnums = [word_to_str_numbers(w) for w in wn]
    strnums = [s for s in strnums if s != ""]
    print(" ".join(strnums))

def word_to_str_numbers(w):
    di = {"b":"1", "c":"1", "d":"2", "w":"2", "t":"3", "j":"3", "f":"4", "q":"4", "l":"5", "v":"5",
          "s":"6", "x":"6", "p":"7", "m":"7", "h":"8", "k":"8", "n":"9", "g":"9", "z":"0", "r":"0"}
    sl = []
    for c in w:
        c = c.lower()
        if c not in di:
            continue
        sl.append(di[c])
    s = "".join(sl)
    return s

main()