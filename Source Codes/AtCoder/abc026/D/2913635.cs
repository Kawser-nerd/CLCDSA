using System;
class Program{
	static void Main(){
		double[] s=Array.ConvertAll(Console.ReadLine().Split(),double.Parse);
		double t=102,h=102,l=0;
		double a=101;
		
		while(Math.Abs(100-a)>0.000001){
			if(a>100){h=t;}
			else{l=t;}
			t=(h+l)/2;
			a=s[0]*t+s[1]*Math.Sin(s[2]*t*Math.PI);
		}
		Console.WriteLine("{0}",t);
	}
}