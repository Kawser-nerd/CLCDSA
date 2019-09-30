using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int ans=0,b=0,c=0;
		for(int i=0;i<n;i++){b+=s[i];}
		if(b%n>0){ans=-1;}
		else{
			b/=n;
			for(int i=0;i<n-1;i++){
				if(s[i]!=b){c+=s[i]-b;}
				if(c!=0){ans++;}
			}
		}
		Console.WriteLine("{0}",ans);
	}
}