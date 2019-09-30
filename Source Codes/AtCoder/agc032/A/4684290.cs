using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());
    List<int> numsList = new List<int>();
		int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
    int[] answers = new int[n];
    bool answerExist = false;

    for(int i = 0; i < n; i++)
    {
      numsList.Add(nums[i]);
    }

    for(int i = 0; i < n; i++)
    {
      answerExist = false;
      for(int j = n-1-i; j >= 0; j--)
      {
        if(numsList[j] == j+1)
        {
          answers[n-1-i] = j+1;
          //Console.WriteLine(j+1);
          answerExist = true;
          numsList.RemoveAt(j);
          break;
        }
      }
      if(!answerExist)
      {
        break;
      }
    }

    if(answerExist)
    {
      var answerText = new StringBuilder();
      for(long i = 0; i < answers.Length; i++)
      {
        answerText.AppendLine(answers[i].ToString());
      }
      Console.Write(answerText);
    }else Console.Write(-1);
    
	}
}