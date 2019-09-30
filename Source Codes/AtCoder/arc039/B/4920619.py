#Combination???
class Combination:

  def __init__(self,n,mod):
    self.fact = [1]
    for i in range(1, n+1):
      self.fact.append(self.fact[-1] * i % mod)

    self.inv_fact = [pow(self.fact[i] ,mod-2 ,mod) for i in range(n+1)]

    self.mod = mod

  #i!????
  def factorial(self,i):
    return self.fact[i]

  #i!???????
  def inverse_factorial(self,i):
    return self.inv_fact[i]

  #i_C_r????
  def combination(self,i,j):
    return (self.fact[i] * self.inv_fact[i-j] * self.inv_fact[j]) % self.mod

n, k = map(int, input().split())
MOD = 10**9+7
comb = Combination(n+k, MOD)

if k//n ==0:
    print(comb.combination(k+n-1,k))
else:
    otoku_enji_num = n - k%n
    son_enji_num = n - otoku_enji_num
    print(comb.combination(n,otoku_enji_num))