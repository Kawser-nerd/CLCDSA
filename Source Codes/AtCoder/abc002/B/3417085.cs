using System;
class Program
{
	static void Main(string[] args)
	{
		// ?????
		string r=Console.ReadLine();
		string o="";
		for(int i=0;i<r.Length;i++){
			if(r[i]!='a'&&r[i]!='e'&&r[i]!='i'&&r[i]!='o'&&r[i]!='u')
			o+=r[i];
		}
		
		//??
		Console.WriteLine(o);
	}
}