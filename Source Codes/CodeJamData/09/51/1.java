import java.util.*;
import java.io.*;

public class EZSocoban {
	final int[] DX = new int[] {-1, 1, 0, 0};
	final int[] DY = new int[] {0, 0, -1, 1};
	class State {
		char[][] data;
		public State(char[][] data) {
			this.data = data;
		}
		public boolean equals(Object other) {
			State os = (State)other;
			for (int i=0; i < data.length; i++)
				for (int j=0; j < data[i].length; j++)
					if (data[i][j] != os.data[i][j])
						return false;
			return true;
		}
		public int hashCode() {
			int res = 0;
			for (int i=0; i < data.length; i++)
				for (int j=0; j < data[i].length; j++) {
					res = 3 * res;
					if (data[i][j] == '#') res++;
					if (data[i][j] == 'b') res+=2;
					res %= 1735244571;
				}
			return res;
		}
		boolean[][] used;
		int R, C;
		public void dfs(int x, int y) {
			used[x][y] = true;
			for (int i=0; i < 4; i++)
				if (x+DX[i] >= 0 && x+DX[i] < R && y+DY[i] >= 0 && y+DY[i] < C
					&& !used[x+DX[i]][y+DY[i]] && data[x+DX[i]][y+DY[i]] == 'b')
					dfs(x+DX[i], y+DY[i]);
		}
		public boolean isDangerous() {
			R = data.length;
			C = data[0].length;
			used = new boolean[R][C];
			int compCnt = 0;
			for (int i=0; i < R; i++)
				for (int j=0; j < C; j++)
					if (data[i][j] == 'b' && !used[i][j]) {
						compCnt++;
						if (compCnt > 1) return true;
						dfs(i, j);
					}
			return false;
		}
		public List<State> movesList() {
			List<State> res = new ArrayList<State>();
			boolean dang = isDangerous();
			R = data.length;
			C = data[0].length;
			for (int i=0; i < R; i++)
				for (int j=0; j < C; j++)
					if (data[i][j] == 'b')
						for (int k=0; k < 4; k++)
							if (i + DX[k] >= 0 && i + DX[k] < R && i - DX[k] >= 0 && i - DX[k] < R &&
								j + DY[k] >= 0 && j + DY[k] < C && j - DY[k] >= 0 && j - DY[k] < C &&
								data[i + DX[k]][j + DY[k]] == '.' && data[i - DX[k]][j - DY[k]] == '.') {
								char[][] tmp = new char[R][C];
								for (int ii=0; ii < R; ii++)
									for (int jj=0; jj < C; jj++)
										tmp[ii][jj] = data[ii][jj];
								tmp[i][j] = '.';
								tmp[i + DX[k]][j + DY[k]] = 'b';
								State toAdd = new State(tmp);
								if (dang && toAdd.isDangerous()) continue;
								res.add(toAdd);
							}
			return res;
		}
	}
	
	char[][] construct(String[] s, String charset) {
		char[][] res = new char[s.length][s[0].length()];
		for (int i=0; i < s.length; i++)
			for (int j=0; j < s[i].length(); j++)
				if (s[i].charAt(j) == '.' ||
					s[i].charAt(j) == '#')
					res[i][j] = s[i].charAt(j);
				else
					res[i][j] = (charset.indexOf(s[i].charAt(j)) >= 0 ? 'b' : '.');
		return res;
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			// input
			int R = sc.nextInt();
			int C = sc.nextInt();
			String[] s = new String[R];
			for (int i=0; i < R; i++)
				s[i] = sc.next();
			
			State start = new State(construct(s, "ow"));
			State finish = new State(construct(s, "xw"));
			
			// output
			pw.print("Case #" + caseNum + ": ");
			
			Map<State, Integer> len = new HashMap<State, Integer>();
			Queue<State> q = new LinkedList<State>();
			q.add(start);
			len.put(start, 0);
			boolean find = false;
			while (q.size() > 0) {
				State cur = q.poll();
				int curLen = len.get(cur);
				if (cur.equals(finish)) {
					pw.println(curLen);
					find = true;
					break;
				}
				List<State> moves = cur.movesList();
				for (State next : moves)
					if (!len.containsKey(next)) {
						q.add(next);
						len.put(next, curLen + 1);
					}
			}
			System.out.println(len.size());
			if (!find) pw.println(-1);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new EZSocoban()).doMain();
	}
}