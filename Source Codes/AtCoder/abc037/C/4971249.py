from numpy import*

def section_sum(numbers,separate):
    sep1=array(numbers[separate:])
    sep2=array(numbers[:-separate])
    sep3=sum(numbers[:separate])
    return insert(sep3+cumsum(sep1-sep2),0,sep3)

n,k,*a=map(int,open(0).read().split())
print(int(sum(section_sum(a,k))))