import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().solve(new Scanner(System.in), new PrintWriter(System.out));
    }

    private void solve(Scanner in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        ArrayList<Integer> segs = new ArrayList<>();
        int size = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ++size;
            } else {
                segs.add(size);
                size = 1;
            }
        }
        segs.add(size);
        segs.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });
        int ans = 0;
        for (int i = 0; i < segs.size() - k; ++i) {
            ans += segs.get(i);
        }
        System.out.println(ans);
    }
}