using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[][] arr=new long[s[0]][];
		long a=0,b=0;
		for(int i=0;i<s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			a=Math.Max(a,arr[i][0]);
		}
		Array.Sort(arr,ca);
		for(int i=0;i<s[0]&&arr[i][1]>a&&s[1]>0;i++){
			s[1]-=arr[i][1];
			b++;
		}
		if(s[1]<=0){Console.WriteLine("{0}",b);}
		else{Console.WriteLine("{0}",s[1]/a+(s[1]%a==0?0:1)+b);}
	}
	static int ca(long[] a,long[] b){
		if(a[1]<b[1]){return 1;}
		else if(a[1]>b[1]){return -1;}
		else{return 0;}
	}
}