using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		if(s[0]+s[1]==s[2]&&s[0]-s[1]==s[2]){Console.WriteLine("?");}
		else if(s[0]+s[1]==s[2]){Console.WriteLine("+");}
		else if(s[0]-s[1]==s[2]){Console.WriteLine("-");}
		else{Console.WriteLine("!");}
	}
}