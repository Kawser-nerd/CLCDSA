a,square,qqq,b,c,qqqq,qqqqq=  list(map(int,input().split()))

a_ = a%2
b_ = b%2
c_ = c%2

b_sub = b-b_
c_sub = c-c_

if b_==1 and c_==1 and a>0:
    a=a-1
    a_ = a%2
    a_sub = a-a_
    print(a_sub+b_sub+c_sub+3+square)
elif a_==1 and c_==1 and b>0:
    a_sub = a-a_
    b = b-1
    b_ = b%2
    b_sub=b-b_
    print(a_sub+b_sub+c_sub+3+square)
elif a_==1 and b_==1 and c>0:
    a_sub = a-a_
    c = c-1
    c_ = c%2
    c_sub=c-c_
    print(a_sub+b_sub+c_sub+3+square)    
else:
    a_ = a%2
    a_sub = a-a_
    print(a_sub+b_sub+c_sub+square)