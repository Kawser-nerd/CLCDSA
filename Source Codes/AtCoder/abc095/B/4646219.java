import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int X = reader.nextInt();
		int[] M = new int[N];
		int ans = N;
		for (int i = 0; i < N; i++) {
			M[i] = reader.nextInt();
			X -= M[i];
		}
		Arrays.sort(M);
		ans += X / M[0];
		reader.close();
		System.out.print(ans);
	}
}