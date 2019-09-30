import math




# def single_num(n):
#     x = math.floor(math.sqrt(n))
#     s1 = x+math.ceil(n/x) - 1
#     s2 = x+math.ceil(n/(x+1))
#     if s1 < s2:
#         return (s1,x)
#     else:
#         return (s2,x+1)
#
# def solution(list):
#     list = sorted(list, reverse=True)
#     minutes= single_num(list[0])[0]
#     b= single_num(list[0])[1]
#     print(minutes,b)
#
#     list.remove(list[0])
#     for plate in list:
#         minutes += math.ceil(plate/b)-1
#     return minutes

f_in = open('file.in')
f_out = open('file.out', 'w')

def solution(plates):
    min = max(plates)
    for i in range(1,max(plates)):
        candidate = i+sum([math.ceil(plate/i)-1 for plate in plates])
        if candidate < min:
            min = candidate
    return min



cases = int(f_in.readline())
for i in range(1,cases+1):
    f_in.readline()
    plates = [int(i) for i in f_in.readline().split()]
    f_out.write("Case #"+str(i)+": "+str(solution(plates))+"\n")
