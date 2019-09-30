import java.util.Scanner;
import java.util.Locale;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Problem implements Runnable {
    private final Scanner scanner;
    private final PrintWriter printer;

    private String solveSingle() {
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        int isect = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] > a[j] && b[i] < b[j]) {
                    isect++;
                }
            }
        }

        return String.valueOf(isect);
    }

    private void solve() throws Exception {
        int cases = scanner.nextInt();
        for (int test = 1; test <= cases; test++) {
            printer.println("Case #" + test + ": " + solveSingle());
        }
    }

    private Problem() throws FileNotFoundException {
        scanner = new Scanner(new File("a-large.in"));
        printer = new PrintWriter(new File("a-large.out"));
    }

    public void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        } finally {
            printer.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        new Thread(new Problem()).start();
    }
}
