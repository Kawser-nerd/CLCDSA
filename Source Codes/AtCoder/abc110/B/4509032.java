import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();

		for (int i = 0; i < n; i++) {
			x = Math.max(x, sc.nextInt());
		}
		for (int i = 0; i < m; i++) {
			y = Math.min(y, sc.nextInt());
		}

		System.out.println(x < y ? "No War" : "War");

		sc.close();
	}

}