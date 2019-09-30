using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		string ans="YES";
		long o=a[n-1],t=n;
		long[] h=new long[n];
		for(int i=0;i<n-1;i++){
			t+=i+1;
			o+=a[i];
			h[i]=a[i+1]-a[i];
		}
		h[n-1]=a[0]-a[n-1];
		if(o%t!=0){ans="NO";}
		else{
			o/=t;
			t=0;
			for(int i=0;i<n;i++){
				if(h[i]>o){ans="NO";break;}
				h[i]=Math.Abs(h[i]-o);
				if(h[i]%n!=0){ans="NO";break;}
				t+=h[i]/n;
			}
			if(o!=t){ans="NO";}
		}
		Console.WriteLine(ans);
	}
}