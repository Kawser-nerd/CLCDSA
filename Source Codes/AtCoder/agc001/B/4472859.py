def main():
    n,x=map(int,input().split())
    a,b=n-x,x
    if(a<b):
       a,b=b,a
    path_length = calc_path(a,b,n)
    print(path_length)

def  calc_path(a1,b1,c1):
    q , mod=divmod(a1,b1)
    count=0
    if mod==0:
         c2=c1+2*b1*q-b1
         return c2
    else:
        count=count+1
        c2=c1+2*b1*q
        a2=a1-b1*q
        b2=b1
        if(a2<b2):
           a2,b2=b2,a2
        return calc_path(a2,b2,c2)
if __name__=='__main__':
  main()