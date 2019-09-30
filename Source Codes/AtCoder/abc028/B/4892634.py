count_list = ["A", "B", "C", "D", "E", "F"]
ans_list = []
S_list = list(input())
for i in count_list:
    ans_list.append(S_list.count(i))
ans = " ".join(map(str, ans_list))
print(ans)