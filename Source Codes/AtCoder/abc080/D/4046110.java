import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int C = sc.nextInt();
		int MAX = 100001;
		int[] s = new int[N];
		int[] t = new int[N];
		int[] c = new int[N];
		for(int i = 0; i < N; i++) {
			s[i] = sc.nextInt();
			t[i] = sc.nextInt();
			c[i] = sc.nextInt() - 1;
		}
		sc.close();
		int[][]a = new int[C][MAX];
		for(int i = 0; i < N; i++) {
			a[c[i]][s[i] - 1]++;
			a[c[i]][t[i]]--;
		}
		for(int i = 0; i < C; i++) {
			for(int j = 1; j < MAX; j++) {
				a[i][j] += a[i][j - 1];
			}
		}
		int max = 0;
		for(int i = 0; i < MAX; i++) {
			int cnt = 0;
			for(int j = 0; j < C; j++) {
				if(a[j][i] != 0) {
					cnt++;
				}
			}
			max = Math.max(max, cnt);
		}
		System.out.println(max);
	}
}