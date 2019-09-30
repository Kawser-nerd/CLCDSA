import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Arthur Petukhovsky petuhovskiy@yandex.ru
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int j = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            int k = in.nextInt();
            int jp[][] = new int[j][p];
            int js[][] = new int[j][s];
            int ps[][] = new int[p][s];
            boolean jps[][][] = new boolean[j][p][s];
            List<Abc> answer = new ArrayList<>();
            for (int offset = 0; offset < 1010; offset++) {
                for (int i = 0; i < j; i++) {
                    for (int i1 = 0; i1 < p; i1++) {
                        int i2 = (i + i1 + offset) % s;
                        if (jps[i][i1][i2]) continue;
                        jps[i][i1][i2] = true;
                        if (jp[i][i1] == k || js[i][i2] == k || ps[i1][i2] == k) continue;
                        jp[i][i1]++;
                        js[i][i2]++;
                        ps[i1][i2]++;
                        answer.add(new Abc(i, i1, i2));
                    }
                }
            }
            out.println(answer.size());
            answer.forEach(out::println);
        }

    }

    static class FastScanner {
        final static int BUFFER_SIZE = 65536;
        BufferedReader br;
        char[] buf = new char[BUFFER_SIZE];
        int len = 0;
        int it = 0;
        boolean end = false;

        boolean delim(char c) {
            return c == ' ' || c == '\n' || c == '\r';
        }

        void fillBuffer() {
            try {
                len = br.read(buf);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        void ensureBuffer() {
            if (it == len) {
                it = 0;
                fillBuffer();
                if (len == -1) end = true;
            }
        }

        void moveNext() {
            while (!end) {
                ensureBuffer();
                if (!delim(buf[it])) return;
                while (it < len && delim(buf[it])) it++;
            }
        }

        public String next() {
            moveNext();
            StringBuilder sb = new StringBuilder();
            while (!end) {
                int l = it;
                while (++it < len && !delim(buf[it])) ;
                sb.append(buf, l, it - l);
                ensureBuffer();
                if (delim(buf[it])) break;
            }
            return sb.toString();
        }

        public int nextInt() {
            moveNext();
            if (buf[it] == '-') {
                it++;
                return -nextInt();
            }
            if (buf[it] == '+') {
                it++;
                return nextInt();
            }
            int result = 0;
            while (!end) {
                int l = it;
                while (it < len && !delim(buf[it])) {
                    result = (result * 10) + buf[it] - '0';
                    it++;
                }
                ensureBuffer();
                if (end || delim(buf[it])) break;
            }
            return result;
        }

        public FastScanner(String file) {
            try {
                br = new BufferedReader(new FileReader(file), BUFFER_SIZE);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is), BUFFER_SIZE);
        }

    }

    static class Abc {
        int a;
        int b;
        int c;

        public Abc(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }


        public String toString() {
            return (a + 1) + " " + (b + 1) + " " + (c + 1);
        }

    }
}

