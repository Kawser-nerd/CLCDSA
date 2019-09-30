using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	string s = Console.ReadLine();
  int k = int.Parse(Console.ReadLine());

  List<string> checkList = new List<string>();

    for(int i = 0; i < k; i++)
    {
      for(int j = 0; j < s.Length - i; j++)
      {
        //Console.WriteLine(s.Substring(j, i+1));
        checkList.Add(s.Substring(j, i+1));//j?????i??
      }
    }

    checkList.Sort((a, b) => a.CompareTo(b));//???

    string memo = "aaaaaa";
    long check = 0;
    
      for(int i = 0; i < checkList.Count(); i++)
      {
        if(checkList[i] != memo) 
        {
          check ++;
          if(check == k) Console.WriteLine(checkList[i]);
          memo = checkList[i];
        }
      }
    
      
	}
}