using System;
class Program{
	static void Main(){
		const int mod=1000000007;
		int n=int.Parse(Console.ReadLine()),i=0;
		string[] arr=new string[]{Console.ReadLine(),Console.ReadLine()};
		long ans=1;
		bool? b=null;
		while(i<n){
			if(arr[0][i]==arr[1][i]){
				if(b==false){ans=(ans*2)%mod;}
				else if(b==null){ans=(ans*3)%mod;}
				i++;
				b=false;
			}
			else{
				if(b==false){ans=(ans*2)%mod;}
				else if(b==true){ans=(ans*3)%mod;}
				else{ans=(ans*6)%mod;}
				i+=2;
				b=true;
			}
		}
		Console.WriteLine("{0}",ans);
	}
}