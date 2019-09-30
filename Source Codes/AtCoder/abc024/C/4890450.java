import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int k = sc.nextInt();
		int[] l = new int[d];
		int[] r = new int[d];
		for (int i = 0; i < d; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}
		int[] s = new int[k];
		int[] t = new int[k];
		int[] now = new int[k];
		for (int i = 0; i < k; i++) {
			s[i] = sc.nextInt();
			t[i] = sc.nextInt();
			now[i] = s[i];
		}
		sc.close();

		int[] ans = new int[k];
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < k; j++) {
				if (ans[j] != 0) {
					continue;
				}
				if (l[i] <= now[j] && now[j] <= r[i]) {
					if (now[j] < t[j]) {
						if (t[j] <= r[i]) {
							now[j] = t[j];
							ans[j] = i + 1;
						} else {
							now[j] = r[i];
						}
					} else {
						if (t[j] >= l[i]) {
							now[j] = t[j];
							ans[j] = i + 1;
						} else {
							now[j] = l[i];
						}
					}
				}
			}
			
		}

		for (int i = 0; i < k; i++) {
			System.out.println(ans[i]);
		}
	}
}