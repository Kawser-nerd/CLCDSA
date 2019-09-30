N, K = map(int,input().split())
h_list = [int(input()) for _ in range(N)]

h_list.sort(reverse = True)
diff = [h_list[i] - h_list[i+K-1] for i in range(N-K+1)]
print(min(diff))