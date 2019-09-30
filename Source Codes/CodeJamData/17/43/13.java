import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int r = readInt();
			int c = readInt();
			char[][] grid = new char[r][c];
			int[][] laserIndex = new int[r][c];
			int numlasers = 0;
			for(int i = 0; i < r; i++) {
				String s = nextToken();
				Arrays.fill(laserIndex[i], -1);
				for(int j = 0; j < c; j++) {
					grid[i][j] = s.charAt(j);
					if(grid[i][j] == '-' || grid[i][j] == '|') {
						laserIndex[i][j] = numlasers++;
					}
				}
			}
			init2SAT(numlasers);
			ArrayList<Clause> already = new ArrayList<Clause>();
			int[] dx = new int[]{1,0,-1,0};
			int[] dy = new int[]{0,1,0,-1};
			boolean forceAbort = false;
			// force mirrors
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(laserIndex[i][j] < 0) continue;
					{
						// is horizontal bad?
						boolean isHorizontalBad = false;
						for(int startDir = 1; startDir < 4; startDir += 2) {
							int dir = startDir;
							int nx = i + dx[dir];
							int ny = j + dy[dir];
							while(nx >= 0 && nx < r && ny >= 0 && ny < c) {
								if(grid[nx][ny] == '#') break;
								else if(grid[nx][ny] == '-' || grid[nx][ny] == '|') {
									isHorizontalBad = true;
									break;
								}
								else if(grid[nx][ny] == '/') {
									if(dir == 0) dir = 3;
									else if(dir == 1) dir = 2;
									else if(dir == 2) dir = 1;
									else dir = 0;
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '\\') {
									if(dir == 0) dir = 1;
									else if(dir == 1) dir = 0;
									else if(dir == 2) dir = 3;
									else dir = 2;
									nx += dx[dir];
									ny += dy[dir];
								}
								else {
									nx += dx[dir];
									ny += dy[dir];
								}
							}
						}
						if(isHorizontalBad) {
							addClause(laserIndex[i][j], false, laserIndex[i][j], false);
							already.add(new Clause(laserIndex[i][j], false, laserIndex[i][j], false));
						}
					}
					{
						// is vertical bad?
						boolean isVerticalBad = false;
						for(int startDir = 0; startDir < 4; startDir += 2) {
							int dir = startDir;
							int nx = i + dx[dir];
							int ny = j + dy[dir];
							while(nx >= 0 && nx < r && ny >= 0 && ny < c) {
								if(grid[nx][ny] == '#') break;
								else if(grid[nx][ny] == '-' || grid[nx][ny] == '|') {
									isVerticalBad = true;
									break;
								}
								else if(grid[nx][ny] == '/') {
									if(dir == 0) dir = 3;
									else if(dir == 1) dir = 2;
									else if(dir == 2) dir = 1;
									else dir = 0;
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '\\') {
									if(dir == 0) dir = 1;
									else if(dir == 1) dir = 0;
									else if(dir == 2) dir = 3;
									else dir = 2;
									nx += dx[dir];
									ny += dy[dir];
								}
								else {
									nx += dx[dir];
									ny += dy[dir];
								}
							}
						}
						if(isVerticalBad) {
							addClause(laserIndex[i][j], true, laserIndex[i][j], true);
							already.add(new Clause(laserIndex[i][j], true, laserIndex[i][j], true));
						}
					}
				}
			}
			for(int i = 0; !forceAbort && i < r; i++) {
				for(int j = 0; !forceAbort && j < c; j++) {
					if(grid[i][j] != '.') {
						continue;
					}
					ArrayList<Integer> laserLoc = new ArrayList<Integer>();
					ArrayList<Boolean> orientLoc = new ArrayList<Boolean>();
					{
						// horizontal
						ArrayList<Integer> seenIndex = new ArrayList<Integer>();
						ArrayList<Boolean> orientation = new ArrayList<Boolean>();
						for(int startDir = 1; startDir < 4; startDir += 2) {
							int dir = startDir;
							int nx = i + dx[dir];
							int ny = j + dy[dir];
							while(nx >= 0 && nx < r && ny >= 0 && ny < c) {
								if(grid[nx][ny] == '#') break;
								else if(grid[nx][ny] == '-' || grid[nx][ny] == '|') {
									seenIndex.add(laserIndex[nx][ny]);
									if(dir == 1 || dir == 3) {
										orientation.add(true);
									}
									else {
										orientation.add(false);
									}
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '/') {
									if(dir == 0) dir = 3;
									else if(dir == 1) dir = 2;
									else if(dir == 2) dir = 1;
									else dir = 0;
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '\\') {
									if(dir == 0) dir = 1;
									else if(dir == 1) dir = 0;
									else if(dir == 2) dir = 3;
									else dir = 2;
									nx += dx[dir];
									ny += dy[dir];
								}
								else {
									nx += dx[dir];
									ny += dy[dir];
								}
							}
						}
						if(seenIndex.size() > 1) {
							forceAbort = true;
						}
						if(seenIndex.size() == 1) {
							laserLoc.add(seenIndex.get(0));
							orientLoc.add(orientation.get(0));
						}
					}
					{
						// vertical
						ArrayList<Integer> seenIndex = new ArrayList<Integer>();
						ArrayList<Boolean> orientation = new ArrayList<Boolean>();
						for(int startDir = 0; startDir < 4; startDir += 2) {
							int dir = startDir;
							int nx = i + dx[dir];
							int ny = j + dy[dir];
							while(nx >= 0 && nx < r && ny >= 0 && ny < c) {
								if(grid[nx][ny] == '#') break;
								else if(grid[nx][ny] == '-' || grid[nx][ny] == '|') {
									seenIndex.add(laserIndex[nx][ny]);
									if(dir == 1 || dir == 3) {
										orientation.add(true);
									}
									else {
										orientation.add(false);
									}
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '/') {
									if(dir == 0) dir = 3;
									else if(dir == 1) dir = 2;
									else if(dir == 2) dir = 1;
									else dir = 0;
									nx += dx[dir];
									ny += dy[dir];
								}
								else if(grid[nx][ny] == '\\') {
									if(dir == 0) dir = 1;
									else if(dir == 1) dir = 0;
									else if(dir == 2) dir = 3;
									else dir = 2;
									nx += dx[dir];
									ny += dy[dir];
								}
								else {
									nx += dx[dir];
									ny += dy[dir];
								}
							}
						}
						if(seenIndex.size() > 1) {
							forceAbort = true;
						}
						if(seenIndex.size() == 1) {
							laserLoc.add(seenIndex.get(0));
							orientLoc.add(orientation.get(0));
						}
					}
					if(laserLoc.isEmpty()) {
						forceAbort = true;
					}
					else if(laserLoc.size() == 1) {
						addClause(laserLoc.get(0), orientLoc.get(0), laserLoc.get(0), orientLoc.get(0));
						already.add(new Clause(laserLoc.get(0), orientLoc.get(0), laserLoc.get(0), orientLoc.get(0)));
					}
					else {
						addClause(laserLoc.get(0), orientLoc.get(0), laserLoc.get(1), orientLoc.get(1));
						already.add(new Clause(laserLoc.get(0), orientLoc.get(0), laserLoc.get(1), orientLoc.get(1)));
					}
				}
			}
			if(forceAbort || !valid()) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			else {
				pw.println("POSSIBLE");
				int startIndex = already.size();
				for(int i = 0; i < numlasers; i++) {
					init2SAT(numlasers);
					for(Clause cc: already) {
						addClause(cc.i1, cc.p1, cc.i2, cc.p2);
					}
					addClause(i, true, i, true);
					if(valid()) {
						already.add(new Clause(i, true, i, true));
					}
					else {
						already.add(new Clause(i, false, i, false));
					}
				}
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if(laserIndex[i][j] >= 0) {
							if(already.get(startIndex + laserIndex[i][j]).p1) {
								pw.print('-');
							}
							else {
								pw.print('|');
							}
						}
						else {
							pw.print(grid[i][j]);
						}
					}
					pw.println();
				}
			}
		}
		pw.close();
	}

	static class Clause {
		public int i1, i2;
		public boolean p1, p2;
		public Clause(int i1, boolean p1, int i2, boolean p2) {
			super();
			this.i1 = i1;
			this.i2 = i2;
			this.p1 = p1;
			this.p2 = p2;
		}

	}

	public static void init2SAT(int n) {
		// 0 through n-1 are positive
		// n to 2n-1 are negative
		edges = new ArrayList[2*n+2];
		for(int i = 0; i < edges.length; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		components = new int[2*n+2];
		Arrays.fill(components, -1);
		indices = new int[2*n+2];
		Arrays.fill(indices, -1);
		lowLink = new int[2*n+2];
		Arrays.fill(lowLink, -1);
		indicesIndex = 0;
		componentsIndex = 0;
		tarjanStack = new Stack<TarjanState>();
		sccStack = new Stack<Integer>();
		inStack = new boolean[2*n+2];
	}

	public static boolean valid() {
		for(int i = 0; i < components.length; i++) {
			if(components[i] == -1) {
				tarjan(i);
			}
		}
		int n = edges.length/2;
		for(int i = 0; i < n; i++) {
			if(components[i] == components[i+n]) return false;
		}
		return true;
	}

	private static int _get2SATValue(int index, boolean pos1) {
		if(!pos1){
			index += edges.length/2;
		}
		return index;
	}

	public static void addClause(int i1, boolean pos1, int i2, boolean pos2) {
		// a or b is equivalent to not a implies b
		// or not b implies not a
		edges[_get2SATValue(i1, !pos1)].add(_get2SATValue(i2, pos2));
		edges[_get2SATValue(i2, !pos2)].add(_get2SATValue(i1, pos1));
	}

	static ArrayList<Integer>[] edges;
	static int[] components;
	static int[] indices;
	static int[] lowLink;
	static int indicesIndex;
	static int componentsIndex;
	static Stack<TarjanState> tarjanStack;
	static Stack<Integer> sccStack;
	static boolean[] inStack;

	static class TarjanState {
		public int index;
		public int edgeNum;
		public boolean checkEarlier;
		public TarjanState(int index, int edgeNum, boolean checkEarlier) {
			super();
			this.index = index;
			this.edgeNum = edgeNum;
			this.checkEarlier = checkEarlier;
		}
	}

	public static void tarjan(int onlyUseThisVariableInTheFirstLine) {    
		tarjanStack.push(new TarjanState(onlyUseThisVariableInTheFirstLine, 0, false));
		while(!tarjanStack.isEmpty()) {
			TarjanState now = tarjanStack.pop();
			if(now.edgeNum == 0) {
				if(indices[now.index] >= 0) {
					continue;
				}
				inStack[now.index] = true;
				indices[now.index] = indicesIndex;
				lowLink[now.index] = indicesIndex;
				indicesIndex++;
				sccStack.push(now.index);
			}
			if(now.checkEarlier) {
				lowLink[now.index] = Math.min(lowLink[now.index], lowLink[edges[now.index].get(now.edgeNum-1)]);
			}
			if(now.edgeNum < edges[now.index].size()) {
				int next = edges[now.index].get(now.edgeNum);
				if(indices[next] == -1) {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, true));
					tarjanStack.push(new TarjanState(next, 0, false));
				}
				else {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, false));
					if(inStack[next]) {
						lowLink[now.index] = Math.min(lowLink[now.index], indices[next]);
					}
				}
			}
			else {
				if(lowLink[now.index] == indices[now.index]) {
					while(true) {
						int rem = sccStack.pop();
						inStack[rem] = false;
						components[rem] = componentsIndex;
						if(rem == now.index) {
							break;
						}
					}
					componentsIndex++;
				}
			}
		}
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
