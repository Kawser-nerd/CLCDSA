import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int N = sc.nextInt();
		int K = sc.nextInt();

		int[] array = new int[N];

		for (int i = 0; i < N; i++) {
			array[i] = sc.nextInt();
		}
		Arrays.sort(array);

		int sum = 0;
		for (int i = N - 1, j = 0; j < K; i--, j++) {
			sum += array[i];
		}
		System.out.println(sum);
	}
}