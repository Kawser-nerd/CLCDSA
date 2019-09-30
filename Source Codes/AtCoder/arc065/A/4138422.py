s = input()

search = []
search.append(s)
found = False

while len(search) > 0:
    se = search[0]
    # print(se, search)
    search = search[1:]
    if se in ("dream", "dreamer", "erase", "eraser"):
        print("YES")
        found = True
        break
    if len(se) < 5:
        continue
    if se[0:5] in ("dream", "erase"):
        search.append(se[5:])
    if se[0:6] in ("eraser"):
        search.append(se[6:])
    if se[0:7] in ("dreamer"):
        search.append(se[7:])

if not found:
    print("NO")