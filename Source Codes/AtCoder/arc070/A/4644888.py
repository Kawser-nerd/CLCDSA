X=int(input())
print([t for t in range(10**5) if t*(t+1)/2<X][-1]+1)