import java.io.*;
import java.util.Scanner;
import java.util.Locale;


class B {
	static double D;
	static int N,A;
	static double[] t = new double[2000];
	static double[] x = new double[2000];
	static double[] a = new double[250];
	
	
	static double solve1(double a){ // egyszerű szabadesés
		double opt = Math.sqrt((2*D)/(a));	
	
		return opt;
	}
	
	
	static double solve2(double a){ // parabola és egyenes metszéspontja
		double opt;
		double opt0 = Math.sqrt((2*D)/(a));	
		double car;
		if(x[0] >= D) opt = opt0;
		else {
			car = (D-x[0])*t[1]/(x[1]-x[0]);
			if(car <= opt0) opt = opt0;
			else opt = car;
		}
		return opt;
	}
	
	static String solve(){
		double opt;
		String answer = "";
		for(int i=0; i<A; i++){
			if(N == 1)
				opt = solve1(a[i]);
			else
				opt = solve2(a[i]);
			answer += "\n"+String.format(Locale.US,"%.8f",opt);
		}
		return answer;
	}
	
	public static void main(String args[]) throws IOException {

		//Scanner be = new Scanner(new FileReader("B-test.in"));
		Scanner be = new Scanner(new FileReader("B-small.in"));
		//Scanner be = new Scanner(new FileReader("B-large.in"));
		//BufferedWriter ki = new BufferedWriter(new FileWriter("B-test.out"));
		BufferedWriter ki = new BufferedWriter(new FileWriter("B-small.out"));
		//BufferedWriter ki = new BufferedWriter(new FileWriter("B-large.out"));
		int T = be.nextInt();
		
		be.useLocale(Locale.US);
		for(int i=1; i<= T; i++){
			
			D = be.nextDouble();
			N = be.nextInt();
			A = be.nextInt();
			for(int j = 0; j< N; j++){
				t[j] = be.nextDouble();
				x[j] = be.nextDouble();
			}
			
			for(int j = 0; j< A; j++){
				a[j] = be.nextDouble();
			}
			
			
			System.out.println("Case #"+i+": "+solve());
			ki.write("Case #"+i+": "+solve()+"\n");
			
		}
		be.close();
		ki.close();
	}
}
