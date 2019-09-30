import java.util.Arrays;
import java.util.Scanner;

public class Space {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int L = sc.nextInt();
			long t = sc.nextLong();
			int N = sc.nextInt();
			int C = sc.nextInt();
			
			long time = t;
			int[] a = new int[1000001];
			
			for (int j = 0; j < C; j++) {
				a[j] = sc.nextInt();
			}
			for (int j = C; j < N; j++) {
				a[j] = a[j-C];
			}
			int index = 0;
			while (t > 0 && index < N) {
				if (a[index] > (t / 2)) {
					a[index] -= t / 2;
					t = -1;
				} else {
					t -= a[index]*2;
					index++;
				}
			}
			if (t > 0) {
				time -= t;
			}
			if (index < N) {
				Arrays.sort(a, index, (int) N);
				for (int j = (int) (N - 1); j >= index; j--) {
					if (L > 0) {
						time += a[j];
						L--;
					} else {
						time += a[j]*2;
					}
				}
			}
			
			System.out.println("Case #" + i + ": " + time);			
		}
	}
	
}
