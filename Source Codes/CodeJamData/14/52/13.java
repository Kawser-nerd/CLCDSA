import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			myDmg = nextInt();
			towerDmg = nextInt();
			n = nextInt();
			health = new int[n + 1];
			gold = new int[n];
			for (int i = 0; i < n; i++) {
				health[i] = nextInt();
				gold[i] = nextInt();
			}			
			cache.clear();
			out.println("Case #" + test + ": " + solve(0, 0, health[0], 0));
		}
	}

	Map<State, Integer> cache = new HashMap<State, Integer>();
	int n;
	int myDmg;
	int towerDmg;
	int[] health;
	int[] gold;

	private int solve(int shotsSaved, int monsterPos, int monsterHealth, int turn) {		
		if (monsterPos == n) {
			return 0;
		}
		if (monsterHealth <= 0) {
			return solve(shotsSaved, monsterPos + 1, health[monsterPos + 1], turn);
		}
		State st = new State(shotsSaved, monsterPos, monsterHealth, turn);
		if (cache.containsKey(st)) {
			return cache.get(st);
		}
		int need = (monsterHealth + myDmg - 1) / myDmg;
		int res = 0;
		if (turn == 0) {
			// skip my turn
			res = Math.max(res, solve(shotsSaved + 1, monsterPos, monsterHealth, 1 - turn));
			// use the bank
			if (need <= shotsSaved + 1) {
				res = Math.max(res, gold[monsterPos] + solve(shotsSaved + 1 - need, monsterPos + 1, health[monsterPos + 1], 1 - turn));
			}
		} else {
			// let it shoot
			res = Math.max(res, solve(shotsSaved, monsterPos, monsterHealth - towerDmg, 1 - turn));
			// interfere
			if (need <= shotsSaved) {
				res = Math.max(res, gold[monsterPos] + solve(shotsSaved - need, monsterPos + 1, health[monsterPos + 1], turn));
			}
		}
		cache.put(st, res);
		return res;
	}

	class State {
		int shotsSaved;
		int monsterPos;
		int monsterHealth;
		int turn;
		State(int shotsSaved, int monsterPos, int monsterHealth, int turn) {
			this.shotsSaved = shotsSaved;
			this.monsterPos = monsterPos;
			this.monsterHealth = monsterHealth;
			this.turn = turn;
		}
		@Override
		public boolean equals(Object obj) {
			State o = (State)obj;
			return shotsSaved == o.shotsSaved && monsterPos == o.monsterPos && monsterHealth == o.monsterHealth && turn == o.turn;
		}
		@Override
		public int hashCode() {
			int h = 0;
			h = 1000000007*h + shotsSaved;
			h = 1000000007*h + monsterPos;
			h = 1000000007*h + monsterHealth;
			h = 1000000007*h + turn;
			return h;
		}
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter(new FileWriter("B-large.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
