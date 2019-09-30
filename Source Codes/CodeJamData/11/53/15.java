import java.util.*;

import static java.lang.Math.*;

public class C {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++){
			R = in.nextInt();
			C = in.nextInt();
			G = new ArrayList[R*C];
			RG = new ArrayList[R*C];
			for(int i = 0; i < R*C;i++){
				G[i] = new ArrayList<Integer>();
				RG[i] = new ArrayList<Integer>();
			}
			for(int r = 0; r < R;r++){
				String s = in.next();
				for(int c = 0; c < C;c++){
					char ch = s.charAt(c);
					if(ch == '-'){
						add(r, c, 1, 0);
					}else if(ch == '|'){
						add(r, c, 0, 1);
					}else if(ch == '\\'){
						add(r, c, 1, 1);
					}else if(ch == '/'){
						add(r, c, 1, -1);
					}
				}
			}
			int N = R*C;
			
			boolean update = true;
			done = new boolean[N];
			boolean legal = true;
			done:
				while(update){
					update = false;
					for(int i = 0; i < N;i++){
						if(done[i])
							continue;
						if(RG[i].size() == 0){
							legal = false;
							break done;
						}else if(RG[i].size() == 1){
							done[i] = true;
							int a = RG[i].get(0);
							for(int e:G[a]){
								if(e == i)
									continue;
								if(done[e]){
									legal = false;
									break done;
								}
								RG[e].remove(Integer.valueOf(a));
							}
						}
					}
				}
			long ans = 1;
			if(!legal){
				ans = 0;
			}else{
				for(int i = 0; i < N;i++){
					if(!done[i]){
						dfs(i);
						ans *= 2;
						ans %= MOD;
					}
				}
			}
			System.out.format("Case #%d: %d\n", zz, ans);
		}
	}
	static long MOD = 1000003;
	private static void dfs(int at) {
		if(done[at])
			return;
		done[at] = true;
		for(int e:RG[at]){
			dfs(G[e].get(0));
			dfs(G[e].get(1));
		}
	}
	static boolean[] done;
	static int R, C;
	static ArrayList<Integer>[] G, RG;
	private static void add(int r, int c, int dc, int dr) {
		add2(r, c, r+dr, c+dc);
		add2(r, c, r-dr, c-dc);
	}
	private static void add2(int r, int c, int nr, int nc) {
		if(nr < R)
			nr += R;
		if(nr >= R)
			nr -= R;
		if(nc < C)
			nc += C;
		if(nc >= C)
			nc -= C;
		G[r*C+c].add(nr*C+nc);
		RG[nr*C+nc].add(r*C+c);
	}
}
