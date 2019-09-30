import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class A {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve());
        }
        out.close();
    }

    private Object solve() {
        int l = in.nextInt();

        int z = 10000;
        int[] min = new int[2 * z];
        int[] max = new int[2 * z];

        Arrays.fill(min, z);
        Arrays.fill(max, -z);

        int x = z;
        int y = 0;
        int d = 0;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        long s1 = 0;
        for (int i = 0; i < l; i++) {
            String s = in.next();
            int t = in.nextInt();
            for (int j = 0; j < t; j++) {
                for (int k = 0; k < s.length(); k++) {

                    min[x] = Math.min(min[x], y);
                    max[x] = Math.max(max[x], y);

                    char c = s.charAt(k);
                    if (c == 'F') {
                        s1 += dx[d] * y;
                        x += dx[d];
                        y += dy[d];
                    } else if (c == 'L') {
                        if (d == 0) d = 3; else d--;
                    } else if (c == 'R') {
                        if (d == 3) d = 0; else d++;
                    }
                }
            }
        }

        int xx = 0;
        for (int i = 0; i < 2 * z; i++) if (max[i] > max[xx]) xx = i;
        for (int i = 1; i < xx; i++) {
            max[i] = Math.max(max[i], max[i - 1]);
        }
        for (int i = 2 * z - 2; i > xx; i--) {
            max[i] = Math.max(max[i], max[i + 1]);
        }

        for (int i = 0; i < 2 * z; i++) if (min[i] < min[xx]) xx = i;
        for (int i = 1; i < xx; i++) {
            min[i] = Math.min(min[i], min[i - 1]);
        }
        for (int i = 2 * z - 2; i > xx; i--) {
            min[i] = Math.min(min[i], min[i + 1]);
        }


        long s2 = 0;

        for (int i = 1; i < 2 * z; i++) {
            int mx = Math.min(max[i - 1], max[i]);
            int mn = Math.max(min[i - 1], min[i]);
            if (mx > mn) {
                s2 += (mx - mn);
            }
        }

        System.out.println("" + s1 + " " + s2);
        return s2 - Math.abs(s1);
    }
}
