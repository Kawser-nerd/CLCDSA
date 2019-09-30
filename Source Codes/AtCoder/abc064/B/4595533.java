import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = reader.nextInt();
		}
		Arrays.sort(a);
		int ans = Math.abs(a[N-1]-a[0]);

		reader.close();
		System.out.print(ans);
	}
}