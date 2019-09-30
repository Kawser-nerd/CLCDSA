import java.util.*;

public class C {
	static final int[] DXs = {1, 1, 1, -1, -1, -1};
	static final int[] DYs = {1, 0, -1, 1, 0, -1};
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int C = sc.nextInt();
		for(int caseID = 1; caseID <= C; caseID++){
			int M = sc.nextInt();
			int N = sc.nextInt();
			char[][] board = new char[M][N];
			for(int y = 0; y < M; y++){
				board[y] = sc.next().toCharArray();
			}
			
			int[][] ids = new int[M][N];
			for(int y = 0; y < M; y++){
				Arrays.fill(ids[y], -1);
			}
			int lcnt = 0;
			int rcnt = 0;
			for(int y = 0; y < M; y++){
				for(int x = 0; x < N; x++){
					if(board[y][x] == '.'){
						if(x % 2 == 0){
							ids[y][x] = lcnt++;
						}
						else{
							ids[y][x] = rcnt++;
						}
					}
				}
			}
			
			int lsize = lcnt;
			int rsize = rcnt;
			int[][] ladjs = new int[lsize][6];
			for(int[] ladj: ladjs) Arrays.fill(ladj, -1);
			
			for(int y = 0; y < M; y++){
				for(int x = 0; x < N; x += 2){
					int lid = ids[y][x];
					if(lid < 0) continue;
					for(int dir = 0; dir < 6; dir++){
						int ry = y + DYs[dir];
						int rx = x + DXs[dir];
						if(0 <= ry && ry < M && 0 <= rx && rx < N){
							int rid = ids[ry][rx];
							if(rid < 0) continue;
							ladjs[lid][dir] = rid;
						}
					}
				}
			}
			
			BMatching bm = new BMatching(lsize, rsize, ladjs);
			bm.run();
			int matchnum = bm.matchnum;
			
			System.out.printf("Case #%d: %d%n", caseID, lsize + rsize - matchnum);
		}
	}
}

class BMatching {
	int lsize, rsize;
	int[][] ladj; // input
	int matchnum;
	int[] lmatch, rmatch;
	boolean[] rsearched;
	BMatching(int lsize, int rsize, int[][] ladj) {
		this.lsize = lsize;
		this.rsize = rsize;
		this.ladj = ladj;
	}
	void run() {
		matchnum = 0;
		lmatch = new int[lsize];
		Arrays.fill(lmatch, -1);
		rmatch = new int[rsize];
		Arrays.fill(rmatch, -1);
		rsearched = new boolean[rsize];
		for (int u = 0; u < lsize; u++) {
			Arrays.fill(rsearched, false);
			if (search(u)) matchnum++;
		}
	}

	private boolean search(int u) {
		for (int v : ladj[u]) {
			if(v < 0) continue;
			if (rsearched[v]) continue;
			rsearched[v] = true;
			if (rmatch[v] == -1 || search(rmatch[v])) {
				lmatch[u] = v;
				rmatch[v] = u;
				return true;
			}
		}
		return false;
	}
}
