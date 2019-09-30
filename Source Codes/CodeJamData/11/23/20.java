package codejam.y2011.r1b;

import org.junit.Test;

import java.io.*;
import java.util.*;

public class ProblemCSmall {

    private class Poly {
        public int[] v;

        public Poly(int[] v) {
            this.v = v;
        }
    }

    private class Wall implements  Comparable<Wall> {
        public int l, r;

        public int compareTo(Wall o) {
            int len = r - l;
            int leno = o.r - o.l;
            if (len < leno)
                return -1;
            if (len > leno)
                return 1;
            return 0;
        }
    }

    public void solve() throws IOException, Exception {
        int casenum = 1;
        String infile = "";
        String outfile = "";
        switch (casenum) {
            case 0:
                infile = "C-standard.in";
                outfile = "C-standard.out";
                break;
            case 1:
                infile = "C-small.in";
                outfile = "C-small.out";
                break;
            case 2:
                infile = "C-large.in";
                outfile = "C-large.out";
                break;
        }
        try {
            Reader reader = new FileReader(infile);
            Writer writer = new FileWriter(outfile);
            BufferedReader br = new BufferedReader(reader);
            StreamTokenizer st = new StreamTokenizer(reader);
            PrintWriter out = new PrintWriter(writer);

            int tt = Integer.valueOf(br.readLine());

            for (int kk = 0; kk < tt; kk++) {
                MyTokenizer tok = new MyTokenizer(br.readLine());
                int n = tok.getInteger();
                int m = tok.getInteger();

                Wall[] w = new Wall[m];
                tok = new MyTokenizer(br.readLine());
                for(int i=0;i<m;i++) {
                    w[i] = new Wall();
                    w[i].l = tok.getInteger() - 1;
                }
                tok = new MyTokenizer(br.readLine());
                for(int j=0;j<m;j++) {
                    w[j].r = tok.getInteger() - 1;
                }
                Arrays.sort(w);
                List<Poly> list = new ArrayList<Poly>();

                int[] v = new int[n];
                for(int i=0;i<n;i++)
                    v[i] = i;
                Poly p = new Poly(v);
                list.add(p);
                for(int i=0;i<m;i++) {
                    for(int j=0;j<list.size();j++) {
                        p = list.get(j);
                        int l = -1, r = -1;
                        for(int k=0;k<p.v.length;k++) {
                            if (p.v[k] == w[i].l || p.v[k] == w[i].l)
                                l = k;
                            if (p.v[k] == w[i].r || p.v[k] == w[i].r)
                                r = k;
                        }
                        if (l >= 0 && r >= 0) {
                            if (l > r) {
                                int tmp = l;
                                l = r;
                                r = tmp;
                            }
                            int[] v2 = new int[r - l + 1];
                            for(int k=l;k<=r;k++) {
                                v2[k-l] = p.v[k];
                            }
                            Poly p2 = new Poly(v2);
                            int[] v3 = new int[p.v.length - (r - l - 1)];
                            int pos = 0;
                            for(int k=0;k<=l;k++) {
                                v3[pos] = p.v[k];
                                pos++;
                            }
                            for(int k=r;k<p.v.length;k++) {
                                v3[pos] = p.v[k];
                                pos++;
                            }
                            Poly p3 = new Poly(v3);
                            list.remove(p);
                            list.add(p2);
                            list.add(p3);
                            break;
                        }
                    }
                }

                int maxc = 1;
                int[] result = new int[n];

                for(int c=2;c<=n;c++) {
                    int max = 1;
                    for(int i=0;i<n;i++)
                        max *= c;

                    boolean found = false;
                    for(int i=0;i<=max;i++) {
                        int[] color = new int[n];
                        int tmp = i;
                        for(int j=0;j<n;j++) {
                            color[j] = tmp % c;
                            tmp /= c;
                        }
                        boolean good = true;
                        for(int j=0;j<list.size();j++) {
                            p = list.get(j);
                            Set<Integer> set = new HashSet<Integer>();
                            for(int k=0;k<p.v.length;k++) {
                                if (!set.contains(color[p.v[k]]))
                                    set.add(color[p.v[k]]);
                            }
                            if (set.size() != c) {
                                good = false;
                                break;
                            }
                        }
                        if (good) {
                            if (maxc < c) {
                                maxc = c;
                                result = color;
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        break;
                }

                out.printf("Case #%d: %d\n", kk + 1, maxc);
                for(int i=0;i<n;i++) {
                    if (i > 0)
                        out.printf(" ");
                    out.printf("%d", result[i] + 1);
                }
                out.printf("\n");
            }

            br.close();
            out.close();
            reader.close();
            writer.close();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
        finally {
        }
    }

    private class MyTokenizer {
        private String s;
        private int cur;

        public MyTokenizer(String s) {
            this.s = s;
            cur = 0;
        }

        public void skip() {
            while (cur < s.length() && (s.charAt(cur) == ' ' || s.charAt(cur) == '\t' || s.charAt(cur) == '\n')) {
                cur++;
            }
        }

        public double getDouble() {
            skip();
            String snum = "";
            while (cur < s.length() && (s.charAt(cur) >= '0' && s.charAt(cur) <= '9' || s.charAt(cur) == '.' || s.charAt(cur) == '-')) {
                snum += s.charAt(cur);
                cur++;
            }
            if (snum.startsWith("."))
                snum = "0" + snum;
            return Double.valueOf(snum);
        }

        public int getInteger() {
            skip();
            String snum = "";
            while (cur < s.length() && (s.charAt(cur) >= '0' && s.charAt(cur) <= '9' || s.charAt(cur) == '.' || s.charAt(cur) == '-')) {
                snum += s.charAt(cur);
                cur++;
            }
            return Integer.valueOf(snum);
        }

        public String getString() {
            skip();
            String s2 = "";
            while (cur < s.length() && (((s.charAt(cur) >= 'a' && s.charAt(cur) <= 'z')) ||
                    ((s.charAt(cur) >= 'A' && s.charAt(cur) <= 'Z')) ||
                    ((s.charAt(cur) >= '0' && s.charAt(cur) <= '9')) ||
                    s.charAt(cur) == '_'
            )) {
                s2 += s.charAt(cur);
                cur++;
            }
            return s2;
        }

        public char getCurrentChar() throws Exception {
            if (cur < s.length())
                return s.charAt(cur);
            else
                throw new Exception("Current character out of string length");
        }

        public void moveNextChar() {
            if (cur < s.length())
                cur++;
        }

        public boolean isFinished() {
            return cur >= s.length();
        }
    }


    @Test
    public void main() {
        try {
            ProblemCSmall w = new ProblemCSmall();
            w.solve();
        }
        catch (Exception ex) {
            int i = 0;
        }
    }
}
