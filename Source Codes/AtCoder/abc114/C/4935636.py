N=int(input())
def is753(s):
    if int(s)>N:
        return 0
    ret=1 if all(s.count(c)>0 for c in '753') else 0
    for c in "753":
        ret+=is753(s+c)
    return ret
print(is753('0'))