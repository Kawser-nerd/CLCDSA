import java.util.Scanner;


public class Main {

	private static double f(double P, double x) {
		return x + P / Math.pow(2, x / 1.5);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double P = sc.nextDouble();
		

		double left = 0;
		double right = Long.MAX_VALUE;
		
		for (int i = 0; i < 200; i ++) {
			double x1 = (left * 2 + right) / 3;
			double x2 = (left + right * 2) / 3;
			
			if (f(P, x1) > f(P, x2)) {
				left = x1;
			} else {
				right = x2;
			}
		}
		System.out.println(f(P,left));
	}
}