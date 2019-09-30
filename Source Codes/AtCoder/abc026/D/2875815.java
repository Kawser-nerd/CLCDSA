import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double A = scan.nextDouble();
		double B = scan.nextDouble();
		double C = scan.nextDouble();
		scan.close();
		double t0 = (B + 100 )/ A;
		double f0 = A * t0 + B * Math.sin(C * Math.PI * t0);
		//System.out.println(f0);
		// g(t) = At + B sin(C?t) - 100
		// dg / dt = A + BC?cos(C?t)
		double temp = t0;
		double t = 0;
		for(int i = 0; i < 1000; i++) {
			t = temp - (A * temp + B * Math.sin(C * Math.PI * temp) - 100)
					/ (A + B * C * Math.PI * Math.cos(C * Math.PI * temp));
			temp = t;
			double f = A * t + B * Math.sin(C * Math.PI * t);
			//System.out.println(f);
			if(Math.abs(f - 100) < 0.00000001) {
				break;
			}
		}
		System.out.println(t);
	}
}