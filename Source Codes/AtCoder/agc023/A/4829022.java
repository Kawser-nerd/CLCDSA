import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();// n????
		long a[] = new long[n + 1];
		long ru[] = new long[n +1];
		a[0] = 0;
		ru[0] = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = sc.nextLong();
			ru[i] = ru[i - 1] + a[i];
			}

		Arrays.sort(ru);

		long sta, gol;
		sta = 0;
		gol = 0;
		long a1, ans;
		ans = 0;

		for (int i = 1; i <= n ; i++) {
			if (ru[i - 1] - ru[i] != 0) {
				gol = i;

				a1 = gol - sta;

				ans = ans + cou(a1);
				sta = gol;

			}
		}
		a1=n+1-sta;
		ans=ans+cou(a1);
		System.out.println(ans);
	}

	public static long cou(long a) {
		long c;
		c = a * (a - 1);

		c = c / 2;
		return c;
	}

}