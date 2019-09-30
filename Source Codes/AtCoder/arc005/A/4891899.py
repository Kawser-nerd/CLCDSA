N = int(input())
w = input()[:-1].split()

ans = len([x for x in w if x.lower() == 'takahashikun'])
print(ans)