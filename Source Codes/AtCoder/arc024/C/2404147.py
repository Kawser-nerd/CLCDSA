from collections import defaultdict,Counter
from string import ascii_lowercase

N , K = list(map(int, input().split() ))
S= input()


counts = [] #(a,...z,index)

tmp_counter = Counter(S[:K])

def set_count(tmp_counter,_index):
    counts.append(tuple(tmp_counter[s] for s in ascii_lowercase)+(_index,))

set_count(tmp_counter,0)
for i in range(N-K):
    s_exclude = S[i]
    s_add = S[i+K]
    tmp_counter[s_exclude] -= 1
    tmp_counter[s_add] +=1
    set_count(tmp_counter,i+1)


#print(counts)

counts.sort()
tmp_count =counts[0]
for count in (counts[1:]):
    if tmp_count[:26]==count[:26]:
        if count[26] - tmp_count[26] >=K:
            print("YES")
            exit()
    else:
        tmp_count = count

print("NO")