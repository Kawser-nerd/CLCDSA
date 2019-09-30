A,B = map(int,input().split())
lists = list(range(A,B+1))
str_lists = list(str(lists[0]))
kaibun_lists = []
for i in range(len(lists)):
        for j in range(len(list(str(lists[i])))):
                kaibun = str(lists[i])[::-1]
        if lists[i] == int(kaibun):
                kaibun_lists.append(int(kaibun))
print(len(kaibun_lists))