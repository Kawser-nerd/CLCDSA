using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int n=int.Parse(Console.ReadLine());
		int[][] a=new int[n+2][];
		long d,e;
		double ans=0;
		a[0]=new int[]{s[0],s[1],0};
		a[n+1]=new int[]{s[2],s[3],0};
		double[,] h=new double[n+2,n+2];
		bool[] b=new bool[n+2];
		for(int i=1;i<=n;i++){
			a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=i-1;j>=0;j--){
				d=Math.Abs(a[i][0]-a[j][0]);
				e=Math.Abs(a[i][1]-a[j][1]);
				h[i,j]=Math.Sqrt(d*d+e*e)-a[i][2]-a[j][2];
				h[i,j]=Math.Max(h[i,j],0);
				h[j,i]=h[i,j];
			}
		}
		for(int j=n;j>=0;j--){
			d=Math.Abs(a[n+1][0]-a[j][0]);
			e=Math.Abs(a[n+1][1]-a[j][1]);
			h[n+1,j]=Math.Sqrt(d*d+e*e)-a[n+1][2]-a[j][2];
			h[n+1,j]=Math.Max(h[n+1,j],0);
			h[j,n+1]=h[n+1,j];
		}

		b[0]=true;
		for(int j=1;j<=n+1;j++){hea(h[0,j],j);}
		while(he.Count>0){
			int q=(int)he[0][1];
			if(!b[q]){
				b[q]=true;
				if(q==n+1){
					ans=he[0][0];
					break;
				}
				for(int j=1;j<=n+1;j++){
					if(!b[j]){hea(he[0][0]+h[q,j],j);}
				}
			}
			her();
		}
		Console.WriteLine(ans);
	}
	static List<double[]> he=new List<double[]>();
	static void hea(double a,int b){
		he.Add(new double[]{a,b});
		int j=he.Count-1;
		while(he[j][0]<he[(j-1)/2][0]){//
			double v=he[j][0];he[j][0]=he[(j-1)/2][0];he[(j-1)/2][0]=v;
			v=he[j][1];he[j][1]=he[(j-1)/2][1];he[(j-1)/2][1]=v;
			j=(j-1)/2;
		}
	}
	static void her(){
		he[0]=he[he.Count-1];
		he.RemoveAt(he.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he.Count){
				if(he[j*2+1][0]<he[j*2+2][0]){j=j*2+1;}//
				else{j=j*2+2;}
			}
			else if(j*2+1<he.Count){j=j*2+1;}
			else{break;}
			if(he[j][0]>=he[(j-1)/2][0]){break;}//
			double v=he[j][0];he[j][0]=he[(j-1)/2][0];he[(j-1)/2][0]=v;
			v=he[j][1];he[j][1]=he[(j-1)/2][1];he[(j-1)/2][1]=v;
		}
	}
}