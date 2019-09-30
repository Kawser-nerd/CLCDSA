using System;
class Program
{
  static void Main()
  {
    string S = Console.ReadLine();
    while(S.Length > 0){
      int L = S.Length;
      if(L >= 2)
      {
        if(S.Substring(L - 2) == "ch")
        {
          S = S.Replace(S.Substring(L - 2), "");
        }
        if(S.Length == 0)
       {
      	Console.WriteLine("YES");
       	return;
       }
     }
      L = S.Length;
 	  if(S.Substring(L - 1) == "o")
      {
        S = S.Replace(S.Substring(L - 1), "");
      }
      else if(S.Substring(L - 1) == "k")
      {
        S = S.Replace(S.Substring(L - 1), "");
      }
      else if(S.Substring(L - 1) == "u")
      {
        S = S.Replace(S.Substring(L - 1), "");
      }
      else
      {
        Console.WriteLine("NO");
        return;
      }
    }
    Console.WriteLine("YES");
  }
}