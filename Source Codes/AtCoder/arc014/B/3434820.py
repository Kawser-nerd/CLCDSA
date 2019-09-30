a = int(input())
ar = []
for i in range(a):
    if i == 0:
        l = input()
        ar.append(l)
    elif i >= 1:
        l = input()
        if l not in ar:
            g = ar[len(ar)-1]
            if g[-1] == l[0]:
                ar.append(l)
            else:
                if i % 2 == 0:
                    print("LOSE")
                    break
                else:
                    print("WIN")
                    break
        else:
            if i % 2 == 0:
                print("LOSE")
                break
            else:
                print("WIN")
                break
if len(ar) == a:
    print("DRAW")