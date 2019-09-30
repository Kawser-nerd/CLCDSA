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
import java.util.LinkedList;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int pairs = 0;
            LinkedList<Character> list = new LinkedList<>();
            for (int i = 0; i < s.length(); i++) {
                char next = s.charAt(i);
                char last = list.size() > 0 ? list.peekLast() : 'x';
                if (last == next) {
                    pairs++;
                    list.pollLast();
                } else {
                    list.add(next);
                }
            }
            out.printf("Case #%d: %d\n", testNumber, pairs * 10 + 5 * list.size() / 2);
        }

    }
}

