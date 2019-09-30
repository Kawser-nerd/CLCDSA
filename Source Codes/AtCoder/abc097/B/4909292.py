X = int(input())

ans = 1

for i in range(1, X+1):
    for j in range(2, X+1):
        bp = i**j
        if bp <= X and bp > ans:
            ans = bp
        if X < bp:
            break

print(ans)