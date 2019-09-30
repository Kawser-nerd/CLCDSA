import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt();
		long S = sc.nextInt();
		long[] x = new long[N], p = new long[N];
		for (int i = 0; i < N; i++) {
			x[i] = sc.nextInt();
			p[i] = sc.nextInt();
		}
		int left = 0, right = N - 1;
		long[] order = new long[N];
		int idx = 0;
		while (x[left] < S && S < x[right]) {
			if (p[left] >= p[right]) {
				order[idx++] = x[right];
				p[left] += p[right];
				right--;
			} else {
				order[idx++] = x[left];
				p[right] += p[left];
				left++;
			}
		}
		while (right >= 0 && S < x[right]) {
			order[idx++] = x[right];
			right--;
		}
		
		while (left < N && x[left] < S) {
			order[idx++] = x[left];
			left++;
		}
		long ans = 0;
		for (int i = N - 1; i >= 0; i--) {
			ans += Math.abs(order[i] - S);
			S = order[i];
		}
		System.out.println(ans);
	}
}