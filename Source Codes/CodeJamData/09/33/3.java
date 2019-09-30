import java.util.*;


public class C {
	static Map<Prison, Integer> cache = new HashMap<Prison, Integer>();
	
	static class Prison {
		int start, end;
		
		Prison(int s, int e) { this.start = s; this.end = e; }
		
		public int hashCode() {
			return start * 10001 + end;
		}
		
		public boolean equals(Object o) {
			return o.hashCode() == hashCode();
		}
		
		int solve() {
			Integer solution = cache.get(this);
			if ( solution != null ) return solution;
			solution = solve0();
			cache.put(this, solution);
			return solution;
		}
		
		int solve0() {
			if ( length() == 0 ) return 0;
			
			int answer = Integer.MAX_VALUE;
			
			for ( int q : Q ) {
				if ( q < start || q > end ) continue;
				Prison left = new Prison(start, q-1);
				Prison right = new Prison(q+1, end);
				int sol = left.length() + right.length() + left.solve() + right.solve();
				if ( sol < answer ) answer = sol;
			}
			
			if ( answer == Integer.MAX_VALUE ) return 0;
			return answer;
		}
		
		int length() {
			return end - start +1;
		}
	}
	
	static List<Integer> Q = new ArrayList<Integer>();
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.useDelimiter("\\s+");
		
		int testCases = s.nextInt();
		for ( int t = 0 ; t < testCases ; t++ ) {
			Q.clear();
			int p = s.nextInt();
			int q = s.nextInt();
			for ( int i = 0 ; i < q ; i++ ) {
				Q.add(s.nextInt());
			}
			
			Prison prison = new Prison(1, p);
			
			cache.clear();
			
			int sol = prison.solve();
			System.out.printf("Case #%d: %d\n", t + 1, sol);
		}
	}
}
