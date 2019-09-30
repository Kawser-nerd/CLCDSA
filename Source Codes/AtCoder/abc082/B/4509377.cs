using System;
class Program
{
	static void Main(string[] args)
	{
		string s = Console.ReadLine();
		string t = Console.ReadLine();
      	char[] sChars = s.ToCharArray();
      	char[] tChars = t.ToCharArray();
        
        Array.Sort(sChars);
      	Array.Sort(tChars);
      	Array.Reverse(tChars);
      
      	string sPrimeStr = new String(sChars);
      	string tPrimeStr = new String(tChars);
      	
      	if(String.Compare(sPrimeStr, tPrimeStr) < 0)
          	Console.WriteLine("Yes");
      	else
          	Console.WriteLine("No");
	}
}