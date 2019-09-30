import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		
		int cnt[] = new int[1000001];
		Arrays.fill(cnt, 0);
		for(int i = 0; i < n; i++) {
			cnt[a[i]] += 1;
			if(b[i] != 1000000) {
				cnt[b[i] + 1] += -1;
			}
		}
		
		int ans[] = new int[1000001];
		ans[0] = cnt[0];
		for(int i = 1; i < 1000001; i++) {
			ans[i] = ans[i - 1] + cnt[i];
		}
		
		int max = 0;
		for(int i = 0; i < 1000001; i++) {
			max = Math.max(max, ans[i]);
		}
		System.out.println(max);
	}
}