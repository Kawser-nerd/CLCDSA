import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	class State {
		int id;
		int col;

		public State(int id_, int col_) {
			id = id_;
			col = col_;
		}
	}

	int R, C, N;

	void run() {
		Scanner sc = new Scanner(System.in);
		C = sc.nextInt();
		R = sc.nextInt();
		N = sc.nextInt();
		ArrayList<State> lis = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			boolean f = true;
			ArrayList<State> tmp = new ArrayList<>();
			for (int t = 0; t < 2; ++t) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				f &= x == 0 || x == C || y == 0 || y == R;
				if (f)
					tmp.add(new State(edge_id(x, y), i));
			}
			if (f) {
				lis.addAll(tmp);
			}
		}
		Collections.sort(lis, new Comparator<State>() {
			@Override
			public int compare(State o1, State o2) {
				return Integer.compare(o1.id, o2.id);
			}
		});
		ArrayDeque<Integer> stk = new ArrayDeque<Integer>();
		int[] col = new int[N];
		for (int i = 0; i < lis.size(); ++i) {
			State s = lis.get(i);
			if (col[s.col] == 0) {
				stk.addLast(s.col);
				++col[s.col];
			} else {
				int pre = stk.pollLast();
				if (pre != s.col) {
					System.out.println("NO");
					return;
				}
				--col[s.col];
			}
		}
		System.out.println("YES");
	}

	int edge_id(int x, int y) {
		if (y == 0) {
			return x;
		} else if (x == C) {
			return C + y;
		} else if (y == R) {
			return C + R + C - x;
		} else if (x == 0) {
			return C + R + C + R - y;
		} else {
			tr(x, y, C, R);
			throw new AssertionError();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}