N = int(input())
print(min((N//10+1)*100, (N//10)*100+(N%10)*15))