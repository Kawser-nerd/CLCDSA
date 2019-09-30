import java.util.Scanner;
import java.util.Locale;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

/**
 * @author Dmitry Shyshkin
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        String fname = "C-large";
        Scanner scanner = new Scanner(new File(fname + ".in"));
        scanner.useDelimiter("[\\n\\r\\s]+");
        PrintStream out = new PrintStream(fname + ".out");

        int n = scanner.nextInt();

        for (int num = 0; num < n; ++num) {
            double f = scanner.nextDouble();
            double R = scanner.nextDouble();
            double t = scanner.nextDouble();
            double r = scanner.nextDouble();
            double g = scanner.nextDouble();

            double mr = R - t - f;

            double x = r;

            if (g - 2 * f <= 0.000000001) {
                System.out.format("Case #%d: 1.000000\n", num + 1);
                out.format("Case #%d: 1.000000\n", num + 1);
                continue;
            }

            double s = 0;
            while (x < R) {
                double y = r;
                while (y < R) {
                    double lx = x + f;
                    double ly = y + f;
                    double rx = x + g - f;
                    double ry = y + g - f;

                    assert lx < rx && ly < ry;

                    double cly = Math.sqrt(mr * mr - lx * lx);
                    boolean crosslx = ly <= cly && ry >= cly;

                    double cry = Math.sqrt(mr * mr - rx * rx);
                    boolean crossrx = ly <= cry && ry >= cry;

                    double clx = Math.sqrt(mr * mr - ly * ly);
                    boolean crossly = lx <= clx && rx >= clx;

                    double crx = Math.sqrt(mr * mr - ry * ry);
                    boolean crossry = lx <= crx && rx >= crx;

                    if (lx * lx + ly * ly > mr * mr ) {
                        // fully not visible
                    } else if (rx * rx + ry * ry < mr * mr) {
                        s += (g - 2 * f) * (g - 2 * f);
                    } else if (crosslx && crossly) {
                        s += calci(mr, lx, clx) - ly * (clx - lx);
                    } else if (crossrx && crossry) {
                        s += calci(mr, crx, rx) - ly * (rx - crx) + (g - 2 * f) * (crx - lx); 
                    } else if (crossly && crossry){
                        s += calci(mr, ly, ry) - lx * (ry - ly);
                    } else if (crosslx && crossrx) {
                        s += calci(mr, lx, rx) - ly * (rx - lx);
                    } else {
                        assert false;
                    }
                    y += g + 2 * r;
                }
                x += g + 2 * r;
            }
            System.out.format("Case #%d: %f\n", num + 1, 1 - (s / (Math.PI * R * R / 4)));
            out.format("Case #%d: %f\n", num + 1, 1 - (s / (Math.PI * R * R / 4)));
        }

        scanner.close();
    }

    private static double calci(double a, double lx, double rx) {
        return calcf(a, rx) - calcf(a, lx);
    }

    private static double calcf(double a, double x) {
        return (x * Math.sqrt(a * a - x * x) + a * a * calcf2(a, x)) / 2;
    }

    private static double calcf2(double a, double x) {
        return Math.asin(x /a);
    }
}
