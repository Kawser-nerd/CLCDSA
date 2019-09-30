import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		int alice = 0;
		int bob = 0;
		int k = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (k % 2 == 0)
				alice += a[i];
			else
				bob += a[i];
			k++;
		}
		System.out.println(Math.abs(alice - bob));
	}

}