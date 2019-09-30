import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int r = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();
		int x3 = sc.nextInt();
		int y3 = sc.nextInt();
		double w1 = Math.pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
		double w2 = Math.pow((x1 - x3) * (x1 - x3) + (y1 - y2) * (y1 - y2), 0.5);
		double w3 = Math.pow((x1 - x2) * (x1 - x2) + (y1 - y3) * (y1 - y3), 0.5);
		double w4 = Math.pow((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3), 0.5);
		if(w1 <= r && w2 <= r && w3 <= r && w4 <= r) {
			System.out.println("YES");
			System.out.println("NO");
		} else if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3) {
			System.out.println("NO");
			System.out.println("YES");
		} else {
			System.out.println("YES");
			System.out.println("YES");
		}
	}
}