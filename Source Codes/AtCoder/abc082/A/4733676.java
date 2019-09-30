import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		double a;
		double b;
		double x;
		Scanner sc = new Scanner(System.in);
		a = sc.nextDouble();
		b = sc.nextDouble();
		x = (a + b) / 2;
		x = Math.ceil(x);
		System.out.println((int)x);
		sc.close();
	}

}