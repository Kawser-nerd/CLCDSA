n, k = map(int, input().split())
lst = [list(map(int, input().split())) for i in range(n)]

answer = 10**100
sortx = sorted(lst, key = lambda x: x[0])
for a, pt1 in enumerate(sortx[:n-k+1]):
    for b, pt2 in enumerate(sortx[a+k-1:]):
        #print(a,b)
        sorty = sorted(sortx[a:a+k+b], key = lambda x: x[1])
        sorty_len = len(sorty)
        for c, pt3 in enumerate(sorty[:sorty_len-k+1]):
            #print(len(sorty), c, k)
            pt4 = sorty[c+k-1]
            #print(pt1, pt2, pt3, pt4)
            if pt3[1] <= pt1[1] and pt3[1] <= pt2[1] and pt4[1] >= pt1[1] and pt4[1] >= pt2[1]:
                answer = min(answer, (pt2[0] - pt1[0]) * (pt4[1] - pt3[1]))
print(answer)