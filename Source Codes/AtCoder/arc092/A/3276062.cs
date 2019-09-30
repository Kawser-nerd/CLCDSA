using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int ans=0;
		int[][] a=new int[n][];
		int[][] b=new int[n][];
		for(int i=0;i<n;i++){a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		for(int i=0;i<n;i++){b[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		Array.Sort(a,ca1);
		Array.Sort(b,ca2);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(b[i][0]>a[j][0]&&b[i][1]>a[j][1]){
					a[j][0]=int.MaxValue;
					ans++;
					break;
				}
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static int ca1(int[] a,int[] b){
		if(a[1]<b[1]){return 1;}
		else if(a[1]>b[1]){return -1;}
		else if(a[0]<b[0]){return 1;}
		else if(a[0]>b[0]){return -1;}
		else{return 0;}
	}
	static int ca2(int[] a,int[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else if(a[1]>b[1]){return 1;}
		else if(a[1]<b[1]){return -1;}
		else{return 0;}
	}
}