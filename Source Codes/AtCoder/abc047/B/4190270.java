import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int minX = 0;
		int maxX = sc.nextInt();
		int minY = 0;
		int maxY = sc.nextInt();

		int n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int a = sc.nextInt();

			switch (a) {
			case 1:
				minX = Math.max(minX, x);
				break;
			case 2:
				maxX = Math.min(maxX,  x);
				break;
			case 3:
				minY = Math.max(minY, y);
				break;
			case 4:
				maxY = Math.min(maxY, y);
				break;
			}
		}
		int area = maxX > minX && maxY > minY ? (maxX - minX) * (maxY - minY) : 0;

		System.out.println(area);
	}
}