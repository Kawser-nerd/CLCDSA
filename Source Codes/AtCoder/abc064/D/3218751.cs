using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string s=Console.ReadLine();
		int a=0,b=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){b++;}
			else if(s[i]==')'&&b==0){a++;}
			else{b--;}
		}
		Console.WriteLine("{0}",new string('(',a)+s+new string(')',b));
	}
}