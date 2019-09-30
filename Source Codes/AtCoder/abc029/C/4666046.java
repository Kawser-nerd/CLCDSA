import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        solve(N, "");
    }

    public static void solve(int n, String str) {
        if (n == 0) {
            out.println(str);
        } else {
            n--;
            for (String c : new String[]{"a", "b", "c"}) {
                String nextStr = str + c;
                solve(n, nextStr);
            }
        }
    }
}