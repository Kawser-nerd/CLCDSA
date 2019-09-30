n,m,l=map(int,input().split())
p,q,r=map(int,input().split())

case_1=(n//p)*(m//q)*(l//r)
case_2=(n//p)*(m//r)*(l//q)
case_3=(n//q)*(m//p)*(l//r)
case_4=(n//q)*(m//r)*(l//p)
case_5=(n//r)*(m//p)*(l//q)
case_6=(n//r)*(m//q)*(l//p)

print(max(case_1,case_2,case_3,case_4,case_5,case_6))