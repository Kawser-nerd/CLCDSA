import java.awt.Checkbox;
import java.lang.invoke.ConstantCallSite;
import java.security.spec.ECPrivateKeySpec;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
	static int a[], b[];
	static int N, K, Q;
	public static boolean check(int low, int high) {
		int last = -1;
		int total = 0;
		int cnt = 0;
		for (int i = 0; i <= N; i++) {
			if (i == N || a[i] < low) {
				///last + 1 -> i - 1 is okay
				total += Math.min(cnt, Math.max(0, (i - 1 - (last + 1) + 1) - K + 1));
				last = i;
				cnt = 0;
			} else 
			if (a[i] >= low && a[i] <= high) cnt++;
		}
		if (total >= Q) return true; else 
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt(); K = in.nextInt(); Q = in.nextInt();
		a = new int[N];
		for (int i = 0; i < N; i++) a[i] = in.nextInt();
		
		b = new int[N];
		for (int i = 0; i < N; i++) b[i] = a[i];
		Arrays.sort(b);
		//for (int i = 0; i < N; i++) System.out.print(b[i] + " "); System.out.println("");
		//System.out.println(check(1, 2));
		
		int result = (int)1e9;
		
		for (int i = 0; i < N; i++) {
			int low = i, high = N - 1, res = N;
			while (low <= high) {
				int mid = (low + high) >> 1;
				if (check(b[i], b[mid])) {
					res = mid;
					high = mid - 1;
				} else low = mid + 1;
			}
			if (res >= i && res < N) {
				result = Math.min(result, b[res] - b[i]);
			}
		}
		
		System.out.println(result);
	}
}