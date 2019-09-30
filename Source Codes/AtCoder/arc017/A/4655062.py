N = int(input())
prime = [2]
p_flag = True

for i in range(3, int(N**0.5)+1, 2):
    flag = True
    for j in prime:
        if i % j == 0:
            flag = False
            break
    
    if flag:
        prime.append(i)

for i in prime:
    if N % i == 0:
        p_flag = False
        break

print("YES" if p_flag else "NO")