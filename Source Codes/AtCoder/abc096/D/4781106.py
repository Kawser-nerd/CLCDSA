N = int(input())
def prime_table(n):
    list = [True for _ in range(n+1)]
    for i in range(2,int(n**0.5)+1):
        if list[i]:
            j = i*2
            while j<=n:
                list[j] = False
                j += i
    table = [i for i in range(n+1) if list[i] and i>=2]
    return table

table = prime_table(55555)
table_ = []
for i in range(len(table)):
    if table[i]%5==1:
        table_.append(table[i])
for i in range(N):
    print(table_[i],end=' ')
print('')