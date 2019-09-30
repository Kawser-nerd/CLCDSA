import java.util.*;
import java.io.*;

public class Main{
	static int N;
	static int K;
	static double[] w;
	static double[] v;
	static double[] y;

	static boolean calc(double x){
		for(int i=0; i<N; i++){
			y[i] = 	v[i] - w[i]*x;
		}
		Arrays.sort(y);
		double sum = 0.0;
		for(int i=0; i<K; i++){
			sum += y[N - i - 1];
		}
		if(sum >= 0) return true;
		else return false;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		w = new double[N];
		v = new double[N];
		y = new double[N];
		
		for(int i=0; i<N; i++){
			w[i] = sc.nextInt();
			int p = sc.nextInt();
			v[i] = w[i] * p / 100.0;
		}

		double lb = 0.0;
		double ub = 1000.0;
		for(int loop=0; loop<100; loop++){
			double mid = (lb + ub)/2;
			if(calc(mid)) lb = mid;
			else ub = mid;
		}	
		System.out.println(lb*100.0);
	}
}