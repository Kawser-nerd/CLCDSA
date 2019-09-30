N,T = map(int,input().split())
A = list(map(int,input().split()))

cummax = [A[-1]]
for a in reversed(A[:-1]):
    cummax.append(max(cummax[-1], a))
cummax.reverse()

maxgain = n = 0
for buy,sell in zip(A,cummax):
    gain = sell - buy
    if gain > maxgain:
        maxgain = gain
        n = 1
    elif gain == maxgain:
        n += 1
print(n)