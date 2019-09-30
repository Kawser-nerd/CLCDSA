A,B,K,L = map(int,input().split(" "))
p = [A * K]
p.append((K // L + 1)*B)

for i in range(1,K+1):
    if K - (L * i) >= 0:
        temp = i * B + (K - (L*i)) * A
        p.append(temp)
    else:
        break
#print(p)
print(min(p))