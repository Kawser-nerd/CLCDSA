import java.util.*;
public class Main{
	static Scanner sn = new Scanner(System.in);
	static double P = sn.nextDouble();
	
	public static void main(String[] args){		
		double r = P;
		double l = 0.0;
		double tol = Math.pow(10.0,-12);
		double ans = -1.0;
		while(Math.abs(ans - f((r + l)/2.0)) > tol){
			ans = f((r + l)/2.0);
			double x1 = l + (r - l)/3.0;
			double x2 = l + 2.0*(r - l)/3.0;			
			if(f(x1) > f(x2)){
				l = x1;
			}
			else{
				r = x2;
			}		
		}
		System.out.printf("%.12f\n",f((r+l)/2.0));
	}
	
	public static double f(double x){
		return x + P/Math.pow(2.0,x/1.5);
	}
}