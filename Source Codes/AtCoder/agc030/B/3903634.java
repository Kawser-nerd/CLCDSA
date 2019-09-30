import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long l = sc.nextLong();
		int n = sc.nextInt();
		long[] dis = new long[n+1];
		long[] sum = new long[n+1];
		for(int i=1; i<=n; i++) {
			dis[i] = sc.nextLong();
			sum[i] = sum[i-1] + dis[i];
		}
		if(n == 1) {
			System.out.println(Math.max(dis[1], l-dis[1]));
			return;
		}
		long ans = 0;
		for(int i=1; i<=n; i++) { // i is the pivot
			// hitting pivot from right
			int right = Math.min(i-1, n-i);
			int left = Math.min(i, n-i);
			ans = Math.max(ans, dis[i] + (sum[i-1] - sum[i-1-right])*2 + left *2*l - 2*(sum[left+i] - sum[i]));
			// hitting pivot from left
			right = Math.min(i-1, n-i+1);
			left = Math.min(n-i, i-1);
			ans = Math.max(ans, l-dis[i] + (sum[i-1] - sum[i-1-right])*2 + left *2*l - 2*(sum[left+i] - sum[i]));
//			System.out.println(ans);
		}
		System.out.println(ans);
	}
}