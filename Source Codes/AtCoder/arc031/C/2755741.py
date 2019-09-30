import bisect
N = int(input())
B = list(map(int,input().split()))
B_index = sorted([(b,_index) for _index,b in enumerate(B)])

complete = []
ans =0
for i,(val,_index) in enumerate(B_index):
    left = _index - bisect.bisect_left(complete,_index)
    right = N- left - i-1
    ans += min(left,right)
    bisect.insort_left(complete,_index)

print(ans)