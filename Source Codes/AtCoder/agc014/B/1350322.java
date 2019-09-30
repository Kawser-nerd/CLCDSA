import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readHead(in.readLine());
		for (; solver.hasNext();) {
			solver.readBody(in.readLine());
		}
		solver.solve();
	}
}

class Solver {
	int N;
	int M;
	int cnt;
	HashMap<Integer, Boolean> ChkMap;

	public void init() {
		N = 0;
		M = 0;
		cnt = 0;
	}

	public void readHead(String str) {
		String[] strArr = str.split(" ");
		N = Integer.parseInt(strArr[0]);
		M = Integer.parseInt(strArr[1]);
		ChkMap = new HashMap<Integer, Boolean>();
	}

	public boolean hasNext() {
		return cnt < M;
	}

	public void readBody(String str) {
		// System.out.println(str);
		String[] strArr = str.split(" ");
		for (int i = 0; i < strArr.length; i++) {
			int v = Integer.parseInt(strArr[i]);
			if (ChkMap.containsKey(v)) {
				ChkMap.put(v, !ChkMap.get(v));
			} else {
				ChkMap.put(v, true);
			}
		}
		cnt++;
	}

	public void solve() {
		for (int i : ChkMap.keySet()) {
			if (ChkMap.get(i)) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}