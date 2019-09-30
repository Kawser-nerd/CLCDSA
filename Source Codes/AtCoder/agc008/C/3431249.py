Ai, Ao, At, Aj, Al, As, Az = map(int, input().split())

ans = Ao + 2*(Ai//2 + Aj//2 + Al//2)
if Ai>0 and Aj>0 and Al>0:
  ans = max(ans, Ao + 2*((Ai-1)//2 + (Aj-1)//2 + (Al-1)//2) + 3)
  
print(ans)