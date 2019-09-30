using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string s=Console.ReadLine();
		string[] a=new string[]{"AA","AB","AX","AY","BA","BB","BX","BY","XA","XB","XX","XY","YA","YB","YX","YY"};
		int ans=0;
		for(int i=0;i<15;i++){
			for(int j=i;j<16;j++){
				int q=0;
				for(int k=0;k<n-1;k++){
					if(s[k]==a[i][0]&&s[k+1]==a[i][1]){k++;q++;}
					else if(s[k]==a[j][0]&&s[k+1]==a[j][1]){k++;q++;}
				}
				ans=Math.Max(ans,q);
			}
		}
		Console.WriteLine("{0}",n-ans);
	}
}