N = int(input())
max_counter = 0
ans = 1

for i in range(N+1):
    counter = 0
    ans_i = i
    for j in range(7):
        if i % 2 == 0:
            counter += 1
            i = i / 2
        else:
            if counter > max_counter:
                 max_counter = counter
                 ans = ans_i
            break

print(ans)