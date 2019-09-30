using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		double[][] arr=new double[s[0]][];
		for(int i=0;i<s[0];i++){arr[i]=Array.ConvertAll((Console.ReadLine()+" 0").Split(),double.Parse);}
		double ok=0,ng=100,mid=0,a=0;

		while(true){
			mid=(ok+ng)/2;
			for(int i=0;i<s[0];i++){arr[i][2]=arr[i][0]*(arr[i][1]-mid);}
			Array.Sort(arr,ca);
			for(int i=0;i<s[1];i++){a+=arr[i][2];}
			if(a>=0){ok=mid;}
			else{ng=mid;}
			if(ng-ok<1e-11){break;}
			a=0;
		}
		Console.WriteLine("{0}",mid);
	}
	static int ca(double[] a,double[] b){
		if(a[2]<b[2]){return 1;}
		else if(a[2]>b[2]){return -1;}
		if(a[0]<b[0]){return 1;}
		else if(a[0]>b[0]){return -1;}
		else{return 0;}
	}
}