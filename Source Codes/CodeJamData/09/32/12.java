package googlejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.*;

public class CenterofMass {


	public static void main(String[] args) throws Exception
	{
		BufferedReader in=new BufferedReader(new FileReader("c:\\B-large.in.txt"));
		PrintWriter pr=new PrintWriter(new FileWriter("C:\\blarge.txt"));
		
        int T=Integer.parseInt(in.readLine().trim());
		
		for(int i=0;i<T;i++)
		{
			int N=Integer.parseInt(in.readLine().trim());
			double[]x=new double[N];
			double[]y=new double[N];
			double[]z=new double[N];
			double[]vx=new double[N];
			double[]vy=new double[N];
			double[]vz=new double[N];
			
			for(int j=0;j<N;j++)
			{
				String[]t=in.readLine().trim().split("[ ]+");
				x[j]=Double.parseDouble(t[0]);
				y[j]=Double.parseDouble(t[1]);
				z[j]=Double.parseDouble(t[2]);
				vx[j]=Double.parseDouble(t[3]);
				vy[j]=Double.parseDouble(t[4]);
				vz[j]=Double.parseDouble(t[5]);
			}
			
			Result r=solve(x,y,z,vx,vy,vz);
			
			pr.println("Case #"+(i+1)+": "+r.d+" "+r.t);
		}
		pr.close();
	}
	
	public static Result solve(double[]x,double[]y,double[]z,double[]vx,double[]vy,double[]vz)
	{
		double ax,bx,ay,by,az,bz,a,b,c;
		ax=mean(vx);
		bx=mean(x);
		ay=mean(vy);
		by=mean(y);
		az=mean(vz);
		bz=mean(z);
		
		a=ax*ax+ay*ay+az*az;
		b=(ax*bx+ay*by+az*bz)*2;
		c=bx*bx+by*by+bz*bz;
		
		Result r=new Result();
		r.t=0;
		r.d=c;
	
		//System.out.println(a+" "+b+" "+c);
		
		double t=-b/(2*a);
		double d=(4*a*c-b*b)/(4*a);
		
	//	System.out.println(a+" "+b+" "+c+" "+t+" "+d);
		if(d<c&&t>0&&a>0)
		{
			//System.out.println("AAA");
			r.t=t;
			r.d=d;
		}
		if(r.d<0)
			r.d=0;
		r.d=Math.sqrt(r.d);
			
		return r;
	}
	
	public static double mean(double[]m)
	{
		double result=0;
		for(int i=0;i<m.length;i++)
			result=result+m[i];
		return result/m.length;
	}
}

class Result{
	double d;
	double t;
}