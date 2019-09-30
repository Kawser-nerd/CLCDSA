import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int INF = (int) 1e6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskF.Vertex[] vs = new TaskF.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskF.Vertex(i + 1);
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskF.Vertex a = vs[in.nextInt() - 1];
                TaskF.Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            String likes = in.next();
            for (int i = 0; i < n; ++i) {
                vs[i].liked = likes.charAt(i) == '1';
            }
            vs[0].dfs1(null);
            long res = 1;
            for (TaskF.Vertex a : vs) {
                a.getMaxDepth(null);
            }
            for (TaskF.Vertex a : vs)
                if (a.liked) {
                    ++res;
                    res += Math.max(0, a.max2 - 1);
                }
            for (TaskF.Vertex a : vs)
                if (a.adj.size() >= 2) {
                    for (TaskF.Vertex b : a.adj) {
                        if (b.getMinPropagate(a) <= 0) {
                            ++res;
                        }
                    }
                    int minSimple = a.max3;
                    int minSimpleUpTo2 = a.max2;
                    for (TaskF.Vertex b : a.adj) {
                        int d = Math.max(1, b.getMinPropagate(a));
                        int dd = b.getMaxDepth(a) + 1;
                        minSimple = Math.min(minSimple, Math.max(dd, d));
                        if (b != a.maxVia && b != a.max2Via) {
                            minSimpleUpTo2 = Math.min(minSimpleUpTo2, Math.max(dd, d));
                        }
                        int maxd;
                        if (b == a.maxVia || b == a.max2Via) {
                            maxd = a.max3 - 1;
                        } else {
                            maxd = a.max2 - 1;
                        }
                        res += Math.max(0, Math.min(dd - 1, maxd) - d + 1);
                    }
                    if (!a.liked) {
                        res += Math.max(0, a.max3 - minSimple);
                        res += Math.max(0, a.max2 - Math.max(a.max3, minSimpleUpTo2));
                    }
                }
            out.println(res);
        }

        static class Vertex {
            int index;
            boolean liked;
            int subtreeLiked;
            TaskF.Vertex parent;
            List<TaskF.Vertex> adj = new ArrayList<>();
            int state = 0;
            TaskF.Vertex skipped = null;
            int max = 0;
            TaskF.Vertex maxVia = null;
            int max2 = 0;
            TaskF.Vertex max2Via = null;
            int max3 = 0;
            TaskF.Vertex max3Via = null;
            int min1p = INF;
            TaskF.Vertex min1pVia = null;
            int min2p = INF;
            TaskF.Vertex min2pVia = null;
            int minFromMax = INF;
            int minFromMax2 = INF;
            int state2 = 0;
            TaskF.Vertex skipped2 = null;

            public Vertex(int index) {
                this.index = index;
            }

            public int getMaxDepth(TaskF.Vertex except) {
                switch (state) {
                    case 0:
                        for (TaskF.Vertex v : adj)
                            if (v != except) {
                                int cur = 1 + v.getMaxDepth(this);
                                if (cur > max) {
                                    max3 = max2;
                                    max3Via = max2Via;
                                    max2 = max;
                                    max2Via = maxVia;
                                    max = cur;
                                    maxVia = v;
                                } else if (cur > max2) {
                                    max3 = max2;
                                    max3Via = max2Via;
                                    max2 = cur;
                                    max2Via = v;
                                } else if (cur > max3) {
                                    max3 = cur;
                                    max3Via = v;
                                }
                            }
                        skipped = except;
                        state = except == null ? 2 : 1;
                        return max;

                    case 1:
                        if (skipped == except) {
                            return max;
                        }
                    {
                        TaskF.Vertex v = skipped;
                        int cur = 1 + v.getMaxDepth(this);
                        if (cur > max) {
                            max3 = max2;
                            max3Via = max2Via;
                            max2 = max;
                            max2Via = maxVia;
                            max = cur;
                            maxVia = v;
                        } else if (cur > max2) {
                            max3 = max2;
                            max3Via = max2Via;
                            max2 = cur;
                            max2Via = v;
                        } else if (cur > max3) {
                            max3 = cur;
                            max3Via = v;
                        }
                        skipped = null;
                        state = 2;
                    }
                    // FALLSTHROUGH

                    case 2:
                        if (except == maxVia) {
                            return max2;
                        } else {
                            return max;
                        }

                    default:
                        throw new RuntimeException();
                }
            }

            public void dfs1(TaskF.Vertex parent) {
                this.parent = parent;
                subtreeLiked = liked ? 1 : 0;
                for (TaskF.Vertex v : adj)
                    if (v != parent) {
                        v.dfs1(this);
                        subtreeLiked += v.subtreeLiked;
                    }
            }

            public int getMinPropagate(TaskF.Vertex dest) {
                int res;
                switch (state2) {
                    case 0:
                        for (TaskF.Vertex child : adj)
                            if (child != dest) {
                                int c = child.getMinPropagate(this);
                                if (child == maxVia) {
                                    minFromMax = c;
                                } else if (child == max2Via) {
                                    minFromMax2 = c;
                                } else if (c < min1p) {
                                    min2p = min1p;
                                    min2pVia = min1pVia;
                                    min1p = c;
                                    min1pVia = child;
                                } else if (c < min2p) {
                                    min2p = c;
                                    min2pVia = child;
                                }
                            }
                        skipped2 = dest;
                        state2 = (dest == null ? 2 : 1);
                        if (dest == maxVia) {
                            int got = Math.min(Math.max(min1p, max2), Math.max(minFromMax2, max3));
                            res = got - 1;
                        } else if (dest == max2Via) {
                            int got = Math.min(Math.max(min1p, max), Math.max(minFromMax, max3));
                            res = got - 1;
                        } else if (dest == min1pVia) {
                            int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min2p), max));
                            res = got - 1;
                        } else {
                            int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min1p), max));
                            res = got - 1;
                        }

                        break;
                    case 1:
                        if (skipped2 == dest) {
                            if (dest == maxVia) {
                                int got = Math.min(Math.max(min1p, max2), Math.max(minFromMax2, max3));
                                res = got - 1;
                            } else if (dest == max2Via) {
                                int got = Math.min(Math.max(min1p, max), Math.max(minFromMax, max3));
                                res = got - 1;
                            } else if (dest == min1pVia) {
                                int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min2p), max));
                                res = got - 1;
                            } else {
                                int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min1p), max));
                                res = got - 1;
                            }
                            break;
                        }
                    {
                        TaskF.Vertex child = skipped2;
                        int c = child.getMinPropagate(this);
                        if (child == maxVia) {
                            minFromMax = c;
                        } else if (child == max2Via) {
                            minFromMax2 = c;
                        } else if (c < min1p) {
                            min2p = min1p;
                            min2pVia = min1pVia;
                            min1p = c;
                            min1pVia = child;
                        } else if (c < min2p) {
                            min2p = c;
                            min2pVia = child;
                        }
                        skipped2 = null;
                        state2 = 2;
                    }
                    // FALLSTHROUGH
                    case 2:
                        if (dest == maxVia) {
                            int got = Math.min(Math.max(min1p, max2), Math.max(minFromMax2, max3));
                            res = got - 1;
                        } else if (dest == max2Via) {
                            int got = Math.min(Math.max(min1p, max), Math.max(minFromMax, max3));
                            res = got - 1;
                        } else if (dest == min1pVia) {
                            int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min2p), max));
                            res = got - 1;
                        } else {
                            int got = Math.min(Math.max(minFromMax, max2), Math.max(Math.min(minFromMax2, min1p), max));
                            res = got - 1;
                        }
                        break;
                    default:
                        throw new RuntimeException();
                }

                if (liked) {
                    if (dest == maxVia) {
                        res = Math.min(res, max2 - 1);
                    } else {
                        res = Math.min(res, max - 1);
                    }
                }

                return Math.max(0, res);
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}