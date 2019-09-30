using System;
class Program{
	static void Main(){
		long s=1+long.Parse(Console.ReadLine());
		bool b=true;
		while(s>3){
			if(b){s=s/2+(s&1);}
			else{s=s/2;}
			b=!b;
		}
		if(s==3){Console.WriteLine("Takahashi");}
		else if(b==true){Console.WriteLine("Aoki");}
		else{Console.WriteLine("Takahashi");}
	}
}