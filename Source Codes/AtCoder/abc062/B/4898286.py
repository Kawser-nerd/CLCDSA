h,w = map(int,input().split())
print('#'*(w+2))
for i in range(h):
    s = input()
    print('#'+s+'#')
print('#'*(w+2))