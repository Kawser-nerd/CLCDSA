s = input()


p_count = s.count("+")
m_count = s.count("-")
m = s.count("M")
prev_m = 0
prev_p = 0
pm_count = [0 for _ in range(m)]
j = 0
for i in range(len(s)):
    if s[i] == "+":
        prev_p += 1
        continue

    if s[i] == "-":
        prev_m += 1
        continue
    pm_count[j] = (p_count - prev_p) - (m_count - prev_m)
    j += 1
pm_count.sort()

print(sum(pm_count[m//2:]) - sum(pm_count[:m//2]))