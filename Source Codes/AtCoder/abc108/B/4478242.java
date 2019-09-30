import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();

		int subX = Math.abs(x1 - x2);
		int subY = Math.abs(y1 - y2);

		int x3, y3, x4, y4;

		if (x1 >= x2) {
			if (y1 <= y2) {
				x3 = x2 - subY;
				y3 = y2 - subX;
				x4 = x1 - subY;
				y4 = y1 - subX;
			} else {
				x3 = x2 + subY;
				y3 = y2 - subX;
				x4 = x1 + subY;
				y4 = y1 - subX;
			}
		} else {
			if (y1 >= y2) {
				x3 = x2 + subY;
				y3 = y2 + subX;
				x4 = x1 + subY;
				y4 = y1 + subX;
			} else {
				x3 = x2 - subY;
				y3 = y2 + subX;
				x4 = x1 - subY;
				y4 = y1 + subX;
			}
		}

		System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
		sc.close();
	}
}