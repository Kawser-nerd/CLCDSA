import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int M = reader.nextInt();
		int X = reader.nextInt();
		int[] A = new int[N];
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 0; i < M; i++) {
			A[reader.nextInt()] = 1;
		}

		for (int i = X; i < N; i++) {
			ans1 += A[i];
		}
		for (int i = X; i > 0; i--) {
			ans2 += A[i];
		}
		System.out.println(Math.min(ans1, ans2));
		reader.close();
	}
}