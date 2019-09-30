import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] cnt = new long[5];
		for (int i = 0; i < n; i++) {
			char ch = sc.next().charAt(0);
			if (ch == 'M') cnt[0]++;
			if (ch == 'A') cnt[1]++;
			if (ch == 'R') cnt[2]++;
			if (ch == 'C') cnt[3]++;
			if (ch == 'H') cnt[4]++;
		}
		sc.close();

		int c = 0;
		for (int i = 0; i < cnt.length; i++) {
			if (cnt[i] > 0) c++;
		}
		if (c < 3) {
			System.out.println(0);
			return;
		}

		long ans = 0L;
		for (int i = 0; i < cnt.length; i++) {
			for (int j = i + 1; j < cnt.length; j++) {
				for (int k = j + 1; k < cnt.length; k++) {
					ans += cnt[i] * cnt[j] * cnt[k];
				}
			}
		}
		System.out.println(ans);
	}
}