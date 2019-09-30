import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	int n, m;
	String[] words, letters;
	String ls;
	int bestPos, bestMis;
	boolean[] exists = new boolean[26];

	void dfs(ArrayList<Integer> list, int pos, int mis) {
		if (list.size() == 0) return;
		if (list.size() == 1) {
			if (bestMis < mis || (bestMis == mis && bestPos > list.get(0))) {
				bestMis = mis;
				bestPos = list.get(0);
			}
			return;
		}
		Arrays.fill(exists, false);
		for (int i : list) {
			for (int j = 0; j < words[i].length(); j++) {
				exists[words[i].charAt(j)-'a'] = true;
			}
		}
		char reqCh = ls.charAt(pos); 
		if (exists[ls.charAt(pos)-'a']) {
			HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
			for (int i : list) {
				int mask = 0;
				for (int j = 0; j < words[i].length(); j++) {
					if (words[i].charAt(j) == reqCh) {
						mask += 1<<j;
					}
				}
				if (!map.containsKey(mask)) {
					map.put(mask, new ArrayList<Integer>());
				}
				ArrayList<Integer> nlist = map.get(mask);
				nlist.add(i);
			}
			for (int mask : map.keySet()) {
				if (mask == 0) {
					dfs(map.get(mask), pos+1, mis+1);
				} else {
					dfs(map.get(mask), pos+1, mis);
				}
			}
		} else {
			dfs(list, pos+1, mis);
		}
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			n = nextInt();
			m = nextInt();
			words = new String[n];
			letters = new String[m];
			for (int i = 0; i < n; i++) {
				words[i] = nextWord();
			}
			for (int i = 0; i < m; i++) {
				letters[i] = nextWord();
			}
			out.printf("Case #%d: ", t+1);
			for (int i = 0; i < m; i++) {
				ls = letters[i];
				ArrayList<Integer>[] list = new ArrayList[12];
				for (int j = 0; j < 12; j++) list[j] = new ArrayList<Integer>();
				for (int j = 0; j < n; j++) {
					list[words[j].length()].add(j);
				}
				bestPos = -1;
				bestMis = -1;
				for (int j = 0; j < 12; j++) {
					dfs(list[j], 0, 0);
				}
				out.print(words[bestPos]);
				out.print(" ");
			}
			out.println();
		}
		out.flush();
	}
}
