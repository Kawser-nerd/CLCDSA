import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		final long MOD = 1000000007;
		int N = sc.nextInt();
		int[] cnt = new int[N];
		for(int i=0; i<N; i++)
			cnt[sc.nextInt()]++;
		
		long ans = 1;
		for(int i=(N-1)%2; i<=N-1; i+=2) {
			if(cnt[i]==(i==0 ? 1 : 2)) {
				ans = (ans * cnt[i])%MOD;
			} else {
				ans = 0;
				break;
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
}