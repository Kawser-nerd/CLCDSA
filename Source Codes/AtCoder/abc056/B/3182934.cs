using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		if(s[1]<s[2]){Console.WriteLine("{0}",s[2]-s[0]-s[1]<1?0:s[2]-s[0]-s[1]);}
		else{Console.WriteLine("{0}",s[1]-s[0]-s[2]<1?0:s[1]-s[0]-s[2]);}
	}
}