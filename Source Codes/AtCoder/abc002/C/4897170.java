import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double x1 = sc.nextDouble();
		double y1 = sc.nextDouble();
		double x2 = sc.nextDouble();
		double y2 = sc.nextDouble();
		double x3 = sc.nextDouble();
		double y3 = sc.nextDouble();
		System.out.println(Math.abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2D);
	}

}