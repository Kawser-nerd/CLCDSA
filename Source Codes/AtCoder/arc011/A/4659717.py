m, n, N = map(int, input().split())
sales = N
mod = N

while mod >= m:
    get = mod//m * n
    sales += get
    mod = mod % m + get

print(sales)