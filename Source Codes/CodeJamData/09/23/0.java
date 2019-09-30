import java.util.*;
import java.io.*;

class CLargeBetter implements Runnable {
    HashMap[][] createHashMapArray(int w, int h) {
        HashMap[][] r = new HashMap[w][h];
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                r[i][j] = new HashMap();
            }
        }
        return r;
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("C-large.in"));
        PrintWriter out = new PrintWriter(new File("C-large.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            int n = in.nextInt();
            int q = in.nextInt();

            char[][] a = new char[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }

            String[] qans = new String[q];
            boolean[] req = new boolean[251];
            int left = 0;
            int[] len = new int[251];
            String[] val = new String[251];
            int[] que = new int[q];
            for (int i = 0; i < q; i++) {
                int p = in.nextInt();
                que[i] = p;
                if (!req[p]) {
                    left++;
                }
                req[p] = true;
            }
            out.println("Case #" + (test + 1) + ":");
            System.err.println(test);
            HashMap<Integer, String>[][] h = createHashMapArray(n, n);

            HashSet<Integer>[][] was = new HashSet[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    was[i][j] = new HashSet<Integer>();
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] >= '0' && a[i][j] <= '9') {
                        int v = a[i][j] - '0';
                        h[i][j].put(v, "" + a[i][j]);
                        was[i][j].add(v);
                        if (req[v]) {
                            val[v] = "" + a[i][j];
                            len[v] = 1;
                            req[v] = false;
                            left--;
                        }
                    }
                }
            }

            int[] dx = new int[]{0, 1, 0, -1};
            int[] dy = new int[]{1, 0, -1, 0};

            for (int s = 2; left > 0; s++) {
//                    System.err.println(s);
                HashMap<Integer, String>[][] nh = createHashMapArray(n, n);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (Integer v : h[i][j].keySet()) {
                            was[i][j].add(v);
                            for (int d = 0; d < 4; d++) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (!(ni >= 0 && ni < n && nj >= 0 && nj < n)) {
                                    continue;
                                }
                                char sgc = a[ni][nj];
                                int sg = sgc == '+' ? 1 : -1;
                                for (int e = 0; e < 4; e++) {
                                    ni = i + dx[d] + dx[e];
                                    nj = j + dy[d] + dy[e];
                                    if (!(ni >= 0 && ni < n && nj >= 0 && nj < n)) {
                                        continue;
                                    }
                                    int nv = v + sg * (a[ni][nj] - '0');
                                    if (was[ni][nj].contains(nv)) {
                                        continue;
                                    }
                                    String r = h[i][j].get(v) + sgc + a[ni][nj];
                                    if (nh[ni][nj].containsKey(nv)) {
                                        String or = nh[ni][nj].get(nv);
                                        if (r.compareTo(or) < 0) {
                                            nh[ni][nj].put(nv, r);
                                        }
                                    } else {
                                        nh[ni][nj].put(nv, r);
                                    }
                                    if (nv > 0 && nv < 251 && req[nv]) {
                                        if (val[nv] == null || r.compareTo(val[nv]) < 0) {
                                            val[nv] = r;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                h = nh;
                for (int i = 0; i < 251; i++) {
                    if (req[i] && val[i] != null) {
                        req[i] = false;
                        left--;
                    }
                }
            }

            for (int i = 0; i < q; i++) {
                out.println(val[que[i]]);
            }
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        new Thread(new CLargeBetter ()).start();
    }
}