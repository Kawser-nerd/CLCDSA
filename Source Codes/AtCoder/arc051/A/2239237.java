import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt(),y1 = sc.nextInt(), r = sc.nextInt();
		int x2 = sc.nextInt(),y2 = sc.nextInt(), x3 = sc.nextInt(), y3 = sc.nextInt();
		if(x1-r >= x2 && x1+r <= x3 &&  y1-r >= y2 && y1+r <= y3) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
		if(Math.hypot(x2-x1, y2-y1) <= r && Math.hypot(x2-x1, y3-y1) <= r && Math.hypot(x3-x1, y2-y1) <= r && Math.hypot(x3-x1, y3-y1) <= r) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}