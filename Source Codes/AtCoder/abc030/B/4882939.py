h,m=map(int,input().split())

tyo=(h%12)*30+m*0.5
tan=m*6

print(min(abs(tyo-tan),360-abs(tyo-tan)))