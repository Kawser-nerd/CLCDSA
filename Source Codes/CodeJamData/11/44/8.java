import java.util.*;

import static java.lang.Math.*;

public class D {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz=1;zz<=T;zz++){
			N = in.nextInt();
			M = in.nextInt();
			G = new ArrayList[N];
			for(int i = 0; i < N;i++)
				G[i] = new ArrayList<Integer>();
			for(int i = 0; i < M;i++){
				String S[] = in.next().split(",");
				int a = Integer.valueOf(S[0]);
				int b = Integer.valueOf(S[1]);
				G[a].add(b);
				G[b].add(a);
			}
			int st = 0;
			int en = 1;
			dst = dist(st);
			den = dist(en);
			int cost = dst[en];
			boolean[] onsp = new boolean[N];
			for(int i = 0; i < N;i++)
				if(dst[i] + den[i] == cost)
					onsp[i] = true;
			DP = new int[N][N];
			for(int[] dp:DP)
				Arrays.fill(dp, -1);
			int hit = 0;
			if(cost == 1){
				hit = G[st].size();
			}else{
				GG = new BitSet[N][cost+1];
				for(int i = 0; i < N;i++)
					for(int j = 0; j <= cost; j++)
						GG[i][j] = new BitSet();
				for(int c = 0; c <= cost;c++){
					int at = 0;
					for(int i = 0; i < N;i++){
						if(dst[i] + den[i] <= cost+2 && dst[i] == c){
							for(int e:G[i]){
								GG[e][c].set(at);
							}
							at++;
						}
					}
				}
				for(int e:G[st]){
					if(onsp[e])
						hit = max(hit, recur(st, e));
				}
			}
			System.out.format("Case #%d: %d %d\n", zz, cost-1, hit);
		}
	}
	private static int recur(int a, int b) {
		if(DP[a][b] != -1)
			return DP[a][b];
		int ans = 0;
		if(den[b] == 1){
			BitSet n1 = (BitSet)GG[a][dst[b]].clone();
			n1.or(GG[b][dst[b]]);
			
			BitSet n2 = (BitSet)GG[a][dst[b]+1].clone();
			n2.or(GG[b][dst[b]+1]);
			ans = n1.cardinality()+n2.cardinality()-1;
		}else{
			for(int c:G[b]){
				if(den[b]-1 == den[c]){
					BitSet n = (BitSet)GG[a][dst[b]].clone();
					n.or(GG[b][dst[b]]);
					n.or(GG[c][dst[b]]);
					ans = max(ans, n.cardinality()-1 + recur(b, c));
				}
			}
		}
		DP[a][b] = ans;
		return ans;
	}
	static ArrayList<Integer>[] G;
	static BitSet[][] GG;
	static int[] dst, den;
	static int[][] DP;
	static int N, M;
	private static int[] dist(int st) {
		LinkedList<Integer> Q = new LinkedList<Integer>();
		int[] ans = new int[N];
		int BIG = 10*N;
		Arrays.fill(ans, BIG);
		ans[st] = 0;
		Q.add(st);
		while(Q.size() > 0){
			int at = Q.poll();
			for(int e:G[at]){
				if(ans[e] == BIG){
					ans[e] = ans[at]+1;
					Q.add(e);
				}
			}
		}
		return ans;
	}

}
