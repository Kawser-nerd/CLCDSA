using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    string alphabets = "abcdefghijklmnopqrstuvwxyz";//26??
    int n = s.Length;
		long answer = 1000;
    long answerMemo = 0;
    long answerMemoMax = 0;
    
    for(int i = 0; i < 26; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(s[j] == alphabets[i])
        {
          answerMemoMax = Math.Max(answerMemoMax, answerMemo);
          answerMemo = 0;
        }else
        {
          answerMemo++;
        }
        answerMemoMax = Math.Max(answerMemoMax, answerMemo);
      }
      //Console.WriteLine(i + " " +answerMemoMax);
      answer = Math.Min(answer, answerMemoMax);
      answerMemo = 0;
      answerMemoMax = 0;
    }

    
		Console.WriteLine(answer);
	}
}