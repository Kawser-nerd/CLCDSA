import java.util.*;

public class Main {
	static final long MOD = 1000000007L;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Long> list = new ArrayList<>();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		long sum = 0;
		long total = 0;
		long prev = 0;
		long count = 0;
		for (int i = 0; i < n; i++) {
			total += sum + arr[i];
			sum += arr[i];
			if (i == 0) {
				count = 1;
			} else if (prev == arr[i]) {
				count++;
			} else {
				if (count != 1) {
					list.add(count);
				}
				count = 1;
			}
			prev = arr[i];
		}
		if (count != 1) {
			list.add(count);
		}
		long ans = 1;
		for (long x : list) {
			ans *= kaijo(x);
			ans %= MOD;
		}
		System.out.println(total);
		System.out.println(ans);
	}
	
	static long kaijo(long x) {
		if (x == 1) {
			return 1;
		} else {
			long ans = x * kaijo(x - 1);
			ans %= MOD;
			return ans;
		}
	}
}