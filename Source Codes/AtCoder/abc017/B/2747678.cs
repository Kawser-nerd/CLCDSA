using System;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		s+="x";
		string a="YES";
		if(s!=""){
			for (int i=0;i<s.Length-1;i++){
				if(s[i].ToString()=="c"&&s[i+1].ToString()=="h"){i++;}
				else if(s[i].ToString()=="o"){}
				else if(s[i].ToString()=="k"){}
				else if(s[i].ToString()=="u"){}
				else{a="NO";break;}
			}
		}
		Console.WriteLine(a);
	}
}