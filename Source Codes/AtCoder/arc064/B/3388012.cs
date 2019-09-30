using System;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		Console.WriteLine((s[0]==s[s.Length-1]&&s.Length%2==0)||(s[0]!=s[s.Length-1]&&s.Length%2==1)?"First":"Second");
	}
}