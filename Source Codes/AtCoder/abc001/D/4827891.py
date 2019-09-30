N = int(input())
def r_forward(string):
    return str(int(string)-int(string)%5).zfill(4)
def r_backward(string):
    ret = str( int(string)+4-(int(string)-1)%5).zfill(4)
    if ret[2]=="6":
        ret = (str(int(ret[:2])+1)+"00").zfill(4)
    return ret
time_lst = []
for i in range(24):
    for j in range(12):
        time_lst.append(str(i).zfill(2)+str(j*5).zfill(2))
time_lst.append("2400")
rained =[ list([time,0]) for time in time_lst]
for i in range(N):
    st_,end_ = input().split("-")
    for idx in range(time_lst.index(r_forward(st_)),time_lst.index(r_backward(end_))):
        rained[idx][1] = 1
prev = 0
for i,j in rained:
    if prev==0 and j ==1:
        st = i
    if prev ==1 and (j==0 or i =="2400"):
        print("{}-{}".format(st,i))
    prev = j