import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N = sc.nextInt();
		int a[] = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		int M = sc.nextInt();
		int b[] = new int[M];
		for (int i = 0; i < M; i++) {
			b[i] = sc.nextInt();
		}
		if (N < M) {
			System.out.println("no");
			return;
		}
		boolean ans = true;
		int s = 0;
		for (int i = 0; i < M; i++) {
			for (int j = s; j < N; j++) {
				if (a[j] + T < b[i]) {
					if (i == M-1 && j == N-1) {
						ans = false;
						break;
					}
					s = j+1;
					continue;
				} else if (a[j] <= b[i] && b[i] <= (a[j] + T)) {
					s = j+1;
					break;
				}
				ans = false;
			}
		}
		if (ans) {
			System.out.println("yes");
		} else {
			System.out.println("no");
		}
	}
}