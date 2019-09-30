N = int(input())
S = input()
t = S.count("E")

mi = N
for i in range(N):
    if S[i] == "E":
        t -= 1
    # print(i, t)   
    mi = min(mi, t)
    
    if S[i] == "W":
        t += 1
    
print(mi)