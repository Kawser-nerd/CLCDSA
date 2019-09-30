n,*a=map(int,open(0).read().split())
print(min(max(sum(a[s]*(t>>s&1)for s in range(n)),sum(a[s]*(not t>>s&1)for s in range(n)))for t in range(2**n)))