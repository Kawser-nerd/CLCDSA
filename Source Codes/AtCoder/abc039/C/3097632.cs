using System;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		string ans="";
		if(s[1].ToString()=="W"){
			if(s[6].ToString()=="W"){ans="Si";}
			else{ans="Mi";}
		}
		else if(s[3].ToString()=="W"){
			if(s[8].ToString()=="W"){ans="La";}
			else{ans="Re";}
		}
		else if(s[5].ToString()=="W"){
			if(s[10].ToString()=="W"){ans="So";}
			else{ans="Do";}
		}
		else{ans="Fa";}
		Console.WriteLine("{0}",ans);
	}
}