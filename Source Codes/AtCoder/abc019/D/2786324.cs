using System;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int a=0,b,n2=2;
		for (int i=2;i<=s;i++){
			Console.WriteLine("? {0} {1}",1,i);
			b=int.Parse(Console.ReadLine());
			if(a<b){a=b;n2=i;}
		}
		for (int i=2;i<=s;i++){
			if(n2!=i){
				Console.WriteLine("? {0} {1}",n2,i);
				b=int.Parse(Console.ReadLine());
				if(a<b){a=b;}
			}
		}
		Console.WriteLine("! {0}",a);
	}
}