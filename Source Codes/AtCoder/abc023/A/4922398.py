def digit(i, lst=[]):
    if i > 0:
        lst.append(i%10)
        return digit(i//10, lst)
    else:
        lst.reverse()
        return lst
print(sum(digit(int(input()))))