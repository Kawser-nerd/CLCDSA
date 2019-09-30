# -*- coding: utf-8 -*-
n = int(input())
s = input()

def check(l):
    if s[0]=="o":
        if l[0]=="S":
            if l[-1]!=l[1]:
                return False
        else:
            if l[-1]==l[1]:
                return False
    else:
        if l[0]=="S":
            if l[-1]==l[1]:
                return False
        else:
            if l[-1]!=l[1]:
                return False
    for i in range(1,n-1):
        if s[i]=="o":
            if l[i]=="S":
                if l[i-1]!=l[i+1]:
                    return False
            else:
                if l[i-1]==l[i+1]:
                    return False
        else:
            if l[i]=="S":
                if l[i-1]==l[i+1]:
                    return False
            else:
                if l[i-1]!=l[i+1]:
                    return False
    if s[n-1]=="o":
        if l[n-1]=="S":
            if l[n-2]!=l[0]:
                return False
        else:
            if l[n-2]==l[0]:
                return False
    else:
        if l[n-1]=="S":
            if l[n-2]==l[0]:
                return False
        else:
            if l[n-2]!=l[0]:
                return False
    return True

def flip(x):
    if x=="S":
        return "W"
    else:
        return "S"

def fill(s0,s1):
    ret = [None for _ in range(n)]
    ret[0] = s0
    ret[1] = s1
    for i in range(1,n-1):
        if ret[i]=="S" and s[i]=="o":
            ret[i+1] = ret[i-1]
        elif ret[i]=="S" and s[i]=="x":
            ret[i+1] = flip(ret[i-1])
        elif ret[i]=="W" and s[i]=="o":
            ret[i+1] = flip(ret[i-1])
        elif ret[i]=="W" and s[i]=="x":
            ret[i+1] = ret[i-1]
    # print(ret)
    if check(ret):
        return ret
    else:
        return None

ret = fill("S","S")
if ret is not None:
    print("".join(ret))
    exit()

ret = fill("S","W")
if ret is not None:
    print("".join(ret))
    exit()

ret = fill("W","S")
if ret is not None:
    print("".join(ret))
    exit()

ret = fill("W","W")
if ret is not None:
    print("".join(ret))
    exit()
print(-1)