import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		int n = 3 * N;
		long[] a = new long[n];
		String[] s = sc.nextLine().split(" ");
		sc.close();
		for(int i = 0; i < n; i++) {
			a[i] = Long.parseLong(s[i]);
		}
		Arrays.sort(a);
		long sum = 0;
		for(int i = 0; i < N; i++) {
			sum += a[n - 2 * i - 2];
		}
		System.out.println(sum);
	}
}