using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static int n = int.Parse(Console.ReadLine());//int.Parse???????????
static long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
static List<long> numsThree = new List<long>();
static List<long> numsThreeR = new List<long>();
static long[] sum = new long[n+1];
static long[] sumR = new long[n+1];
static long answer = 0;
static long check = 0;

	static void Main()
	{
      
    for(int i=0; i<n; i++)
    {
    sum[0] += nums[i];
    numsThree.Add(nums[i]);
    
    sumR[n] += nums[3*n-1-i];
    numsThreeR.Add(nums[3*n-1-i]);
    }
    
    

    numsThree.Sort();//??????
    numsThreeR.Sort();//??????
    numsThreeR.Reverse();

      
    for(int i=0; i<n; i++)
    {
      numsThree = PushHeap(numsThree,nums[n+i]);
      sum[i+1] = sum[i] + nums[n+i];
      numsThree = PopHeap(numsThree);
      sum[i+1] -= check;

      numsThreeR = PushHeapR(numsThreeR,nums[2*n-1-i]);
      sumR[n-1-i] = sumR[n-i] + nums[2*n-1-i];
      numsThreeR = PopHeapR(numsThreeR);
      sumR[n-1-i] -= check;
    }
    
    answer = sum[0] - sumR[0];
    //Console.WriteLine(sum[0] +" "+ sumR[0]);//????
    for(int i=1; i<=n; i++)
    {
      long ans = sum[i] - sumR[i];
      //Console.WriteLine(sum[i] +" "+ sumR[i]);//????
      if(ans > answer) answer = ans;
    }
    
	Console.WriteLine(answer);
	}

  static List<long> PushHeap(List<long> nums, long addNum)//??????nums?addNum???
{
  int n = nums.Count;
  nums.Add(addNum);

  while (n > 0)
  {
    int i = (n-1)/2;
    if (nums[n] < nums[i])//???????????????
    {
      long tmp = nums[n];
      nums[n] = nums[i];
      nums[i] = tmp;
    }
    n = i;
  }
  return nums;
}

static List<long> PopHeap(List<long> nums)//???nums?????
{
  int n = nums.Count - 1;
  check = nums[0];
  nums[0] = nums[n];//???????????????????????
  nums.RemoveAt(n);

  for (int i = 0, j; (j = 2*i+1) < n; )
  {
    if ((j != n-1) && (nums[j] > nums[j+1]))// ?????????????????
      j++;
    if (nums[i] > nums[j])//??????????????
    {
      long tmp = nums[j];
      nums[j] = nums[i];
      nums[i] = tmp;
    }
    i = j;
  }
  return nums;
}

static List<long> PushHeapR(List<long> nums, long addNum)//??????nums?addNum???
{
  int n = nums.Count;
  nums.Add(addNum);

  while (n > 0)
  {
    int i = (n-1)/2;
    if (nums[n] > nums[i])//???????????????
    {
      long tmp = nums[n];
      nums[n] = nums[i];
      nums[i] = tmp;
    }
    n = i;
  }
  return nums;
}

static List<long> PopHeapR(List<long> nums)//???nums?????
{
  int n = nums.Count - 1;
  check = nums[0];
  nums[0] = nums[n];//???????????????????????
  nums.RemoveAt(n);

  for (int i = 0, j; (j = 2*i+1) < n; )
  {
    if ((j != n-1) && (nums[j] < nums[j+1]))// ?????????????????
      j++;
    if (nums[i] < nums[j])//??????????????
    {
      long tmp = nums[j];
      nums[j] = nums[i];
      nums[i] = tmp;
    }
    i = j;
  }
  return nums;
}




  
}