import java.math.BigInteger;
import java.util.*;

public class A {
	static BigInteger B(long n) { return BigInteger.valueOf(n); }
	static BigInteger A(BigInteger A, BigInteger B) { return A.add(B); }
	static BigInteger M(BigInteger A, BigInteger B) { return A.multiply(B); }
	
	static long L;
	static BigInteger cost(long len) {
		BigInteger LEN = B(len);
		BigInteger SUM_LEN = M(LEN, A(LEN, B(-1))).divide(B(2));
		BigInteger ans = M(B(L), LEN);
		ans = ans.subtract(SUM_LEN);
		return ans;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			L = in.nextInt();
			int n = in.nextInt();
			
			List<long[]> EV = new ArrayList<long[]>();
			
			BigInteger old_cost = B(0);
			for(int i=0; i<n; i++) {
				long enter = in.nextInt();
				long exit = in.nextInt();
				long k = in.nextInt();
				EV.add(new long[]{enter, k, 1});
				EV.add(new long[]{exit, k, -1});
				old_cost = A(old_cost, M(B(k), cost(exit-enter)));
			}
			
			BigInteger new_cost = B(0);
			Collections.sort(EV, new Comparator<long[]>() {
				public int compare(long[] A, long[] B) {
					if(A[0] > B[0]) return 1;
					if(A[0] < B[0]) return -1;
					
					if(A[2] > B[2]) return -1;
					if(A[2] < B[2]) return 1;
					return 0;
				}
			});
			Stack<long[]> ST = new Stack<long[]>();
			for(long[] ev : EV) {
				//System.out.println(ev[0]+" "+ev[1]+" "+ev[2]);
				if(ev[2]==1) { //enter
					ST.push(new long[]{ev[0], ev[1]});
				} else {
					long pos = ev[0];
					long amt = ev[1];
					while(true) {
						long[] ent = ST.pop();
						if(ent[1]>=amt) {
							new_cost = A(new_cost, M(B(amt), cost(pos-ent[0])));
							ST.push(new long[]{ent[0], ent[1]-amt});
							break;
						} else {
							new_cost = A(new_cost, M(B(ent[1]), cost(pos-ent[0])));
							amt -= ent[1];
						}
					}
				}
			}
			BigInteger ans = old_cost.subtract(new_cost);
			System.out.printf("Case #%d: %s\n", cas, ans.toString());
		}
	}
}
