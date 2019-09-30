using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string ans="NO";
		if(n%400==0){ans="YES";}
		else if(n%100==0){ans="NO";}
		else if(n%4==0){ans="YES";}
		Console.WriteLine(ans);
	}
}