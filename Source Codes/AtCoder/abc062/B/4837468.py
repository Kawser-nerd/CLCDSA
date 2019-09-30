h,w = map(int, input().split())

print('#'*(w+2))
for i in range(h):
    print('#', end='')
    print(input(), end='')
    print('#')
print('#'*(w+2))