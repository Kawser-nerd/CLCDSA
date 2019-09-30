import java.util.*;

public class B {
	static long ans;
	static PriorityQueue<long[]> Q;
	static void spend(long spend) {
		while(spend > 0) {
			long[] X = Q.poll();
			long amt = Math.min(spend, X[1]);
			System.out.println(spend+" "+X[0]+" "+X[1]);
			spend -= amt;
			ans += X[0]*amt;
			if(X[1]-amt > 0) Q.offer(new long[]{X[0], X[1]-amt});
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			long E = in.nextInt();
			long R = in.nextInt();
			int n = in.nextInt();
			Q = new PriorityQueue<long[]>(10, new Comparator<long[]>() {
				public int compare(long[] A, long[] B) { //inverted
					if(A[0] > B[0]) return -1;
					if(B[0] > A[0]) return 1;
					return 0;
				}
			});
			for(int i=0; i<n; i++)
				Q.offer(new long[]{in.nextInt(), i});
			
			long ans = 0;
			//M.get(2i) = before event i
			//M.get(2i+1) = after event i
			TreeMap<Integer, Long> M = new TreeMap<Integer, Long>();
			M.put(0, E);
			M.put(2*(n-1)+1, 0L);
			for(int i=0; i<n; i++) {
				long[] X = Q.poll();
				long v = X[0];
				int t = (int)X[1];
				
				int A = M.floorKey(2*t);
				int B = M.higherKey(2*t);
				
				long have_i = Math.min(E, M.get(A)+R*(t-A/2));
				long need_i = Math.max(0, M.get(B)-R*(B/2-t));
				
				
				ans += (have_i-need_i)*v;
				M.put(2*t, have_i);
				M.put(2*t+1, need_i);
				//System.out.println(ans+" "+t+" "+have_i+" "+need_i+" "+M.get(A)+" "+M.get(B));
			}
			System.out.printf("Case #%d: %d\n", cas, ans);
		}
		
	}
}
