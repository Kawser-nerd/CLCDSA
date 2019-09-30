package round2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class C {
    private static final Integer INF = 1000000000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in)
    {
        int r = in.nextInt();
        int[] x1 = new int[r];
        int[] x2 = new int[r];
        int[] y1 = new int[r];
        int[] y2 = new int[r];
        for (int i = 0; i < r; i++) {
            x1[i] = in.nextInt();
            y1[i] = in.nextInt();
            x2[i] = in.nextInt() + 1;
            y2[i] = in.nextInt() + 1;
        }
        SortedSet<Integer> xSet = new TreeSet<Integer>();
        SortedSet<Integer> ySet = new TreeSet<Integer>();
        for (int i = 0; i < r; i++) {
            xSet.add(x1[i]);
            xSet.add(x2[i]);
            ySet.add(y1[i]);
            ySet.add(y2[i]);
        }
        List<Integer> xList = new ArrayList<Integer>(xSet);
        List<Integer> yList = new ArrayList<Integer>(ySet);
        Map<Integer, Integer> xMap = new HashMap<Integer, Integer>();
        Map<Integer, Integer> yMap = new HashMap<Integer, Integer>();
        int[] x = new int[xSet.size()];
        int[] y = new int[ySet.size()];
        for (int i = 0; i < xList.size(); i++) {
            x[i] = xList.get(i);
            xMap.put(x[i], i);
        }
        for (int i = 0; i < yList.size(); i++) {
            y[i] = yList.get(i);
            yMap.put(y[i], i);
        }

        for (int i = 0; i < r; i++) {
            x1[i] = xMap.get(x1[i]);
            x2[i] = xMap.get(x2[i]);
            y1[i] = yMap.get(y1[i]);
            y2[i] = yMap.get(y2[i]);
        }

        boolean[][] a = new boolean[x.length][y.length];
        for (int i = 0; i < r; i++) {
            for (int xx = x1[i]; xx < x2[i]; xx++) {
                for (int yy = y1[i]; yy < y2[i]; yy++) {
                    a[xx][yy] = true;
                }
            }
        }

//        for (int i = 0; i < x.length; i++) {
//            for (int j = 0; j < y.length; j++) {
//                System.out.print(a[i][j] ? "*" : ".");
//            }
//            System.out.println();
//        }

        SegList emptyList = new SegList(Arrays.asList(INF));
        SegList[][] b = new SegList[x.length][y.length];
        int res = 0;
        for (int xx = 0; xx < x.length - 1; xx++) {
            for (int yy = 0; yy < y.length - 1; yy++) {
                SegList q1 = (xx == 0) ? emptyList : b[xx - 1][yy];
                SegList q2 = (yy == 0) ? emptyList : b[xx][yy - 1];
                SegList q = new SegList(new ArrayList<Integer>());
                boolean l = a[xx][yy];
                if (l) {
                    q.t.add(0);
                }
                boolean l1 = (xx == 0) ? false : a[xx - 1][yy];
                boolean l2 = (yy == 0) ? false : a[xx][yy - 1];
                if (l && !l1 && !l2) {
                    q.t.add(1);
                    res = Math.max(res, 1 + (x[xx + 1] - x[xx] + y[yy + 1] - y[yy]));
                    l = false;
                    //System.out.println("1d");
                }
                if (!l && l1 && l2) {
                    q.t.add(1);
                    l = true;
                    //System.out.println("1b");
                }
                int i = l1 ? 1 : 0;
                int j = l2 ? 1 : 0;
                while (i < q1.t.size() || j < q2.t.size()) {
                    int t1 = q1.t.get(i) + (xx > 0 ? (x[xx] - x[xx - 1]) : 0);
                    int t2 = q2.t.get(j) + (yy > 0 ? (y[yy] - y[yy - 1]) : 0);
                    int t = Math.min(t1, t2);
                    if (t >= INF) break;
                    if (t1 == t) {
                        i++;
                        l1 = !l1;
                    }
                    if (t2 == t) {
                        j++;
                        l2 = !l2;
                    }
                    if (l && !l1 && !l2) {
                        l = false;
                        q.t.add(t);
                        //System.out.println(t + " d");
                        res = Math.max(res, t + (x[xx + 1] - x[xx] + y[yy + 1] - y[yy]));
                    }
                    if (!l && l1 && l2) {
                        l = true;
                        //System.out.println(t + " b");
                        q.t.add(t);
                    }
                }
                q.t.add(INF);
                b[xx][yy] = q;
                //System.out.println(xx + " " + yy + " " + q.t);
            }
        }



        return "" + (res - 2);
    }

    private class SegList {
        private SegList(List<Integer> t) {
            if (t == null) {
                throw new RuntimeException();
            }
            this.t = t;
        }

        List<Integer> t;
    }
}