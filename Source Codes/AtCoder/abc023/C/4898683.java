import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		int C = sc.nextInt();
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] r = new int[n];
		int[] c = new int[n];
		// ??????????
		int[] cntr = new int[R];
		int[] cntc = new int[C];
		for (int i = 0; i < n; i++) {
			r[i] = sc.nextInt() - 1;
			c[i] = sc.nextInt() - 1;
			cntr[r[i]]++;
			cntc[c[i]]++;
		}
		sc.close();

		// ?????????
		int[] cntr2 = new int[100001];
		int[] cntc2 = new int[100001];
		for (int i = 0; i < cntr.length; i++) {
			cntr2[cntr[i]]++;
		}
		for (int i = 0; i < cntc.length; i++) {
			cntc2[cntc[i]]++;
		}

		long ans = 0;
		for (int i = 0; i <= k; i++) {
			ans += cntr2[i] * cntc2[k - i];
		}

		for (int i = 0; i < n; i++) {
			if (cntr[r[i]] + cntc[c[i]] == k) {
				ans--;
			} else if (cntr[r[i]] + cntc[c[i]] == k + 1) {
				ans++;
			}
		}

		System.out.println(ans);
	}
}