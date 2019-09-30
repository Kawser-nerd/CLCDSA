import java.util.*;
public class Main{
	static Scanner sn = new Scanner(System.in);
	static int N = sn.nextInt();
	static double[] x = new double[1002];
	static double[] y = new double[1002];
	static double[] c = new double[1002];
	public static void main(String[] args){		
		for(int i = 0; i < N; ++i){
			x[i] = sn.nextDouble();
			y[i] = sn.nextDouble();
			c[i] = sn.nextDouble();			
		}
		double l = 0, h = Math.pow(10,9);
		for(int i = 0; i < 100; ++i){
			double m = (l + h)/2;
			if(solve(m)) h = m;
			else l = m;
		}
		System.out.printf("%.10f\n",h);
	}
	
	public static boolean solve(double r){
		for(int i = 0; i < N; ++i)
			for(int j = i+1; j < N; ++j){
				double dy = Math.abs(y[i] - y[j]);
				if(dy > r/c[i] + r/c[j]) return false;
				double dx = Math.abs(x[i] - x[j]);
				if(dx > r/c[i] + r/c[j]) return false;
			}
		return true;
	}
}