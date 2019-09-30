
import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;

public class D {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int caseNum = sc.nextInt();
		for(int caseID = 1; caseID <= caseNum; caseID++){
			new D().solveDataSet(caseID);
		}
	}
	int R;
	int C;
	char[][] map;
	int treeNum;
	int[] trees;
	void solveDataSet(int caseID){
		R = sc.nextInt();
		C = sc.nextInt();
		map = new char[R][C];
		ArrayList<Integer> treeList = new ArrayList<Integer>();
		for(int r = 0; r < R; r++){
			String row = sc.next();
			for(int c = 0; c < C; c++){
				map[r][c] = row.charAt(c);
				if(map[r][c] == 'T'){
					treeList.add(rc2ID(r, c));
				}
			}
		}
		
		treeNum = treeList.size();
		trees = new int[treeNum];
		for(int i = 0; i < treeNum; i++) trees[i] = treeList.get(i);
		
		int[][] wmat = new int[R * C][R * C];
		for(int v1 = 0; v1 < R * C; v1++){
			for(int v2 = 0; v2 < R * C; v2++){
				if(v1 == v2){
					wmat[v1][v2] = FloydWarshall.INF;
				}
				else{
					int r1 = getRow(v1);
					int c1 = getCol(v1);
					int r2 = getRow(v2);
					int c2 = getCol(v2);
					if(map[r1][c1] == '.' || map[r2][c2] == '.'){
						wmat[v1][v2] = FloydWarshall.INF;
					}
					else if(r1 == r2 && abs(c1 - c2) == 1){
						wmat[v1][v2] = 1;
					}
					else if(c1 == c2 && abs(r1 - r2) == 1){
						wmat[v1][v2] = 1;
					}
					else{
						wmat[v1][v2] = wmat[v1][v2] = FloydWarshall.INF;
					}
				}
			}
		}
		
		FloydWarshall fw = new FloydWarshall(R * C, wmat);
		fw.run();
		
		int[][] wmatTree = new int[treeNum][treeNum];
		for(int i = 0; i < treeNum; i++){
			for(int j = 0; j < treeNum; j++){
				wmatTree[i][j] = fw.dmat[trees[i]][trees[j]];
			}
		}
		
		Prim prim = new Prim(treeNum, wmatTree);
		prim.run();
		
		boolean[] visited = new boolean[R * C];
		visited[0] = true;
		
		int ans = 0;
		
		for(int i = 1; i < treeNum; i++){
			int treeCur = trees[i];
			int treePrev = trees[prim.prev[i]];
//			System.out.println(Arrays.deepToString(fw.pmat));
//			System.out.println(Arrays.deepToString(fw.dmat));
//			System.out.println(Arrays.deepToString(fw.wmat));
			ArrayList<Integer> path = fw.path(treePrev, treeCur);
			for(int v : path){
				if(v == treePrev) continue;
				if(!visited[v]){
					ans += fw.dmat[treePrev][v];
					visited[v] = true;
				}
			}
		}
		
		for(int i = 0; i < R * C; i++){
			if(visited[i]) continue;
			int r = getRow(i);
			int c = getCol(i);
			if(map[r][c] == '#'){
				int cost = FloydWarshall.INF;
				for(int tree : trees){
					cost = min(fw.dmat[tree][i], cost);
				}
				ans += cost;
				visited[i] = true;
			}
			else if(map[r][c] == '.'){
				// DO NOTHING
			}
			else throw new RuntimeException();
		}
		
		System.err.printf("Case #%d: %d%n", caseID, ans);
		System.out.printf("Case #%d: %d%n", caseID, ans);
	}
	int getRow(int id){
		return id / C;
	}
	int getCol(int id){
		return id % C;
	}
	int rc2ID(int row, int col){
		return row * C + col;
	}
}

class FloydWarshall {
	static final int INF = 1 << 28;
	int n;
	int[][] wmat; // input
	int[][] dmat;
	int[][] pmat;

	FloydWarshall(int n, int[][] wmat) {
		this.n = n;
		this.wmat = wmat;
	}

	void run() {
		dmat = new int[n][n];
		pmat = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dmat[i][j] = wmat[i][j];
				pmat[i][j] = i;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(i == j) continue;
					if (dmat[i][k] + dmat[k][j] < dmat[i][j]) {
						dmat[i][j] = dmat[i][k] + dmat[k][j];
						pmat[i][j] = pmat[k][j];
					}
				}
			}
		}
	}
	ArrayList<Integer> path(int s, int t) {
		if (dmat[s][t] == INF)
			return null;
		ArrayList<Integer> path = new ArrayList<Integer>();
		for (int u = t; u != pmat[s][u]; u = pmat[s][u]){
			path.add(u);
		}
		path.add(s);
		Collections.reverse(path);
		return path;
	}
}

class Prim {
	static final int INF = 1 << 28;
	int n;
	int[][] wmat; // input
	boolean valid; // connected or not
	int[] prev; // previous node in MST
	int mstw; // weight of MST

	Prim(int n, int[][] wmat) {
		this.n = n;
		this.wmat = wmat;
	}

	void run() {
		prev = new int[n];
		Arrays.fill(prev, -1);
		int[] pot = new int[n];
		Arrays.fill(pot, INF);
		boolean[] searched = new boolean[n];
		pot[0] = 0;
		for (int k = 0; k < n; k++) {
			int v = -1;
			int min = INF;
			for (int i = 0; i < n; i++)
				if (!searched[i] && pot[i] < min) {
					v = i;
					min = pot[i];
				}
			if (v == -1)
				return; // non-connected
			searched[v] = true;
			if (v != 0)
				mstw += wmat[prev[v]][v];
			for (int i = 0; i < n; i++) {
				if (!searched[i] && wmat[v][i] < pot[i]) {
					pot[i] = wmat[v][i];
					prev[i] = v;
				}
			}
		}
		valid = true;
		return;
	}
}