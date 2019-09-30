n = int(input())
ans = 1
if n == 1:
    print("Deficient")
    quit()
i = 2
ans_l = ["Deficient", "Perfect", "Abundant"]
while i**2 <= n:
    if n%i == 0:
        ans += i
        if n//i != i:
            ans += n//i
    i += 1
key = (ans-n)//max(1,abs(ans-n))+1
print(ans_l[key])