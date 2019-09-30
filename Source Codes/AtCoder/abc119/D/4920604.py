import itertools
A,B,Q = [int(_) for _ in input().split(" ")]
s_array = [int(input()) for _ in range(A)]
t_array = [int(input()) for _ in range(B)]                                                  
x = [int(input()) for _ in range(Q)]

def binary_search(arr,point,start,end):
    pivot = (start+end)//2
    if end -start > 1:
        if arr[pivot] <point :
            return binary_search(arr,point,pivot,end)
        else:
            return binary_search(arr,point,start,pivot)
    else:
        return start
    
def find_closest_path(s_1,s_2,t_1,t_2,point):
    shortest = 10**11
    for s,t in itertools.product([s_1,s_2],[t_1,t_2]):
        length = min(abs(point-t), abs(point -s )) + abs(s - t)
        if length < shortest:
            shortest = length 
    return shortest 


for i in range(Q):
    s_idx = binary_search(s_array,x[i],0,len(s_array)-1)
    t_idx = binary_search(t_array,x[i],0,len(t_array)-1)
    if len(s_array)>1:
        s_1,s_2 = s_array[s_idx],s_array[s_idx+1] 
    else:
        s_1,s_2 = s_array[0],s_array[0]
    if len(t_array)>1:
        t_1,t_2 = t_array[t_idx],t_array[t_idx+1]    
    else:
        t_1,t_2 = t_array[0],t_array[0]
    answer = find_closest_path(s_1,s_2,t_1,t_2,x[i])
    print(answer)