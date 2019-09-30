import java.io.*;
import java.util.*;

public class C implements Runnable {

    private static final String DIR = "E:\\isinev\\programming\\contests\\gcj\\11round1B\\";

    String problemName = C.class.getName();

    static final int inf = (int) 1e9;

    //    String fileName = String.format(DIR + "%s-statement", problemName);
    public int n;
    String fileName = String.format(DIR + "%s-small-attempt3", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

    class V {
        int i;
        public Comparator<V> vcmp = new Comparator<V>() {
            public int compare(V o1, V o2) {
                int i1 = o1.i <= i ? o1.i + n : o1.i;
                int i2 = o2.i <= i ? o2.i + n : o2.i;
                return i1 - i2;
            }
        };
        TreeSet<V> e = new TreeSet<V>(vcmp);

        V(int i) {
            this.i = i;
        }

        public V(V vi) {
            this.i = vi.i;
            this.e = new TreeSet<V>(vi.e);
            this.vcmp = vi.vcmp;
        }

        @Override
        public String toString() {
            return "V[" +
                    "" + i +
                    ']';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            V v = (V) o;

            if (i != v.i) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return i;
        }
    }

    class P {
        List<V> v = new ArrayList<V>();
        Map<V, Integer> vc = new HashMap<V, Integer>();
        int cc;

        public void solve() {
            boolean found = false;
            for (V vi : v) {
                if (vi.e.size() > 0) {
                    found = true;
                    V vip = vi.e.first();

                    V vi1 = new V(vi);
                    V vi2 = new V(vi);
                    V vip1 = new V(vip);
                    V vip2 = new V(vip);
                    vi1.e.remove(vip);
                    vip1.e.remove(vi);
                    vi2.e.remove(vip);
                    vip2.e.remove(vi);


                    P p1 = new P();
                    P p2 = new P();
                    for (V vj : v) {
                        if (vj.equals(vi)) {
                            p1.v.add(vi1);
                            p2.v.add(vi2);
                        } else if (vj.equals(vip)) {
                            p1.v.add(vip1);
                            p2.v.add(vip2);
                        } else {
                            if (vi.vcmp.compare(vj, vip) < 0) {
                                p1.v.add(vj);
                                if (vj.e.contains(vi)) {
                                    vj.e.remove(vi);
                                    vj.e.add(vi1);
                                }
                                if (vj.e.contains(vip)) {
                                    vj.e.remove(vip);
                                    vj.e.add(vip1);
                                }
                                vi2.e.remove(vj);
                                vip2.e.remove(vj);
                            } else {
                                p2.v.add(vj);
                                if (vj.e.contains(vi)) {
                                    vj.e.remove(vi);
                                    vj.e.add(vi2);
                                }
                                if (vj.e.contains(vip)) {
                                    vj.e.remove(vip);
                                    vj.e.add(vip2);
                                }
                                vi1.e.remove(vj);
                                vip1.e.remove(vj);
                            }
                        }
                    }

                    p1.solve();
                    p2.solve();

                    cc = Math.min(p1.cc, p2.cc);

                    if (cc < p1.cc) {
                        reduce(p1.vc, vi, vip, cc);
                    }
                    if (cc < p2.cc) {
                        reduce(p2.vc, vi, vip, cc);
                    }

                    replace(p2.vc, vi, p1.vc.get(vi));
                    replace(p2.vc, vip, p1.vc.get(vip));
                    if (p2.vc.get(vi).equals(p2.vc.get(vip))) {
                        p2.vc.put(vi, p1.vc.get(vi));
                        p2.vc.put(vip, p1.vc.get(vip));
                    }
                    for (Map.Entry<V, Integer> e : p1.vc.entrySet()) {
                        vc.put(e.getKey(), e.getValue());
                    }
                    for (Map.Entry<V, Integer> e : p2.vc.entrySet()) {
                        vc.put(e.getKey(), e.getValue());
                    }
                    break;
                }
            }
            if (!found) {
                cc = v.size();
                for (int i = 0; i < v.size(); i++) {
                    vc.put(v.get(i), i + 1);
                }
            }
        }
    }

    void reduce(Map<V, Integer> m, V v1, V v2, int cc) {
        TreeMap<Integer, Integer> diff = new TreeMap<Integer, Integer>();
        int last = 1;
        diff.put(m.get(v1), last++);
        diff.put(m.get(v2), last++);
        for (Map.Entry<V, Integer> e : m.entrySet()) {
            if (!diff.containsKey(e.getValue())) {
                if (diff.size() < cc) {
                    Integer ev = e.getValue();
                    diff.put(ev, last++);
                    e.setValue(diff.get(ev));
                } else {
                    e.setValue(1);
                }
            } else {
                e.setValue(diff.get(e.getValue()));
            }
        }
    }

    void replace(Map<V, Integer> m, V vs, int ct) {
        int cs = m.get(vs);
        for (Map.Entry<V, Integer> e : m.entrySet()) {
            if (e.getValue() == cs) {
                e.setValue(ct);
            } else if (e.getValue() == ct) {
                e.setValue(cs);
            }
        }
    }

    public void run() {
        try {
            int nt = nextInt();
            cases_loop:
            for (int it = 1; it <= nt; it++) {
                n = nextInt();
                int m = nextInt();
                List<V> v = new ArrayList<V>();
                for (int i = 0; i < n; i++) {
                    v.add(new V(i + 1));
                }
                {
                    int[] ue = new int[m];
                    int[] ve = new int[m];
                    for (int i = 0; i < m; i++) {
                        ue[i] = nextInt();
                    }
                    for (int i = 0; i < m; i++) {
                        ve[i] = nextInt();
                        V v1 = v.get(ue[i] - 1);
                        V v2 = v.get(ve[i] - 1);
                        v1.e.add(v2);
                        v2.e.add(v1);
                    }
                }

//                if (it != 95) {
//                    continue;
//                }

                P p = new P();
                p.v = v;
                p.solve();

                out.format("Case #%d: %d%n", it, p.cc);
                for (int i = 0; i < v.size(); i++) {
                    out.format("%d%s", p.vc.get(v.get(i)), i == v.size() - 1 ? "\n" : " ");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    static {
        Locale.setDefault(Locale.US);
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public C() throws FileNotFoundException {
        in = new BufferedReader(new FileReader(new File(fileName + ".in")));
        out = new PrintWriter(fileName + ".out");
        st = new StringTokenizer("");
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Thread(new C()).start();
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(next());
    }
}