import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    int go(String[] s, String[] t, boolean[] change, int alrChanged) {
        HashMap<String, Integer> hm = new HashMap<>();
        int n = s.length;
        for (int i = 0; i < n; i++) {
            char[] a = new char[alrChanged];
            for (int j = 0; j < alrChanged; j++) {
                if (change[j]) {
                    a[j] = (char) ('1' + '0' - s[i].charAt(j));
                } else {
                    a[j] = s[i].charAt(j);
                }
            }
            String str = new String(a);
            Integer cnt = hm.get(str);
            if (cnt == null)
                cnt = 0;
            cnt++;
            hm.put(str, cnt);
        }
        for (int i = 0; i < n; i++) {
            char[] a = new char[alrChanged];
            for (int j = 0; j < alrChanged; j++) {
                a[j] = t[i].charAt(j);
            }
            String str = new String(a);
            Integer cnt = hm.get(str);
            if (cnt == null)
                cnt = 0;
            cnt--;
            hm.put(str, cnt);
            if (cnt < 0)
                return Integer.MAX_VALUE / 2;
        }
        if (alrChanged == change.length)
            return 0;
        change[alrChanged] = false;
        int res = go(s, t, change, alrChanged + 1);
        change[alrChanged] = true;
        res = Math.min(res, go(s, t, change, alrChanged + 1) + 1);
        return res;
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int l = in.nextInt();
        String[] outlets = new String[n];
        String[] devices = new String[n];
        for (int i = 0; i < n; i++) {
            outlets[i] = in.next();
        }
        for (int i = 0; i < n; i++) {
            devices[i] = in.next();
        }
        int res = go(outlets, devices, new boolean[l], 0);
        out.println(res >= Integer.MAX_VALUE / 2 ? "NOT POSSIBLE" : res);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }
}