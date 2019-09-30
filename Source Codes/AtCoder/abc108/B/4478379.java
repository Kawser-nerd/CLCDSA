import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();

		int subX = x1 - x2;
		int subY = y1 - y2;


		System.out.println((x2 + subY) + " " + (y2 - subX) + " " + (x1 + subY) + " " + (y1 - subX));
		sc.close();
	}
}