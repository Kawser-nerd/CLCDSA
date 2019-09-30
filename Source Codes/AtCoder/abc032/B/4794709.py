s = input()
k = int(input())

dic = {}
for i in range(len(s)-k+1):
    word = s[i:i+k]
    dic[word] = 1

print(len(dic.keys()))