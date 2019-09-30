import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class C {

    private static final int INF = 100000;

    void solve(String s) {
        int[][] a = new int[s.length() + 1][6];
        for (int prefixLen = 1; prefixLen <= s.length(); prefixLen++) {
            if (prefixLen % 100 == 0) {
                System.err.println("pL = " + prefixLen);
            }
//            System.err.println("prefixLen = " + prefixLen);
            for (int i = 0; i < a[prefixLen].length; i++) {
                a[prefixLen][i] = INF;
            }
            char[] t = s.substring(0, prefixLen).toCharArray();
            ford:
            for (char[] d : dict) {
                if (d.length > t.length) {
                    continue ford;
                }
                int first = -1;
                int prev = -INF;
                int count = 0;
                for (int j = 0; j < d.length; j++) {
                    if (d[j] != t[t.length - d.length + j]) {
                        if (first == -1) {
                            first = j;
                        }
                        if (j - prev < 5) {
                            continue ford;
                        }
                        prev = j;
                        count++;
                    }
                }
//                System.err.println("d = " + d + ", count = " + count);
                if (count == 0) {
                    for (int i = 0; i < a[prefixLen].length; i++) {
                        a[prefixLen][i] = Math.min(a[prefixLen][i], a[prefixLen - d.length][Math.max(i - d.length, 0)]);
                    }
                } else {
                    int shouldBeEquals = Math.max(5 - first, 0);
                    int x = a[t.length - d.length][shouldBeEquals];
                    int lastEquals = Math.min(d.length - prev, 5);
                    a[prefixLen][lastEquals] = Math.min(a[prefixLen][lastEquals], x + count);
                }
            }
            for (int i = a[prefixLen].length - 2; i >= 0; i--) {
                a[prefixLen][i] = Math.min(a[prefixLen][i], a[prefixLen][i + 1]);
            }
        }
        System.out.println(a[s.length()][0]);
    }

    ArrayList<char[]> dict = new ArrayList<char[]>();

    void run() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
        while (true) {
            String s = br.readLine();
            if (s == null) {
                break;
            }
            dict.add(s.toCharArray());
        }
        Scanner in = new Scanner(System.in);
//        Scanner in = new Scanner(new File("test"));
        int t = in.nextInt();
        for (int it = 0; it < t; it++) {
            System.out.print("Case #" + (it + 1) + ": ");
            String s = in.next();
            solve(s);
        }
    }


    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
