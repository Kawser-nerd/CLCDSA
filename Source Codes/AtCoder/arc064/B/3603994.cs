using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    int n = s.Length;
    bool firstWin = true;
    if(n%2==1 && s[0]==s[n-1] || n%2==0 && s[0]!=s[n-1]) firstWin = false;
		
		Console.WriteLine((firstWin) ? "First" : "Second");
	}
}