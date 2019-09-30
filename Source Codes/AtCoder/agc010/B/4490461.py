n=int(input())
a=list(map(int,input().split()))
q,m=divmod(sum(a),n*(n+1)//2)
print('YNEOS'[any([(y-x-q)%n or y-x>q or m for x,y in zip(a[:-1],a[1:])])::2])