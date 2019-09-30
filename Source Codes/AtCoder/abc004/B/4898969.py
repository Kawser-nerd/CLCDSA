a = []
for _ in range(4):
    a.append(list(input()))    
a = list(reversed(a))
for a_ in a:
    a_ = list(reversed(a_))
    print("".join(a_))