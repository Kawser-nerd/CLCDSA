def min_index(array):
    index = 0
    figure = 100
    for i in range(len(array)):
        if(inputs[i] < 0):
            continue
        if(array[i] < figure):
            figure = array[i]
            index = i
    return index

def max_index(array):
    index = 0
    figure = 1
    for i in range(len(array)):
        if(inputs[i] < 0):
            continue
        if(array[i] > figure):
            figure = array[i]
            index = i
    return index

inputs = []
for i in range(3):
    inputs.append(int(input()))

inputs[min_index(inputs)] = -3
inputs[max_index(inputs)] = -1

for i in range(len(inputs)):
    if(inputs[i] > 0):
        inputs[i] = -2

for i in range(len(inputs)):
    print(inputs[i] * -1)