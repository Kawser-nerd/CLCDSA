
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 *
 * @author igor_kz
 */
public class PerfectHarmony {
    static int[] a;
    static int n;
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int test = Integer.parseInt(in.nextLine());
        for (int t = 1; t <= test; t++) {
            String nums = in.nextLine();
            StringTokenizer st = new StringTokenizer(nums);
            n = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            a = new int[n];
            nums = in.nextLine();
            st = new StringTokenizer(nums);
            for (int i = 0 ; i < n ; i++)
                a[i] = Integer.parseInt(st.nextToken());
            boolean ok = false;
            while (l <= h) {
                if (canBe(l)) {
                    ok = true;
                    break;
                }
                l++;
            }
            out.print("Case #" + t + ": ");
            if (ok) out.println(l); else out.println("NO");
        }
        out.close();
    }

    private static boolean canBe(int l) {
        for (int i = 0 ; i < n ; i++)
            if (l % a[i] == 0 || a[i] % l == 0) ; else return false;
        return true;
    }
}
