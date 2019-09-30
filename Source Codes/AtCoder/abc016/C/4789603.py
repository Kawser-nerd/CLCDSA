n, m = map(int, input().split())

friend_dict = {}

for i in range(m):
    a, b = map(int, input().split())

    if a in friend_dict.keys():
         friend_dict[a].append(b)
    else:
         friend_dict[a] = [b]
    
    if b in friend_dict.keys():
         friend_dict[b].append(a)
    else:
         friend_dict[b] = [a]

for i in range(1, n + 1):
    friends = set()
    if i in friend_dict.keys():
        for j in friend_dict[i]:
            for k in friend_dict[j]:
                if k != i and k not in friend_dict[i]:
                    friends.add(k)
    print(len(friends))