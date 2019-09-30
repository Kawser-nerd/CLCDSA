import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        ArrayList<Integer>[] ch;
        String f;
        Random rnd = new Random(238904782904782L);

        String rnd(int v) {
            StringBuilder res = new StringBuilder();
            res.append(f.charAt(v));
            ArrayList<String> z = new ArrayList<>();
            int total = 0;
            for (int u : ch[v]) {
                z.add(rnd(u));
                total += z.get(z.size() - 1).length();
            }
            int[] len = new int[z.size()];
            int[] pos = new int[z.size()];
            for (int i = 0; i < z.size(); i++) {
                len[i] = z.get(i).length();
            }
            while (total > 0) {
                int r = rnd.nextInt(total);
                int j = 0;
                while (r >= len[j]) {
                    r -= len[j];
                    j++;
                }
                res.append(z.get(j).charAt(pos[j]));
                pos[j]++;
                len[j]--;
                total--;
            }
            return res.toString();
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            System.err.println(testNumber);
            int n = in.nextInt() + 1;
            int[] p = new int[n];
            ch = new ArrayList[n + 1];
            for (int i = 0; i < n; i++) {
                ch[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                p[i] = in.nextInt();
                ch[p[i]].add(i);
            }
            f = "." + in.next();
            int m = in.nextInt();
            String[] w = new String[m];
            for (int i = 0; i < m; i++) {
                w[i] = in.next();
            }

            int[] cnt = new int[m];
            int ITER = 30000;
            for (int i = 0; i < ITER; i++) {
                String r = rnd(0);
                for (int j = 0; j < m; j++) {
                    if (r.indexOf(w[j]) != -1) {
                        cnt[j]++;
                    }
                }
            }
            out.print("Case #" + testNumber + ":");
            for (int i = 0; i < m; i++) {
                out.print(" " + 1.0 * cnt[i] / ITER);
            }
            out.println();
        }

    }
}

