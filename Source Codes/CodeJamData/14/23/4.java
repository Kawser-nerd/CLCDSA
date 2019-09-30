import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        OutputStream outputStream;
        try {
            inputStream = new FileInputStream("in");
            outputStream = new FileOutputStream("output");
//            outputStream = System.out;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
}

class Task {
    int[] color;
    int n;
    int m;
    String[] cost;
    ArrayList[] g;
    String ans;
    int[] from;
    int[] to;
    int[] used;
    public void solve(InputReader in, PrintWriter out) {
        int countTest = in.nextInt();
        for (int test = 1; test <= countTest; test++) {
            out.print("Case #" + test + ": ");
            ans = "";
            n = in.nextInt();
            m = in.nextInt();
            used = new int[n];
            from = new int[m];
            to = new int[m];
            cost = new String[n];
            for (int i = 0; i < n; i++) {
                cost[i] = in.nextLine();
            }
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<Integer>(0);
            }
            for (int i = 0; i < m; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                from[i] = x;
                to[i] = y;
                g[x].add(y);
                g[y].add(x);
            }
            color = new int[n];
            String minCost = "zzzzz";
            int start = 0;
            for (int i = 0; i < n; i++) {
                color[i] = 1;
                if (can()) {
                    if (cost[i].compareTo(minCost) < 0) {
                        minCost = cost[i];
                        start = i;
                    }
                }
                color[i] = 0;
            }
            color[start] = 1;
            ArrayList<Integer> way = new ArrayList<Integer>(0);
            way.add(start);
            ans += minCost;
            for (int i = 0; i < n - 1; i++) {
                minCost = "zzzzz";
                int nextV = 0;
                int prevV = 0;
                for (int o = way.size() - 1; o >= 0; o--) {
                    int x = way.get(o);
                    for (int j = 0; j < g[x].size(); j++) {
                        Integer y = (Integer) g[x].get(j);
                        if (color[y] == 0) {
                            color[y] = 1;
                            if (can()) {
                                if (cost[y].compareTo(minCost) < 0) {
                                    minCost = cost[y];
                                    prevV = o + 1;
                                    nextV = y;
                                }
                            }
                            color[y] = 0;
                        }
                    }
                    color[x] = 2;
                }
                ans += minCost;
                while (way.size() > prevV) {
                    color[way.get(way.size() - 1)] = 2;
                    way.remove(way.size() - 1);
                }
                way.add(nextV);
                for (int j = 0; j < way.size(); j++) {
                    color[way.get(j)] = 1;
                }
            }
            out.println(ans);
        }
    }
    boolean can() {
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                used[i] = 0;
            } else {
                used[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (color[i] == 1) {
                dfs(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                return false;
            }
        }
        return true;
    }
    void dfs(int x) {
        used[x] = 1;
        for (int i = 0; i < g[x].size(); i++) {
            Integer y = (Integer) g[x].get(i);
            if (used[y] == 0) {
                dfs(y);
            }
        }
    }
}

class InputReader {
    private static BufferedReader bufferedReader;
    private static StringTokenizer stringTokenizer;

    public InputReader(InputStream inputStream) {
        bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            try {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return stringTokenizer.nextToken();
    }

    public String nextLine() {
        try {
            return bufferedReader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
