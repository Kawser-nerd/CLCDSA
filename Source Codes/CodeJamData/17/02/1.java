import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCount = in.nextInt();
        for (int testNo = 1; testNo <= testCount; testNo++) {
            solve(testNo, in);
        }
    }

    private static void solve(int testNo, Scanner in) {
        long n = in.nextLong();
        System.out.println("Case #" + testNo + ": " + calc(n));

    }

    private static long calc(long n) {
        tag:
        while (true) {
            char[] s = String.valueOf(n).toCharArray();
            for (int i = 0; i < s.length - 1; i++) {
                if (s[i] > s[i + 1]) {
                    for (int j = i + 1; j < s.length; j++) {
                        s[j] = '0';
                    }
                    n = Long.parseLong(String.valueOf(s)) - 1;
                    continue tag;
                }
            }
            return n;
        }
    }

}
