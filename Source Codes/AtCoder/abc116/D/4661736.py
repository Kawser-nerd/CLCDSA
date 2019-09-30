from collections import Counter
N, K =  map(int, (input().split(' ')))
sushi = [tuple(map(int, input().split(' '))) for _ in range(N)]
all_sushi = sorted(sushi, key=lambda x: -x[1])
default_sushi = all_sushi[:K]
amari = all_sushi[K:]
len_amari = len(amari)
counter = Counter([i[0] for i in default_sushi])
result = []
def calc_value(sushi):
    return sum([i[1] for i in sushi]) + len(counter)**2

fs = []
def change_sushi(sushi):
    oishisa = sum([i[1] for i in sushi])
    fs.append(oishisa + len(counter)**2)
    amari_index = 0
    for s in sushi[::-1]:
        if counter[s[0]] >= 2:
            while amari_index < len_amari:
                a = amari[amari_index]
                amari_index += 1
                if a[0] not in counter:
                    counter[s[0]] -= 1
                    counter[a[0]] += 1
                    oishisa = oishisa - s[1] + a[1]
                    fs.append(oishisa + len(counter)**2)
                    break
    print(max(fs))
    exit()
            
    
def get_sushi(sushi):
    #result.append(calc_value(sushi))
    changed_sushi = change_sushi(sushi)
    #if not changed_sushi:
        #print(max(result))
        #return
    #get_sushi(changed_sushi)

get_sushi(default_sushi)