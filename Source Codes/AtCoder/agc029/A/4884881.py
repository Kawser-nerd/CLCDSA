txt = input()
txt_list = list(txt)

num = 0
count = 0
for i in range(len(txt)):
    if txt_list[i] == 'W':
        count += i-num 
        num += 1

print(count)