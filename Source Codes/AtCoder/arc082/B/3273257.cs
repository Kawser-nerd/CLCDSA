using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int ans=0;
		for(int i=0;i<n-1;i++){
			if(s[i]==i+1){
				int v=s[i];
				s[i]=s[i+1];
				s[i+1]=v;
				i++;
				ans++;
			}
		}
		if(s[n-1]==n){
			int v=s[n-1];
			s[n-1]=s[n-2];
			s[n-2]=v;
			ans++;
		}
		Console.WriteLine("{0}",ans);
	}
}