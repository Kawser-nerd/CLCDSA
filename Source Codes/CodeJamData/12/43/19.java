import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		CASE: for(int cas=1; cas<=T; cas++) {
			int n = in.nextInt();
			int[] N = new int[n-1];
			for(int i=0; i<n-1; i++) {
				N[i] = in.nextInt()-1;
			}
			for(int i=0; i<n-1; i++)
				for(int j=i+1; j<n-1; j++) {
					if(j < N[i] && N[j] > N[i]) {
						System.out.printf("Case #%d: Impossible\n", cas, i, j);
						continue CASE;
					}
				}
			
			TreeMap<Integer,Integer> X = new TreeMap<Integer, Integer>();
			X.put(n-1, 1000*1000*1000);
			for(int i=0; i<n; i++) {
				if(X.containsKey(i)) continue;
				
				int st = i;
				int end = X.higherKey(i);
				int c = i;
				X.put(c, 0);
				while(!X.containsKey(N[c])) {
					c = N[c];
					X.put(c, (X.get(end)+end-st-1)/(end-st)*(c-st));
				}
			}
			
			for(int i=0; i<n; i++) {
				if(X.get(i) < 0 || X.get(i) > 1000*1000*1000)
					System.out.printf("OOPS: %d\n", i);
			}
			for(int i=0; i<n; i++) {
				for(int j=i+1; j<n; j++) {
					long pj = X.get(i) + ((long)(X.get(N[i])-X.get(i)))*(j-i)/(N[i]-i);
					if((j < N[i] && X.get(j) >= pj) ||
					   (j >= N[i] && X.get(j) > pj))
						System.out.printf("BAD: %d %d (%d %d %d)\n", i, j, pj, X.get(j), N[i]);
				}
				/*To be precise, when we say that peak B looks like it's the highest from peak
				A we mean that B is further down the road than A; all peaks between A and B are
				below the line connecting the peaks A and B; and all the peaks that are further than B are below or on this line.*/
				
			}
			
			System.out.printf("Case #%d:", cas);
			for(int i=0; i<n; i++)
				System.out.printf(" %d", X.get(i));
			System.out.println();
		}
	}
}