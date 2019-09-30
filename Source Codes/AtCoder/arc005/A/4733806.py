N = int(input())
ws = [_ for _ in input()[:-1].split()]

t = [
    "TAKAHASHIKUN",
    "Takahashikun",
    "takahashikun"
]

result = sum([w in t for w in ws])

print(result)