import java.util.Scanner;
import java.util.Locale;
import java.util.Arrays;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Load implements Runnable {
    private final Scanner scanner;
    private final PrintWriter printer;

    private String solveSingle() {
        int l = scanner.nextInt();
        int p = scanner.nextInt();
        int c = scanner.nextInt();

        int mults = 0;
        long ll = l;
        while (ll * c < p) {
            ll *= c;
            mults++;
        }

        int naive = 0;
        while ((1 << naive) <= mults) {
            naive++;
        }

        return String.valueOf(naive);
    }

    private void solve() throws Exception {
        int cases = scanner.nextInt();
        for (int test = 1; test <= cases; test++) {
            printer.println("Case #" + test + ": " + solveSingle());
        }
    }

    private Load() throws FileNotFoundException {
        scanner = new Scanner(new File("b-large.in"));
        printer = new PrintWriter(new File("b-large.out"));
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
        new Thread(new Load()).start();
    }
}