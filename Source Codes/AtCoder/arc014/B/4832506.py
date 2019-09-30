n = int(input())
W = []
W.append(input())

for i in range(n-1):
    new_w = input()
    if new_w in W:
        if i % 2 == 0:
            print("WIN")
            break
        else:
            print("LOSE")
            break
    else:
        last_w = W[-1]
        if last_w[-1] != new_w[0]:
            if i % 2 == 0:
                print("WIN")
                break
            else:
                print("LOSE")
                break
        else:
            W.append(new_w)
else:
    print("DRAW")