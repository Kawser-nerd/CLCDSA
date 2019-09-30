import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int H = sc.nextInt();
		int a[] = new int[N];
		int b[] = new int[N];
		int max = 0;
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			max = Math.max(a[i], max);
		}
		
		Arrays.sort(b);
		int ans = 0;
		int sum = 0;
		for(int i = N - 1; i >= 0; i--) {
			if(max > b[i]) {
				break;
			}
			sum += b[i];
			ans++;
			if(sum >= H) {
				System.out.println(ans);
				return;
			}
		}
		while(sum < H) {
			sum += max;
			ans++;
		}
		System.out.println(ans);
	}
}