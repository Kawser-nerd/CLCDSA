A_N,B_N = map(int, input().split())

A_line = set(map(int, input().split()))
B_line = set(map(int, input().split()))

uni = A_line | B_line
inter = A_line & B_line

print(len(inter)/len(uni))