using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string[] s=new string[n];
		for(int i=0;i<n;i++){
			s[i]=Console.ReadLine();
			char[] c=s[i].ToCharArray();
			Array.Reverse(c);
			s[i]=new string(c);
		}
		Array.Sort(s);
		for(int i=0;i<n;i++){
			char[] c=s[i].ToCharArray();
			Array.Reverse(c);
			s[i]=new string(c);
		}
		Console.WriteLine(String.Join("\n",s));
	}
}