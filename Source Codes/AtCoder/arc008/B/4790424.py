def main():
    input()
    name = input()
    kit = input()

    print(solve(name, kit))

def solve(name, kit):
    cnt = dict()
    for c in name:
        cnt[c] = cnt.get(c, 0) + 1
    
    r = 0
    for c, i in cnt.items():
        kitCount = kit.count(c)
        if kitCount == 0:
            return -1
        r = max(r, ceilDiv(i, kitCount))
    
    return r

def ceilDiv(x, y):
    r = x % y
    if r == 0:
        return x // y
    else:
        return x // y + 1

main()