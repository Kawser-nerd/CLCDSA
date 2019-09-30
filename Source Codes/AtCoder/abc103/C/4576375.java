import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int[] a = new int[N];
		int ans = 0;
		int[] M = new int[N];

		for (int i = 0; i < N; i++) {
			ans += reader.nextInt() -1;
		}

		reader.close();
		System.out.print(ans);
	}
}