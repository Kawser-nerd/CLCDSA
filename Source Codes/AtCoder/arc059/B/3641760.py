import collections
S = input()

if len(S) == 1:
    print(-1,-1)
    exit()

tmp_s1 = '1'
tmp_s2 = '2'
tmp_s3 = '3'

for i,s in enumerate(S):
    if i == 0:
        tmp_s1 = s
    elif i == 1:
        tmp_s2 = s
    elif i == 3:
        tmp_s3 = s

    else:
        tmp_s1 = tmp_s2
        tmp_s2 = tmp_s3
        tmp_s3 = s

    if tmp_s1 == tmp_s2:
        print(i-1 + 1,i + 1)
        exit()
    elif tmp_s2 == tmp_s3:
        print(i, i+1)
        exit()
    elif tmp_s1 == tmp_s3:
        print(i-2 + 1,i + 1)
        exit()
print(-1,-1)