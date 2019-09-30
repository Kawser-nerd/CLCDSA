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
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ":");
            int n = in.nextInt();
            List<String> answer = new ArrayList<>();
            int count = 0;
            char who = '@';
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                char now = (char) ('A' + i);
                while (count > 0 && x > 0) {
                    answer.add("" + who + now);
                    x--;
                    count--;
                }
                if (x > 0) {
                    count = x;
                    who = now;
                }
            }
            while (count > 0) {
                if (count > 1) {
                    answer.add("" + who + who);
                    count -= 2;
                    continue;
                }
                count--;
                answer.add("" + who);
            }
            for (int i = answer.size() - 1; i >= 0; i--) out.print(" " + answer.get(i));
            out.println();
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
}

