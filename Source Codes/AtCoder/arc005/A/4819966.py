n = int(input())
W = list(input().split())
word = ["TAKAHASHIKUN","Takahashikun","takahashikun","TAKAHASHIKUN.","Takahashikun.","takahashikun."]
cnt = 0
for w in W:
	if w in word:
		cnt += 1
print(cnt)