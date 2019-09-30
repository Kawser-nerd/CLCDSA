import java.util.*;

public class C {
	
	static int n;
	static int m;
	static int[][] EE;
	static int[] PATH;
	static boolean prefix_good(int p) {
		List<List<Integer>> E = new ArrayList<List<Integer>>();
		for(int i=0; i<n; i++) E.add(new ArrayList<Integer>());
		for(int ei=0; ei<m; ei++)
			E.get(EE[ei][0]).add(ei);
		
		int st = EE[PATH[p]][1];
		int dst = 0;
		for(int i=0; i<=p; i++)
			dst += EE[PATH[i]][2];
		Set<Integer> SHORT = new HashSet<Integer>();
		for(int i=0; i<=p; i++)
			SHORT.add(PATH[i]);
		
		PriorityQueue<int[]> Q = new PriorityQueue<int[]>(10, new Comparator<int[]>() {
			public int compare(int[] A, int[] B) {
				if(A[1]!=B[1])
					return A[1]-B[1];
				else if(A[2]==1) return -1;
				else if(A[2]==0) return 1;
				else return 0;
			}
		});
		
		boolean[] S = new boolean[n];
		Q.offer(new int[]{0, 0, 0});
		Q.offer(new int[]{st, dst, 1});
		while(!Q.isEmpty()) {
			int[] X = Q.poll();
			int v = X[0];
			int d = X[1];
			boolean make_long = X[2]==0;
			if(S[v]) continue;
			S[v] = true;
			if(v==1) return X[2]==1;
 			for(Integer ei : E.get(v)) {
				if(SHORT.contains(ei) || !make_long)
					Q.offer(new int[]{EE[ei][1], d+EE[ei][2], X[2]});
				else Q.offer(new int[]{EE[ei][1], d+EE[ei][3], X[2]});
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		CAS: for(int cas=1; cas<=T; cas++) {
			n = in.nextInt();
			m = in.nextInt();
			int p = in.nextInt();
			
			EE = new int[m][];
			for(int i=0; i<m; i++) {
				int x = in.nextInt()-1;
				int y = in.nextInt()-1;
				int lo = in.nextInt();
				int hi = in.nextInt();
				EE[i] = new int[]{x,y,lo,hi};
			}
			PATH = new int[p];
			for(int i=0; i<p; i++)
				PATH[i] = in.nextInt()-1;
			
			for(int i=0; i<p; i++)
				if(!prefix_good(i)) {
					System.out.printf("Case #%d: %d\n", cas, PATH[i]+1);
					continue CAS;
				}
			System.out.printf("Case #%d: Looks Good To Me\n", cas);
			continue CAS;
		}
	}
}
