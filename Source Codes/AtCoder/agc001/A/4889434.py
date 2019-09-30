N = input()
L = list(map(int, input().split()))

def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

guzai = 0

for i in range(int(N)):
    guzai += int(quicksort(L)[int(2*i)]) 

print (guzai)