n = int(input())
for case_no in range(1, n+1):
  n = int(input())
  words = [input().strip() for _ in range(n)]
  accs = []
  for word in words:
    acc = []
    for i in range(len(word)):
      if i > 0 and word[i] == word[i-1]:
        acc[-1][1] += 1
      else:
        acc.append([word[i],1])
    accs.append(acc)

  acclens = list(map(len, accs))
  fail = any([x != acclens[0] for x in acclens])
  answer = 0
  if not fail:
    for i in range(acclens[0]):
      # Check that all accs[j][i] are the same.
      if any([accs[0][i][0] != acc[i][0] for acc in accs]):
          fail = True
          break

      # Calculate a median.
      nums = [acc[i][1] for acc in accs]
      nums.sort()
      total = 0
      for num in nums:
        total += abs(num - nums[len(nums)//2])
      answer += total

  if fail:
    print("Case #" + str(case_no) + ": Fegla Won")
  else:
    print("Case #" + str(case_no) + ": " + str(answer))
