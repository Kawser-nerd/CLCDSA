import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long[] a = new long[N];
		for(int i=0; i<N; i++)
			a[i] = sc.nextLong();
		
		long ans = 0;
		
		Arrays.sort(a);
		
		for(int i=1; i<N; i++) {
			long op = (a[i]-a[0])/(N+1);
			ans += op;
			a[i] -= op*(N+1);
		}
		
		for(int i=0; i<N; i++)
			a[i] += ans;
		
		Arrays.sort(a);
		
		long op = Math.max(0, a[0]-N);
		for(int i=0; i<N; i++)
			a[i] -= op;
		ans += op*N;
		
		int idx = N-1;
		while(true) {
			if(a[idx]<=N-1)
				break;
			ans++;
			a[idx]-=N;
			for(int i=0; i<N; i++)
				if(i!=idx)
					a[i]++;
			idx = (idx-1+N)%N;
		}
		
		System.out.println(ans);
		sc.close();
	}
}