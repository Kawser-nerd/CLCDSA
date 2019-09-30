import com.sun.org.apache.xerces.internal.impl.xpath.regex.Match;

import java.io.*;
import java.util.*;

public class R3 {
    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;

    static class Vertex {
        final int index;

        Vertex prev = this, next = this;

        Vertex(int index) {
            this.index = index;
        }
    }

    public void solveOne(String prefix) throws IOException {
        int n = nextInt();
        int m = nextInt();

        Vertex[] vs = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            vs[i] = new Vertex(i);
        }
        for (int i = 0; i < n; ++i) {
            int nx = (i + 1) % n;
            int pv = (i + n - 1) % n;
            vs[i].next = vs[nx];
            vs[i].prev = vs[pv];
        }

        int[] starts = new int[m];
        int[] finishes = new int[m];

        for (int i = 0; i < m; ++i) {
            starts[i] = nextInt() - 1;
        }
        for (int i = 0; i < m; ++i) {
            finishes[i] = nextInt() - 1;
        }
        List<Map<Integer, Vertex>> vertices = new ArrayList<Map<Integer, Vertex>>();
        vertices.add(new HashMap<Integer, Vertex>());
        for (int i = 0; i < n; ++i) {
            vertices.get(0).put(i, vs[i]);
        }

        for (int i = 0; i < m; ++i) {
            int from = starts[i];
            int to = finishes[i];

            for (int cmp = 0; cmp < vertices.size(); ++cmp) {
                Map<Integer, Vertex> oldComp = vertices.get(cmp);
                if (oldComp.containsKey(from) && oldComp.containsKey(to)) {
                    Map<Integer, Vertex> newComp = new HashMap<Integer, Vertex>();
                    vertices.add(newComp);

                    Vertex split1 = oldComp.get(from);
                    Vertex split2 = oldComp.get(to);

                    Vertex copy1 = new Vertex(split1.index);
                    Vertex copy2 = new Vertex(split2.index);

                    copy1.next = split1.next;
                    copy1.next.prev = copy1;

                    copy2.prev = split2.prev;
                    copy2.prev.next = copy2;
                    copy1.prev = copy2;
                    copy2.next = copy1;

                    split1.next = split2;
                    split2.prev = split1;

//                    System.err.println(oldComp.keySet());
                    oldComp.clear();

                    oldComp.put(split1.index, split1);
//                    System.err.print(split1.index + " ");
                    for (Vertex v = split1.next; v != split1; v = v.next) {
                        oldComp.put(v.index, v);
//                        System.err.print(v.index + " ");
                    }
//                    System.err.println();

                    newComp.put(copy1.index, copy1);
//                    System.err.print(copy1.index + " ");
                    for (Vertex v = copy1.next; v != copy1; v = v.next) {
                        newComp.put(v.index, v);
//                        System.err.print(v.index + " ");
                    }
//                    System.err.println();

//                    System.err.println();
                    break;
                }
            }
            if (vertices.size() != i + 2) {
                throw new AssertionError("Bridge not applied");
            }
        }
//        for (Map<Integer, Vertex> cmp : vertices) {
//            System.err.println(cmp.keySet());
//        }
        int maxSize = 0;
        for (Map<Integer, Vertex> cmp : vertices) {
            maxSize = Math.max(maxSize, cmp.size());
        }

        int[] ans = new int[n];
        Set<Integer> colors = new HashSet<Integer>();
        while (maxSize > 0) {
            do {
                boolean ok = true;
                for (Map<Integer, Vertex> cmp : vertices) {
                    colors.clear();
                    for (int idx : cmp.keySet()) {
                        colors.add(ans[idx]);
                    }
                    if (colors.size() != maxSize) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    out.println(prefix + " " + maxSize);
                    for (int i = 0; i < n; ++i) {
                        out.print(ans[i] + 1);
                        if (i + 1 == n) {
                            out.println();
                        } else {
                            out.print(" ");
                        }
                    }
                    return;
                }
            } while (next(ans, maxSize));
            --maxSize;
        }
        throw new AssertionError();
    }

    boolean next(int[] v, int max) {
        for (int i = 0; i < v.length; ++i) {
            ++v[i];
            if (v[i] == max) {
                v[i] = 0;
            } else {
                return true;
            }
        }
        return false;
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader("C.in"));
        out = new PrintWriter("C.out");

        int nTests = nextInt();

        for (int i = 1; i <= nTests; ++i) {
            solveOne(String.format("Case #%d:", i));
        }

        out.close();
        in.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new R3().run();
    }
}
