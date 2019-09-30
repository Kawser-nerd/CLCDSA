num = int(input())
count = 1
div_8_list = []
while count < num + 1:
    if count % 2 != 0:
        div = []
        for i in range(1, int(count**0.5)+1):
            if count % i == 0:
                div.append(i)
                if i != count // i:
                    div.append(count//i)
        if len(div) == 8:
            div_8_list.append(div)
    count += 1
print(len(div_8_list))