using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string[] a=new string[n];
		int ans=0;
		for(int i=0;i<n;i++){a[i]=Console.ReadLine();}
		bool b=true;
		for(int j=0;j<n-1&&b;j++){
			for(int k=j+1;k<n;k++){
				if(a[j][k]!=a[k][j]){b=false;break;}
			}
		}
		if(b){ans++;}
		for(int i=1;i<n;i++){
			for(int j=0;j<n;j++){
				a[j]+=a[j][0];
				a[j]=a[j].Remove(0,1);
			}
			b=true;
			for(int j=0;j<n-1&&b;j++){
				for(int k=j+1;k<n;k++){
					if(a[j][k]!=a[k][j]){b=false;break;}
				}
			}
			if(b){ans++;}
		}
		Console.WriteLine("{0}",ans*n);
	}
}