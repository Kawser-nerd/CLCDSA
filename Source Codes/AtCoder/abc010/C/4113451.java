import java.util.*;

public class Main {
	static double x1;
	static double x2;
	static double y1;
	static double y2;
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		x1 = sc.nextInt();
		y1 = sc.nextInt();
		x2 = sc.nextInt();
		y2 = sc.nextInt();
		double t = sc.nextInt();
		double v = sc.nextInt();
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			if (t * v >= calc(sc.nextInt(), sc.nextInt())) {
				System.out.println("YES");
				return;
			}
		}
		System.out.print("NO");
	}
	
	static double calc(double x, double y) {
		return Math.sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) + Math.sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	}
}