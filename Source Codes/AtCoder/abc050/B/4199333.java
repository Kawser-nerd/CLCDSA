import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[] t = new int[sc.nextInt()];

		int sum = 0;
		for (int i = 0; i < t.length; i++) {
			sum += t[i] = sc.nextInt();
		}

		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
			int p = sc.nextInt(), x = sc.nextInt();
			System.out.println(sum - (t[p - 1] - x));
		}
		sc.close();
	}
}