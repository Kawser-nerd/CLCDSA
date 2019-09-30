using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
static string ss = Console.ReadLine();
static string alphabets = "abcdefghijklmnopqrstuvwxyz";//26??
static long[] alphaCount = new long[26];
static bool isPossible = true;//????????
static long[] origiStringNums = new long[ss.Length];
static long[] lookedAlphaCount = new long[26];
static long[] bits = new long[ss.Length+1];
static int[] s = ss.Select(c => c - 'a').ToArray();
static long writeNum = 1;
static long[][] leftMemo = new long[26][];
static long oddMemo = 0;
static long oddMemoSub = 0;
	static void Main()
	{
    
    for(long stNum = 0; stNum < s.Length; stNum++)
    {
          alphaCount[s[stNum]]++;
    }

    if(s.Length % 2 == 0)
    {
    isPossible = true;
      for(long i = 0; i < 26; i++)
      {
        if(alphaCount[i] % 2 == 1) isPossible = false;
      }
    }else
    {
    long addMemo = 0;
    isPossible = false;
      for(long i = 0; i < 26; i++)
      {
      if(alphaCount[i] % 2 == 1)
        {
          addMemo++;
          oddMemo = alphaCount[i];
        }
      }
    if(addMemo == 1) isPossible = true;
    }

    if(!(isPossible))
    {
		Console.WriteLine(-1);
    }else
    {
      writeNum = 1;
    
    //Console.WriteLine(alphaCount[0]+" "+alphaCount[1]);
      for(long stNum = 0; stNum < s.Length; stNum++)
      {
        if(lookedAlphaCount[s[stNum]] < alphaCount[s[stNum]]/2)
          {
          lookedAlphaCount[s[stNum]]++;
          origiStringNums[stNum] = writeNum;
          writeNum++;
          }else if(alphaCount[s[stNum]] % 2 == 1 && 
            lookedAlphaCount[s[stNum]] == (alphaCount[s[stNum]]-1)/2)
          {
            lookedAlphaCount[s[stNum]]++;
            origiStringNums[stNum] = s.Length / 2 + 1;
          }
      }
    //Console.WriteLine(origiStringNums[0]+" "+origiStringNums[1]+" "+origiStringNums[2]);
    if(s.Length % 2 == 1) writeNum++;

      for(long i = 0; i < 26; i++)
      {
        leftMemo[i] = new long[alphaCount[i]/2+3];//????????????
      }

      for(long stNum = 0; stNum < s.Length; stNum++)
      {
        if(origiStringNums[stNum] != 0)
          {
            leftMemo[s[stNum]][leftMemo[s[stNum]][0]+1] = origiStringNums[stNum];
            leftMemo[s[stNum]][0]++;
          }
      }

      for(long i = 0; i < 26; i++)
      {
        if(alphaCount[i] % 2 == 1)
        {
          leftMemo[i][0]--;
        }
      }

    for(long stNum = 0; stNum < s.Length; stNum++)//??????
      {
      if(origiStringNums[stNum] == 0)
        {
          origiStringNums[stNum] = 
            s.Length - leftMemo[s[stNum]][leftMemo[s[stNum]][0]] + 1;
          leftMemo[s[stNum]][0]--;
        }
      }
      //Console.WriteLine(origiStringNums[0]+" "+origiStringNums[1]+" "+origiStringNums[2]);

/*
    Console.WriteLine(origiStringNums[0]+" "+origiStringNums[1]+" "+origiStringNums[2]
      +" "+origiStringNums[3]+" "+origiStringNums[4]+" "+origiStringNums[5]
      +" "+origiStringNums[6]+" "+origiStringNums[7]);
*/

    long answer = 0;
    for(long i = 0; i < s.Length; i++)
      {
      answer += i - BitSum(origiStringNums[i]);
      BitAdd(origiStringNums[i], 1);
      }
    
		  Console.WriteLine(answer);
    }
	}



  static void BitAdd(long i, long x)//BIT?i???x??
{
  while(i <= s.Length)
  {
    bits[i] += x;
    i += i&-i;
  }
}

static long BitSum(long i)//BIT?i????????
{
  long sum = 0;
  while(i > 0)
  {
    sum += bits[i];
    i -= i&-i;
  }
  return sum;
}
}