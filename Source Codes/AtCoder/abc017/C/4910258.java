import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		int[] s = new int[n];
		int all = 0;
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt() - 1;
			r[i] = sc.nextInt() - 1;
			s[i] = sc.nextInt();
			all += s[i];
		}
		sc.close();

		int minus[] = new int[m + 1];
		for (int i = 0; i < n; i++) {
			minus[l[i]] += s[i];
			minus[r[i] + 1] -= s[i];
		}
		for (int i = 1; i < m; i++) {
			minus[i] = minus[i - 1] + minus[i];
		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < m; i++) {
			min = Math.min(min, minus[i]);
		}

		System.out.println(all - min);
	}
}