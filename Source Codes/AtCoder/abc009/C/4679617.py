n, k = map(int, input().split())
s = input()
s_list = sorted(s)

def is_safe(string, length):
    c = {}
    
    for ch in s:
        if ch in c:
            c[ch] += 1
        else:
            c[ch] = 1
    
    for ch in string:
        if ch in c and c[ch] > 0:
            c[ch] -= 1
        else:
            return False
    
    c_1 = {}
    diff = 0

    for ch in s[:length]:
        if ch in c_1:
            c_1[ch] += 1
        else:
            c_1[ch] = 1

    for ch in string:
        if ch in c_1 and c_1[ch] > 0:
            c_1[ch] -= 1
        else:
            diff += 1

    for i in range(length):
        if s[i] != string[i]:
            diff += 1

    return diff <= k

ans = ""

for i in range(n):
    for j in s_list:
        if is_safe(ans + j, i + 1):
            ans += j
            break

print(ans)