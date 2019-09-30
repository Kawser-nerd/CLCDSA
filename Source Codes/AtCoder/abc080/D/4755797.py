##########################
from collections import defaultdict as ddict
N, C = map(int, input().split())
imos = [0] * (10**5 + 2)
last_s_by_c = ddict(lambda: 1)
last_t_by_c = ddict(int)
stc = [list(map(int, input().split())) for i in range(N)]
for s, t, c in sorted(stc, key=lambda x: x[1]):
	if last_t_by_c[c] != s:
		imos[last_s_by_c[c] - 1] += 1
		imos[last_t_by_c[c]] -= 1
		last_s_by_c[c] = s
	last_t_by_c[c] = t
for c in last_s_by_c:
	imos[last_s_by_c[c] - 1] += 1
	imos[last_t_by_c[c]] -= 1
for i in range(10**5 + 1):
	imos[i + 1] += imos[i]
print(max(imos))