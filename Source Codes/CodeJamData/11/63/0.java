import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	final int M = 250000;
	final int S = 30;
	int[] tape = new int[2 * M + 1];
	ArrayList<Statement> program = new ArrayList<Statement>();
	int cur = 0;
	
	class Statement {
		boolean terminate;
		int state;
		int mark;
		int newState;
		int newMark;
		int move;

		public Statement(int state, int mark, int newState, int newMark, int move) {
			this.state = state;
			this.mark = mark;
			this.newState = newState;
			this.newMark = newMark;
			this.move = move;
			this.terminate = false;
		}
		
		public Statement(int state, int mark) {
			this.state = state;
			this.mark = mark;
			this.terminate = true;
		}
		
		public long code() {
			return C.code(state, mark);
		}
		
		@Override
		public String toString() {
			return state + " " + mark + " -> " + (terminate ? "R" : (direction(move) + " " + newState + " " + newMark));
		}
	}
	
	static char direction(int move) {
		switch (move) {
		case 1:
			return 'E';
		case -1:
			return 'W';
		default:
			throw new RuntimeException();
		}
	}
	
	static long code(int state, int mark) {
		return ((long) state << 32) | mark;
	}
	
	int model() {
		System.out.print("Modeling: (" + program.size() + " statements) ");
		if (program.size() > S) {
			throw new RuntimeException("Program is too large: " + program.size());
		}
		Map<Long, Statement> what2do = new HashMap<Long, Statement>();
		for (Statement s : program) {
			if (what2do.containsKey(s.code())) {
				System.out.println("!!!!: " + what2do.get(s.code()));
				throw new RuntimeException("Duplicate " + s);
			}
			what2do.put(s.code(), s);
		}
		Arrays.fill(tape, 0);
		int state = 0;
		int pos = M;
		int max = pos;
		for (int i = 0; i < M; i++) {
			long situation = code(state, tape[pos]);
			Statement s = what2do.get(situation);
			if (s == null) {
				throw new RuntimeException("Don't know what to do! " + state + " " + tape[pos]);
			}
			if (s.terminate) {
				System.out.println("Position = " + (pos - M) + ", " + (i + 1) + " steps.");
				return pos;
			}
			state = s.newState;
			tape[pos] = s.newMark;
			pos += s.move;
			max = Math.max(max, pos);
//			System.out.println();
//			for (int j = M; j <= max; j++) {
//				System.out.print(tape[j]);
//				if (j == pos) {
//					System.out.print("[" + state + "]");
//				}
//				System.out.print(" ");
//			}
		}
		throw new RuntimeException(M + " iterations");
	}

	void p(int state, int mark, int newState, int newMark, int move) {
		program.add(new Statement(state, mark, newState, newMark, move));
//		System.out.println(new Statement(state, mark, newState, newMark, move));
	}
	
	void t(int state, int mark) {
		program.add(new Statement(state, mark));
	}
	
	void i(int mark) {
		p(cur, 0, cur + 1, mark, +1);
		cur++;
	}
	
	private void solve() {
		int n = in.nextInt();
		program.clear();
		cur = 0;
		if (n < S) {
			for (int i = 0; i < n; i++) {
				i(0);
			}
			t(cur, 0);
		} else {
			int p = 1;
			int q = 1;

			int _PLUS = 200;
			int _COPY = 100;
			int _MAIN = _COPY + p;
			int _CONT = _MAIN + 1;
			int _MOVE = _CONT + 1;
			int _DONE = _MOVE + 1;
			
			int A = 10;
			int X = 1;
			int Y = 2;
			int T = 9;
//			int V = 8;
			
			while (n % 4 != 2) {
				n--;
				i(0);
			}
			int k = 2;
			while ((8 << k) - 6 < n) {
				k++;
			}
			int d = ((8 << k) - 6 - n) / 4;
			for (int i = 0; i < k; i++) {
				i(A + 1 - ((d >> i) & 1));
			}
//			int k = 6;
//			for (int i = 0; i < k; i++) {
//				i(A + 1);
//			}
			i(X);
			p(cur, 0, _MAIN, T, -1);
			
			
			p(_MAIN, A + 1, _COPY, A + 2, +1);
			p(_MAIN, A + 2, _MOVE, A, +1);
			p(_MOVE, T, _MOVE, X, +1);
//			for (int i = 1; i <= q; i++) {
//				p(_MAIN, A + i, _COPY, A + i - 1, +1);
//			}
//			p(_PLUS, T, _PLUS, T, +1);
//			p(_PLUS, X, _PLUS, X, +1);
//			p(_PLUS, 0, _MAIN, X, -1);
			
			p(_MAIN, A, _COPY, Y, +1);
			p(_COPY, X, _COPY, X, +1);
			p(_COPY, T, _COPY, T, +1);
			
			for (int i = 0; i < p - 1; i++) {
				p(_COPY + i, 0, _COPY + i + 1, X, +1);
			}
			p(_COPY + p - 1, 0, _MAIN, X, -1);
			
			p(_MAIN, X, _MAIN, X, -1);
			p(_MAIN, T, _MAIN, T, -1);
			p(_MAIN, Y, _CONT, X, +1);
			
			p(_CONT, X, _COPY, Y, +1);
			p(_CONT, T, _MOVE, X, +1);
			p(_MOVE, X, _MOVE, X, +1);
			p(_MOVE, 0, _MAIN, T, -1);
			
			p(_MAIN, 0, _DONE, 0, +1);
			p(_DONE, X, _DONE, X, +1);
			p(_DONE, T, _DONE, T, +1);
			t(_DONE, 0);
		}
		model();
		out.println(program.size());
		for (Statement s : program) {
			out.println(s);
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			new C().solve();
		}
		in.close();
		out.close();
	}
}