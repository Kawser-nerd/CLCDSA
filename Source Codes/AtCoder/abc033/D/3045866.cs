using System;
class Program{
	static void Main(){
		long n=long.Parse(Console.ReadLine());
		int [][] arr=new int[n][];
		double [] r=new double[n];
		double [] q=new double[(n-1)*2];
		long sg=0,ct=0,et=0,ac=0,ad=0;
		const double eps=1e-12;
		for(int i=0;i<n;i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		}
		double c=Math.Atan2(1,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				r[j]=Math.Atan2(arr[j][0]-arr[i][0],arr[j][1]-arr[i][1]);
			}
			r[i]=-100;
			Array.Sort(r);
			sg=0;et=0;ct=0;
			for(int j=0;j<n-1;j++){
				q[j]=r[j+1];
				q[j+n-1]=r[j+1]+Math.PI+Math.PI;
			}
			for(int j=1;j<n*2;j++){
				while(q[j]-q[sg]>c-eps&&sg<n-1){
					if(q[j]-q[sg]<c+eps){ct++;}
					sg++;
				}
				if(sg>=n-1){break;}
				et+=j-sg;
				if(j>=n){et-=j-(n-1);}
			}
			ac+=ct;
			ad+=(n-1)*(n-2)/2-et-ct;
		}
		Console.WriteLine("{0} {1} {2}",n*(n-1)*(n-2)/6-ac-ad,ac,ad);
	}
}