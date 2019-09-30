N = int(input())
S = input()
max_cnt = 0
for i in range(N):
  li1 = [0]*26
  li2 = [0]*26
  cnt = 0
  for j in S[i:]:
    li1[ord(j)-97]+=1
  for j in S[:i]:
    li2[ord(j)-97]+=1
  for j in range(26):
    if(li1[j]>0 and li2[j]>0):
      cnt += 1
  max_cnt = max(max_cnt,cnt)
print(max_cnt)