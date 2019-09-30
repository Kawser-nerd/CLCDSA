def main():
    N = int(input())
    As = list(map(int, input().split()))
    ct = 1
    inc = False
    dec = False
    bef = As.pop(0)

    for Ai in As:
        if (not inc) and (not dec):
            if Ai < bef:
                dec = True
            elif Ai > bef:
                inc = True
        elif inc:
            if Ai < bef:
                ct += 1
                inc = False
        elif dec:
            if Ai > bef:
                ct += 1
                dec = False
        bef = Ai
    
    print(ct)

main()