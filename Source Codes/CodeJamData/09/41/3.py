def Swap(arr, i):
  arr[i - 1], arr[i] = arr[i], arr[i - 1]

for tc in range(1, int(input()) + 1):
  n = int(input())
  nums = []
  for i in range(n):
    s = input()
    nums.append(s.rfind("1") + 1)
  ans = 0
  for i in range(n):
    #print(nums)
    upperBound = i + 1
    if nums[i] > upperBound:
      for j in range(i + 1, n):
        if nums[j] <= upperBound:
          for k in range(j, i, -1):
            Swap(nums, k)
            # print("Swapped %d and %d" % (k, k - 1))
            ans += 1
          break
  print("Case #%d: %d" % (tc, ans))