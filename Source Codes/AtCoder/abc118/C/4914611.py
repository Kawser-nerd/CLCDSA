import fractions

N =int(input())
lives = [int(i) for i in input().split()]
gcd_value = lives[0]

for i in range(1,len(lives)) :
    gcd_value = fractions.gcd(gcd_value, lives[i])

print(gcd_value)