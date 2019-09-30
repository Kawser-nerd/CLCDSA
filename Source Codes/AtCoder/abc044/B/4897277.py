import re

pattern = '[a-z]+$'
w = input()
result = re.match(pattern, w)
if result:
    w_set = set(list(w))
    for word in w_set:
        counter = w.count(word)
        if counter % 2 == 1:
            print('No')
            break
    else:
        print('Yes')
else:
    print('No')