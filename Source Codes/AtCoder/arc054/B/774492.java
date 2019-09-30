import java.util.Scanner;

public class Main {

	double P;
	public static void main(String[] args) {
		new Main().run();
	}
	
	public void run() {
		Scanner sc = new Scanner(System.in);
		
		P = sc.nextDouble();
		double max = P;
		double min = 0;
		double mid = (max + min) / 2;
		double tilt = fprime(mid);
		while(max - min > 0.000000000001) {
			if (tilt < 0) {
				min = mid;
			} else {
				max = mid;
			}
			mid = (max + min) / 2;
			tilt = fprime(mid);
		}
		System.out.println(f(mid));
		
		sc.close();
	}
	
	private double f(double x) {
		return x + P / Math.pow(2, x / 1.5);
	}
	
	private double fprime(double x) {
		double tmp = Math.pow(2, x / 1.5);
		return 1 - P * tmp * Math.log(2) / (tmp * tmp * 1.5);
	}
}