import java.util.*;

public class Main {
	static int sum(long v) {
		int ans = 0;
		while(v>0) {
			ans += v%10;
			v /= 10;
		}

		return ans;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long M = sc.nextLong();
		long A = M/100000;
		
		HashMap<Long, Long> map = new HashMap<>();
		for(int i=0; i<100000; i++) {
			long fb = (i - sum(i)%K + K)%K;
			map.put(fb, (map.containsKey(fb) ? map.get(fb) : 0) + 1);
		}
		
		long ans = 0;
		for(long i=0; i<A; i++) {
			long fa = (i*100000 - sum(i)%K + K)%K;
			Long v = map.get((K-fa)%K);
			ans += v!=null ? v : 0;
		}
		
		for(long i=A*100000; i<=M; i++) {
			if(i%K==sum(i)%K)
				ans++;
		}
		
		// M is not zero 
		System.out.println(ans-1);
		sc.close();
	}
}