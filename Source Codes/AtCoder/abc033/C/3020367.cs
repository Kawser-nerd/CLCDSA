using System;
class Program{
	static void Main(){
		string s=Console.ReadLine()+"+";
		int a=0;
		bool b=false;
		for(int i=0;i<s.Length;i++){
			if(s[i].ToString()=="+"){
				if(!b){a++;}
				b=false;
			}
			else if(s[i].ToString()=="0"){b=true;}
		}
		Console.WriteLine("{0}",a);
	}
}