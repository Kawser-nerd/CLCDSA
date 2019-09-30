using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		Array.Sort(s,(a,b)=>b-a);
		double c=double.MaxValue;
		int d=0;
		for(int i=1;i<n;i++){
			if(Math.Abs(s[0]/2.0-s[i])<c){
				c=Math.Abs(s[0]/2.0-s[i]);
				d=s[i];
			}
			else{break;}
		}
		Console.WriteLine("{0} {1}",s[0],d);
	}
}