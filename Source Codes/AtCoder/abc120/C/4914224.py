S = input()

remove_count = 0
# while(True) :
#     S = S.replace("10","X").replace("01","X")
#     current_count = S.count("X")
#     if (current_count == 0) :
#         break
#     remove_count += current_count
#     S = S.replace("X","")
# print(remove_count * 2)
print(min(S.count("1"), S.count("0") )* 2)