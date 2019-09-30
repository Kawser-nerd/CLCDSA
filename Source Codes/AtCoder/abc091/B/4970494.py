Blue_card = [input() for i in range(int(input()))]
Red_card = [input() for i in range(int(input()))]
ans_list = [0]
for i in set(Blue_card):
    ans_list.append(Blue_card.count(i) - Red_card.count(i))
print(max(ans_list))