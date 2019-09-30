import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		long answer = gcd(a[0], a[1]);
		for (int i = 0; i < N; i++) {
			answer = gcd(answer, a[i]);
		}
		System.out.println(answer);
	}
	public static long gcd(long div, long div2) {
		if (div2 == 0) {
			return div;
		}
		return gcd(div2, div%div2);
	}
}