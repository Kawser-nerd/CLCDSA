import java.util.*;
import java.io.*;

public class Solution {
	class Testcase {
		int N;
		
		int inpCnt = 0;
		int[][] inputs;
		
		boolean[] used;
		int[] p;
		
		Map<String, Integer> moveCnt = new HashMap<String, Integer>();
		Map<String, Integer> nextMove = new HashMap<String, Integer>();
		
		int[] order;
		
		int[] ans;
		
		void process(char[] state) {
			String key = new String(state);
			if (moveCnt.containsKey(key)) return;
			
			for (int i=0; i < N; i++)
				if (state[i] == '0') {
					moveCnt.put(key, 0);
					nextMove.put(key, 0);
					return;
				}
			
			boolean[][] canBeAt = new boolean[N][N];
			for (int i=0; i < inpCnt; i++) {
				boolean ok = true;
				for (int j=0; j < N; j++)
					if (state[j] != '?' && (state[j] - '0') != inputs[i][j])
						ok = false;
				if (!ok) continue;
				for (int j=0; j < N; j++)
					canBeAt[j][inputs[i][j]] = true;
			}
			
			int res = Integer.MAX_VALUE;
			for (int i=0; i < N; i++) {
				if (state[i] != '?') continue;
				int tmp = 0;
				for (int j=0; j < N; j++)
					if (canBeAt[i][j]) {
						char[] newState = state.clone();
						newState[i] = (char)((int)'0' + j);
						process(newState);
						tmp = Math.max(tmp, moveCnt.get(new String(newState)) + 1);
					}
				res = Math.min(res, tmp);
			}
			
			int mask = 0;
			for (int i=0; i < N; i++) {
				if (state[i] != '?') continue;
				int tmp = 0;
				for (int j=0; j < N; j++)
					if (canBeAt[i][j]) {
						char[] newState = state.clone();
						newState[i] = (char)((int)'0' + j);
						tmp = Math.max(tmp, moveCnt.get(new String(newState)) + 1);
					}
				if (tmp == res)
					mask |= (1<<i);
			}
			
			moveCnt.put(key, res);
			nextMove.put(key, mask);
		}
		
		public Testcase() {	
		}
		
		public Testcase(int seed) {
			Random rnd = new Random(seed);
		}
		
		public void loadInput(Scanner sc) {
			N = sc.nextInt();
			order = new int[N];
			for (int i=0; i < N; i++)
				order[i] = sc.nextInt() - 1;
		}
		
		void go(int pos) {
			if (pos == N) {
				int[] dp = new int[N];
				for (int i=0; i<N; i++) {
					dp[i] = 1;
					for (int j=0; j<i; j++)
						if (p[j] > p[i])
							dp[i] = Math.max(dp[i], dp[j]+1);
					if (dp[i] >= 3) return;
				}
				inputs[inpCnt++] = p.clone();
				return;
			}
			for (p[pos]=0; p[pos]<N; p[pos]++)
				if (!used[p[pos]]) {
					used[p[pos]] = true;
					go(pos+1);
					used[p[pos]] = false;
				}
		}
		
		public void solveSlow() {
			inputs = new int[6000][];
			p = new int[N];
			used = new boolean[N];
			go(0);
			
			char[] state = new char[N];
			Arrays.fill(state, '?');
			process(state);
			
			for (int inpId = inpCnt - 1; inpId >= 0; inpId--) {
				state = new char[N];
				Arrays.fill(state, '?');
				boolean ok = true;
				for (int i = 0; i < N; i++) {
					int mask = nextMove.get(new String(state));
					if ((mask & (1<<order[i])) == 0) {
						ok = false;
						break;
					}
					state[order[i]] = (char)((int)'0' + inputs[inpId][order[i]]);
				}
				if (ok) {
					ans = inputs[inpId];
					break;
				}
			}
		}
		
		public void solveFast() {
		}
		
		public void printSelf(PrintWriter pw) {
			for (int i=0; i < N; i++) {
				pw.print(ans[i]+1);
				if (i+1<N) pw.print(" "); else pw.println();
			}
		}
		
		public boolean sameAnswers(Testcase other) {
			return false;
		}
	}
	
	final String AFTER_CASE = " ";
	
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("solving case " + caseNum);
			
			Testcase tc = new Testcase();
			
			tc.loadInput(sc);
			tc.solveSlow();
			
			pw.print("Case #" + (caseNum + 1) + ":");
			pw.print(AFTER_CASE);
			
			tc.printSelf(pw);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public void stresstest() {
		int it = 0;
		Random rnd = new Random();
		while (true) {
			it++;
			if (it % 1000 == 0)
				System.out.println(it + " iterations");
			
			int seed = rnd.nextInt();
			
			Testcase tc1 = new Testcase(seed);
			tc1.solveFast();
			
			Testcase tc2 = new Testcase(seed);
			tc2.solveSlow();
			
			if (!tc1.sameAnswers(tc2)) {
				System.out.println("ERROR: it failed");
				System.exit(0);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		new Solution().go();
	}
}
