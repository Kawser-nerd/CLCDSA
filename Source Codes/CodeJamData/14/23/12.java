import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Locale;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    int[] zip;
    int n, m;
    ArrayList<Integer>[] adj;
    boolean[] deleted, visited;

    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        zip = Input.intArray(in, n);
        //noinspection unchecked
        adj = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            adj[i] = new ArrayList<>();
        while (m --> 0) {
            int a = in.nextInt()-1, b = in.nextInt()-1;
            adj[a].add(b);
            adj[b].add(a);
        }
        deleted = new boolean[n];
        visited = new boolean[n];
        connected = new boolean[n];
        int root = 0;
        for (int i = 1; i < n; ++i)
            if (zip[i] < zip[root])
                root = i;
        ArrayList<Integer> path = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        res.add(zip[root]);
        path.add(root);
        visited[root] = true;
        while (res.size() < n) {
            ArrayList<Pair<Integer>> moves = new ArrayList<>();
            for (int i = path.size()-1; i >= 0; --i) {
                int u = path.get(i);
                for (int v : adj[u])
                    if (!visited[v] && !deleted[v])
                        moves.add(new Pair<>(i, v));
                deleted[u] = true;
                if (!graphIsConnected(root))
                    break;
            }
            for (int u : path)
                deleted[u] = false;

            Pair<Integer> bestMove = moves.get(0);
            for (Pair<Integer> move: moves) {
                if (zip[move.second] < zip[bestMove.second] ||
                        (zip[move.second] == zip[bestMove.second] && move.first > bestMove.first)) {
                    bestMove = move;
                }
            }

            int fromI = bestMove.first;
            for (int i = path.size()-1; i > fromI; --i) {
                deleted[path.get(i)] = true;
                path.remove(i);
            }
            int to = bestMove.second;
            path.add(to);
            visited[to] = true;
            res.add(zip[to]);
        }

        out.print("Case #" + testNumber + ": ");
        for (int i : res)
            out.print(i);
        out.println();
    }


    boolean[] connected;
    private boolean graphIsConnected(int root) {
        Arrays.fill(connected, false);
        go(root);
        for (int i = 0; i < n; ++i)
            if (!deleted[i] && !connected[i])
                return false;
        return true;
    }

    private void go(int u) {
        if (connected[u] || deleted[u])
            return;
        connected[u] = true;
        for (int v : adj[u])
            go(v);
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

abstract class Input {
    public static int[] intArray(TokenizerReader in, int size) {
        int[] res = new int[size];
        for (int i = 0; i < size; ++i)
            res[i] = in.nextInt();
        return res;
    }

}

class Pair<T> {
    public final T first, second;

    public Pair(T first, T second) {
        this.first = first;
        this.second = second;
    }

    public int hashCode() {
        return first.hashCode() * 31013 + second.hashCode();
    }

    public boolean equals(Object obj) {
        Pair<T> p = (Pair<T>) obj;
        return first.equals(p.first) && second.equals(p.second);
    }
}

