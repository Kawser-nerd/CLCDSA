L,R = map(int,input().split())
l_list = sorted(list(map(int,input().split())))
r_list = sorted(list(map(int,input().split())))
l_index = 0
r_index = 0
c = 0
while True:
    if l_list[l_index] == r_list[r_index]:
        l_index += 1
        r_index += 1
        c += 1
    elif l_list[l_index] > r_list[r_index]:r_index += 1
    else:l_index += 1
    if l_index == len(l_list) or r_index == len(r_list):break
print(c)