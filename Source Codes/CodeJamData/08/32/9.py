def ugly(numbers,number,subtracting,current):
    if (len(numbers) == 0):
        if (is_ugly(number+current)):
            return 1
        else:
            return 0
    if subtracting:
        return ugly(numbers[1:],number+current,False,int(numbers[0])) + ugly(numbers[1:],number+current,True,-int(numbers[0])) + ugly(numbers[1:],number,subtracting,current * 10 - int(numbers[0]))
    else:
        return ugly(numbers[1:],number+current,False,int(numbers[0])) + ugly(numbers[1:],number+current,True,-int(numbers[0])) + ugly(numbers[1:],number,subtracting,current * 10 + int(numbers[0]))

def start_ugly(numbers):
    return ugly(numbers[1:],0,False,int(numbers[0]))

def is_ugly(number):
    if number % 2 == 0 or number % 3 == 0 or number % 5 == 0 or number % 7 == 0:
        return True
    else:
        return False

N = int(raw_input())
for i in range(1,N+1):
    print "Case #%d: %d" % (i, start_ugly(raw_input()))
