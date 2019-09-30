using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static double phi=(1+Math.Sqrt(5))*0.5;
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[][] a=new int[n][];
		double xh=int.MinValue,yh=int.MinValue,xl=int.MaxValue,yl=int.MaxValue;
		for(int i=0;i<n;i++){
			a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			xh=Math.Max(xh,a[i][0]);
			yh=Math.Max(yh,a[i][1]);
			xl=Math.Min(xl,a[i][0]);
			yl=Math.Min(yl,a[i][1]);
		}
		double xc1=0,xc2=0,xd1=0,xd2=0,yc1=0,yc2=0,yd1=0,yd2=0;
		xc1=(xl*phi+xh)/(1+phi);
		xc2=(xl+phi*xh)/(1+phi);
		yc1=(yl*phi+yh)/(1+phi);
		yc2=(yl+phi*yh)/(1+phi);
		while(xh-xl>1e-9&&yh-yl>1e-9){
			xd1=0;xd2=0;yd1=0;yd2=0;
			for(int i=0;i<n;i++){
				xd1=Math.Max(xd1,Math.Abs(xc1-a[i][0])*a[i][2]);
				xd2=Math.Max(xd2,Math.Abs(xc2-a[i][0])*a[i][2]);
				yd1=Math.Max(yd1,Math.Abs(yc1-a[i][1])*a[i][2]);
				yd2=Math.Max(yd2,Math.Abs(yc2-a[i][1])*a[i][2]);
			}
			if(xd1>xd2){xl=xc1;xc1=xc2;xc2=(xl+phi*xh)/(1+phi);}
			else{xh=xc2;xc2=xc1;xc1=(xl*phi+xh)/(1+phi);}
			if(yd1>yd2){yl=yc1;yc1=yc2;yc2=(yl+phi*yh)/(1+phi);}
			else{yh=yc2;yc2=yc1;yc1=(yl*phi+yh)/(1+phi);}
		}
		Console.WriteLine("{0}",Math.Max(xd1,yd1));
	}
}