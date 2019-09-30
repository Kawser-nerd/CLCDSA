import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble() / 100.0;
		double y = sc.nextDouble();
		double ans = y * Math.pow(x, 2);
		System.out.printf("%.5f\n", ans);
	}
}