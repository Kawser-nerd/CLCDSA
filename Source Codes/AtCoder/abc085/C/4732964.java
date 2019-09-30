import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Y = sc.nextInt();
		sc.close();
		for (int x = 0; x <= N; x++) {
			for (int y = 0; y <= N - x; y++) {
				if (10000 * x + 5000 * y + (N - x - y) * 1000 == Y) {
					System.out.println(x + " " + y + " " + (N - x - y));
					return;
				}
			}
		}
		System.out.println("-1 -1 -1");
	}
}