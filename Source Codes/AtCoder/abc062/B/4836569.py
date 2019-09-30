h,w,=map(int,input().split())
ss = [input() for _ in range(h)]
print('#'*(w+2))
for s in ss:
    print('#'+s+'#')
print('#'*(w+2))