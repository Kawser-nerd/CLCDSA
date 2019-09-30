N = int(input())
list_an = input().split()
list_an_int = [int(s) for s in list_an]

list_an_int.sort()
list_an_int.reverse()

Alice_counter = 0
Bob_counter = 0

counter = 0
for i in range(N):
    if counter % 2 == 0:
        Alice_counter += list_an_int[i]
    else:
        Bob_counter += list_an_int[i]
    counter += 1
print(Alice_counter - Bob_counter)