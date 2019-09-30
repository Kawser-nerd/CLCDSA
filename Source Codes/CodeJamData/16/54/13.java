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

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Rene
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
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                String s = in.next();
                boolean allOne = true;
                for (int j = 0; j < s.length(); j++) {
                    allOne &= s.charAt(j) == '1';
                }
                ok &= !allOne;
            }
            String bad = in.next();
            out.printf("Case #%d: ", testNumber);
            if (!ok) out.println("IMPOSSIBLE");
            else {
                String y = "";
                for (int i = 0; i < l; i++) y += "0?";
                String z = "";
                for (int i = 0; i < l - 1; i++) z += "1";
                z += "0";
                out.printf("%s %s\n", y, z);
            }
        }

    }
}

