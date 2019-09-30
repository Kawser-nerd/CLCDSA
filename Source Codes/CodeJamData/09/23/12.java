import java.io.*;
import java.util.*;

public class C implements Runnable {
	private static String fileName = "c";
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";

    private Scanner in;
	private PrintWriter out;

    private C() throws FileNotFoundException {
        in = new Scanner(new File(inputFileName));
        out = new PrintWriter(outputFileName);
    }

    private final static int[] dx = {-1, 1, 0, 0};
    private final static int[] dy = {0, 0, -1, 1};

    private class State implements Comparable<State> {
        int x;
        int y;
        int value;
        char op;
        int rank;

        public State(int x, int y, int value, char op) {
            this.x = x;
            this.y = y;
            this.value = value;
            this.op = op;
        }

        public int compareTo(State o) {
            return op - o.op;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            return value == state.value && x == state.x && y == state.y;

        }

        public int hashCode() {
            int result;
            result = x;
            result = 31 * result + y;
            result = 31 * result + value;
            return result;
        }
    }


    private int rankCount;

    private void reRank(List<State> states) {
        Collections.sort(states);

        int curRank = -1;
        int prevOp = 0;

        for (State state : states) {
            if (state.op != prevOp) {
                curRank = newRank();
                prevOp = state.op;
            }
            state.rank = curRank;
        }
    }

    private int newRank() {
        return rankCount++;
    }


    private void solve() {
        int w = in.nextInt();
        int q = in.nextInt();

        char[][] b = new char[w][];

        for (int i = 0; i < w; i++) {
            String line = in.next();
            b[i] = line.toCharArray();
        }

        Map<Integer, String> ans = new HashMap<Integer, String>();
        Set<Integer> pending = new HashSet<Integer>();
        int[] reqs = new int[q];
        for (int i = 0; i < q; i++) {
            int req = in.nextInt();
            reqs[i] = req;
            pending.add(req);
        }

        Queue<State> queue = new ArrayDeque<State>();
        List<State> list = new ArrayList<State>();

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                if (b[i][j] >= '0' && b[i][j] <= '9') {
                    State state = new State(i, j, b[i][j] - '0', b[i][j]);
                    state.rank = b[i][j] - '0';
                    list.add(state);
                }
            }
        }
        reRank(list);
        queue.addAll(list);


        Set<State> visited = new HashSet<State>();
        visited.addAll(queue);
        Map<State, State> prev = new HashMap<State, State>();

        while (!queue.isEmpty() && !pending.isEmpty()) {
            State curr = queue.peek();
            List<State> process = new ArrayList<State>();
            while (!queue.isEmpty() && queue.peek().rank == curr.rank) {
                process.add(queue.poll());
            }

            Set<State> ns = new HashSet<State>();

            for (State state : process) {
                if (pending.contains(state.value)) {
                    StringBuilder result = new StringBuilder();

                    for (State res = state; res != null; res = prev.get(res)) {
                        result.append(res.op);
                    }
                    ans.put(state.value, result.reverse().toString());
                    pending.remove(state.value);
                }

                for (int dir = 0; dir < dx.length; dir++) {
                    int nx = state.x + dx[dir];
                    int ny = state.y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= w || ny >= w) {
                        continue;
                    }

                    int nv;
                    if (b[nx][ny] >= '0' && b[nx][ny] <= '9') {
                        int d = b[nx][ny] - '0';
                        if (state.op == '+') {
                            nv = state.value + d;
                        } else {
                            nv = state.value - d;
                        }
                    } else {
                        nv = state.value;
                    }

                    State newState = new State(nx, ny, nv, b[nx][ny]);
                    if (!visited.contains(newState)) {
                        ns.add(newState);
                        prev.put(newState, state);
                        visited.add(newState);
                    }
                }
            }

            List<State> toAdd = new ArrayList<State>(ns);
            reRank(toAdd);
            queue.addAll(toAdd);
        }

        for (int req : reqs) {
            out.println(ans.get(req));
        }
    }

	public void run() {
		try {
            int tests = in.nextInt();
            in.nextLine();
            for (int t = 1; t <= tests; t++) {
                out.println("Case #" + t + ": ");
                solve();
            }
        } finally {
            in.close();
            out.close();
        }
    }

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
		new Thread(new C()).start();
	}
}