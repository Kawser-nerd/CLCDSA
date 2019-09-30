w = str(input())
ban_list = ['a', 'i', 'u', 'e', 'o']
for ban in ban_list:
    w = w.replace(ban, '')
print(w)