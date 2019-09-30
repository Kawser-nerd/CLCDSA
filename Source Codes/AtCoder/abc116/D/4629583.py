import collections

index = 0

def maxsushi(sushi_list,eaten_sushi):
    global index
    max_val = [0,0]
    for i in range(index,len(sushi_list)):
        if(sushi_list[i][1] not in eaten_sushi):
            tmp = sushi_list[i]
            max_val = sushi_list[i]
            index = i
            break
    return max_val

N,K = map(int,input().split())
sushi = []
umasa = []
for _ in range(N):
    i,j = map(int,input().split())
    sushi.append(i)
    umasa.append(j)
l = list(zip(umasa,sushi))
l = sorted(l,reverse=True)
sushi_list = list(l)
eat_sushi = sushi_list[0:K]
eaten_sushi = set()
double_sushi = []
for i in range(K):
    if(sushi_list[i][1] not in eaten_sushi):
        eaten_sushi.add(sushi_list[i][1])
    else:
        double_sushi.append((sushi_list[i]))
manzoku = 0
sushi_list = sushi_list[K:N]
for i in range(len(eat_sushi)):
    manzoku += eat_sushi[i][0]
manzoku = manzoku + (len(eaten_sushi)) ** 2
tmp_manzoku = manzoku 
while double_sushi:
    tmp1 = double_sushi.pop()
    tmp2 = maxsushi(sushi_list,eaten_sushi)
    if(tmp2[0] == 0 and tmp2[1] == 0):
        break
    eaten_sushi.add(tmp2[1])
    tmp_manzoku = tmp_manzoku + tmp2[0] - tmp1[0] + len(eaten_sushi) ** 2 - (len(eaten_sushi) - 1) ** 2
    if (tmp_manzoku > manzoku):
        manzoku = tmp_manzoku
print(manzoku)