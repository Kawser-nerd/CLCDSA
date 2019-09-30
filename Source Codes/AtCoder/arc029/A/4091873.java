import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int t[] = new int[N];
		for (int i = 0; i < N; i++) {
			t[i] = sc.nextInt();
		}

		Arrays.sort(t);
		int n1 = t[N-1];
		int n2 = 0;
		for (int i = 1; i < N; i++) {
			if (n1 > n2) {
				n2 += t[N-i-1];
			} else {
				n1 += t[N-i-1];
			}
		}
		System.out.println(Math.max(n1, n2));
	}
}