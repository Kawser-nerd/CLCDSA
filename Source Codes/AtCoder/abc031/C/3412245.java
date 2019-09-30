import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int[]a = new int[N];
		for(int i = 0; i < N; i++) {
			a[i] = scan.nextInt();
		}
		scan.close();
		int max = -100000;
		for(int i = 0; i < N; i++) {
			int t = -1000000;

			int p = -1000000;
			for(int j = 0; j < N; j++) {
				if(i == j) continue;
				int l = Math.min(i, j);
				int r = Math.max(i, j);
				int p1 = 0;
				int p2 = 0;
				int turn = 1;
				for(int k = l; k <= r; k++) {
					if(turn % 2 == 1) {
						p1 += a[k];
					}else {
						p2 += a[k];
					}
					turn++;
				}
				if(t < p2) {
					t = p2;
					p = p1;
				}
			}
			max = Math.max(max, p);
		}
		System.out.println(max);
	}
}