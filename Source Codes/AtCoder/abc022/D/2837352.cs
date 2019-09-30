using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		double[][] arr=new double[s][];
		List<int> li;
		List<int> lo;
		int a;
		double b,c,hl;
		double[] th=new double[2];
		
		for(int j=0;j<2;j++){

		li=new List<int>();
		lo=new List<int>();
		a=1;

		for(int i=0;i<s;i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}
		Array.Sort(arr,ca);
		hl=Math.Min(arr[0][1],arr[s-1][1]);
		li.Add(0);
		while(arr[a][1]<hl&&a<s-1){a++;}
		li.Add(a);
		a++;

		while(a<s){
			if(arr[a][1]>=hl){
				double tk=fu(arr[li[li.Count-2]][0],arr[li[li.Count-2]][1],arr[li[li.Count-1]][0],arr[li[li.Count-1]][1],arr[a][0],arr[a][1]);
				while(tk>0){
					li.RemoveAt(li.Count-1);
					if(li.Count>1){
						tk=fu(arr[li[li.Count-2]][0],arr[li[li.Count-2]][1],arr[li[li.Count-1]][0],arr[li[li.Count-1]][1],arr[a][0],arr[a][1]);}
					else{break;}
				}
				li.Add(a);
				if(tk==0){li.RemoveAt(li.Count-2);}
			}
			a++;
		}

		hl=Math.Max(arr[0][1],arr[s-1][1]);
		lo.Add(s-1);
		a=s-2;
		while(arr[a][1]>hl&&a>0){a--;}
		lo.Add(a);

		while(a>=0){
			if(arr[a][1]<=hl){
				double tk=fu(arr[lo[lo.Count-2]][0],arr[lo[lo.Count-2]][1],arr[lo[lo.Count-1]][0],arr[lo[lo.Count-1]][1],arr[a][0],arr[a][1]);
				while(tk>0){
					lo.RemoveAt(lo.Count-1);
					if(lo.Count>1){
						tk=fu(arr[lo[lo.Count-2]][0],arr[lo[lo.Count-2]][1],arr[lo[lo.Count-1]][0],arr[lo[lo.Count-1]][1],arr[a][0],arr[a][1]);}
					else{break;}
				}
				lo.Add(a);
				if(tk==0){lo.RemoveAt(lo.Count-2);}
			}
			a--;
		}
		
		for(int i=0;i<li.Count-1;i++){
			b=Math.Abs(arr[li[i]][0]-arr[li[i+1]][0]);
			c=Math.Abs(arr[li[i]][1]-arr[li[i+1]][1]);
			th[j]+=Math.Sqrt(b*b+c*c);
		}
		
		for(int i=0;i<lo.Count-1;i++){
			b=Math.Abs(arr[lo[i]][0]-arr[lo[i+1]][0]);
			c=Math.Abs(arr[lo[i]][1]-arr[lo[i+1]][1]);
			th[j]+=Math.Sqrt(b*b+c*c);
		}

		if(li[li.Count-1]!=lo[0]){
			b=Math.Abs(arr[li[li.Count-1]][0]-arr[lo[0]][0]);
			c=Math.Abs(arr[li[li.Count-1]][1]-arr[lo[0]][1]);
			th[j]+=Math.Sqrt(b*b+c*c);
		}
		if(lo[lo.Count-1]!=li[0]){
			b=Math.Abs(arr[lo[lo.Count-1]][0]-arr[li[0]][0]);
			c=Math.Abs(arr[lo[lo.Count-1]][1]-arr[li[0]][1]);
			th[j]+=Math.Sqrt(b*b+c*c);
		}

		}

		Console.WriteLine("{0}",th[1]/th[0]);
	}
	static double fu(double ax,double ay,double bx,double by,double cx,double cy){
		return (bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
	}
	static int ca(double[] a,double[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else if(a[1]<b[1]){return 1;}
		else if(a[1]>b[1]){return -1;}
		else{return 0;}
	}
}