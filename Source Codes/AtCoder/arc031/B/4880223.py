import sys

land = []
first_check = [0, 0]
for i in range(10):
    lst = list(input())
    if 'o' in lst:
        first_check[0] = i
        first_check[1] = lst.index('o')
    land.append(lst)

check = [[0] * 10 for _ in range(10)]

def search(row, col, id):
    if (row < 0 or row >= 10 or col < 0 or col >= 10 or land[row][col] == 'x'):
        return
    if (check[row][col] == id):
        return
    check[row][col] = id

    search(row - 1, col, id)
    search(row + 1, col, id)
    search(row, col - 1, id)
    search(row, col + 1, id)
            
# ????0????????
search(first_check[0], first_check[1], 1)
ans = "YES"
for row in range(10):
    for col in range(10):
        if land[row][col] == 'o' and check[row][col] == 0:
            ans ='NO'
            break
if (ans == "YES"):
    print("YES")
    sys.exit()

for i in range(10):
    for j in range(10):
        ans = "YES"
        # ???1???????
        if land[i][j] == 'x':
            land[i][j] = 'o'
        else:
            continue

        search(i, j, 1)
        
        for row in range(10):
            for col in range(10):
                if land[row][col] == 'o' and check[row][col] == 0:
                    ans ='NO'
                    break
            if land[row][col] == 'o' and check[row][col] == 0:
                ans ='NO'
                break        

        if (ans == "YES"):
            print("YES")
        
            sys.exit()
        else:
            check = [[0] * 10 for _ in range(10)]
            land[i][j] = 'x'
print("NO")