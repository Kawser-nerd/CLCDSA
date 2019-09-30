a, b = map(int, input().split())
a_line = (a-1) // 50 + 1
b_line = (b-1) // 50 +1
print(a_line*2 + b_line*2, 99)
for i in range(a_line):
    if i == a_line-1:
        print(('.#'*((a-1)%50) + '#'*(99-2*((a-1)%50))))
    else:
        print(('.#'*49+'.'))
    print('#'*99)
for i in range(b_line):
    print('.'*99)
    if i == b_line-1:
        print(('#.'*((b-1)%50) + '.'*(99-2*((b-1)%50))))
    else:
        print(('#.'*49+'#'))