import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "D-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("d.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int l = in.nextInt();
            Set<String> g = new HashSet<>();
            for (int i = 0; i < n; i++) {
                g.add(in.next());
            }
            String b = in.next();
            String notb = "";
            for (int i = 0; i < l; i++) {
                if (b.charAt(i) == '0') {
                    notb += "1";
                } else {
                    notb += "0";
                }
            }

            String ans = "";
            if (g.contains(b)) {
                ans = "IMPOSSIBLE";
            } else {
                if (l > 1) {
                    for (int i = 0; i < l; i++) {
                        ans = ans + notb.charAt(i) + "?";
                    }
                    ans = ans + " ";
                    for (int i = 0; i < l - 1; i++) {
                        ans = ans + notb.charAt(i) + b.charAt(i);
                    }
                } else {
                    ans = notb + " " + notb + "?";
                }
            }
            out.println("Case #" + testNumber + ": " + ans);
        }

    }
}

