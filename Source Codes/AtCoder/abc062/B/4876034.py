H, W = map(int, input().split())

print('#'*(W+2))
for i in range(H):
    a = input()
    print('#'+a+'#')
print('#'*(W+2))