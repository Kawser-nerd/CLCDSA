import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class C {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	int n;
	double[]P;
	double[]X;
	double[]Y;
	double[]Z;
	
	double val(double px, double py, double pz){
		double res =0;
		for(int i=0;i<n;i++){
			double r = abs(X[i]-px)+abs(Y[i]-py)+abs(Z[i]-pz);
			r/=P[i];
			res = max(res,r);
		}
		return res;
	}
	
	
	
	double solve(){
		double res=0;
		n = scan.nextInt();
		double mx = 1000000,Mx=0;
		double my = 1000000,My=0;
		double mz = 1000000,Mz=0;
		P = new double[n];
		X = new double[n];
		Y = new double[n];
		Z = new double[n];
		for(int i=0;i<n;i++){
			X[i]=scan.nextInt();
			Y[i]=scan.nextInt();
			Z[i]=scan.nextInt();
			P[i]=scan.nextDouble();
			mx = min(mx, X[i]);Mx=max(Mx,X[i]);
			my = min(my, Y[i]);Mx=max(My,Y[i]);
			my = min(mz, Z[i]);Mx=max(Mz,Z[i]);
		}
		double px=0,py=0,pz=0;
		res = 10000000;
		Random r = new Random();
		for(int i=0;i<100000;i++){
			double a = r.nextDouble();
			double b = r.nextDouble();
			double c = r.nextDouble();
			double tx = mx + a*(Mx-mx);
			double ty = my + b*(My-my);
			double tz = mz + c*(Mz-mz);
			double t = val(tx,ty,tz);
			if(t<res){
				res = t;
				px=tx;py=ty;pz=tz;
			}
		}
		double p = 200000;
		for(int i=0;i<100000;i++){
			for(int a =-1;a<2;a++)for(int b=-1;b<2;b++)for(int c =-1;c<2;c++){
				double tx = px + a*p;
				double ty = py + b*p;
				double tz = pz + c*p;
				double t = val(tx,ty,tz);
				if(t<res){
					res = t;
					px=tx;py=ty;pz=tz;
				}
			}
			p = p*0.999;
		}
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			double r =solve();
			System.out.format("Case #%d: %f\n",i+1,r);
		}
	}
	
	C() throws Exception{
		in = new BufferedInputStream(new FileInputStream("C-large.in"));
		//in = new BufferedInputStream(new FileInputStream("C.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new C().solveAll();
	}

}
