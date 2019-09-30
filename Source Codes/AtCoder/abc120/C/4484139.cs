using System;
public class c
{
  public static void Main()
  {
    string S = Console.ReadLine();
    int count_0 = 0;
    int count_1=0;
    string s= "";
    for(int i=0;i<S.Length;i++)
    {
      if(S[i]=='0')count_0++;
      else count_1++;
    }
    if(count_1>=count_0)Console.WriteLine(count_0*2);
    else Console.WriteLine(count_1*2);
   
    
  }
}