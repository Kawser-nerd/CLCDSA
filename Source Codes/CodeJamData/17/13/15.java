import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class C {
	
	public static void main(String[] args) throws Exception {
		Scanner in;
		PrintStream out;
		if (new File("c-large.in").exists()) {
			in = new Scanner(new File("c-large.in"));
			out = new PrintStream(new File("c-large.out"));
		} else if (new File("c-small.in").exists()) {
			in = new Scanner(new File("c-small.in"));
			out = new PrintStream(new File("c-small.out"));
		} else {
			in = new Scanner(new File("c-test.in"));
			out = System.out;
		}
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int Hd = in.nextInt();
			int Ad = in.nextInt();
			int Hk = in.nextInt();
			int Ak = in.nextInt();
			int B = in.nextInt();
			int D = in.nextInt();
			
			int solution = solve(Hd, Ad, Hk, Ak, B, D);
			
			String solVal = (solution == -1) ? "IMPOSSIBLE" : (solution + "");
			
			out.printf("Case #%d: %s%n", caseNum, solVal);
		}
		
		
		in.close();
		out.close();
	}
	
	private static int key(int curD, int curK, int b, int d) {
		return ((curD * 101 + curK) * 101 + b) * 101 + d;
	}
	
	private static int solve(int Hd, int Ad, int Hk, int Ak, int B, int D) {
		LinkedList<int[]> states = new LinkedList<int[]>();
		states.add(new int[] { Hd, Hk, 0, 0 });
		states.add(null);
		HashSet<Integer> seen = new HashSet<Integer>();
		int turns = 0;
		while (states.size() > 1) {
			int[] state = states.removeFirst();
			if (state == null) {
				turns++;
				states.addLast(null);
				continue;
			}
			if (state[1] <= 0) {
				return turns;
			}
			if (state[0] <= 0) continue;
			
			if (B == 0) state[2] = 0;
			if (D == 0) state[3] = 0;
			
			int key = key(state[0], state[1], state[2], state[3]);
			if (seen.contains(key)) continue;
			seen.add(key);
			
			int curAd = Ad + state[2] * B;
			int curAk = Math.max(0, Ak - state[3] * D);
			int nextAk = Math.max(0, curAk - D);

			states.addLast(new int[] { state[0] - curAk, state[1] - curAd, state[2], state[3] });
			states.addLast(new int[] { state[0] - curAk, state[1], state[2] + 1, state[3] });
			states.addLast(new int[] { Hd - curAk, state[1], state[2], state[3] });
			states.addLast(new int[] { state[0] - nextAk, state[1], state[2], state[3] + 1 });
		}
		return -1;
	}
}
