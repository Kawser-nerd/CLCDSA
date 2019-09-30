import java.util.*;

public class B {

    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int T = in.nextInt();
        for (int C = 1; C <= T; C++) {
            System.out.println("Case #" + C + ": " + solve());
        }
    }

    public static String solve() {
        String out = "";
        int B = in.nextInt();
        long M = in.nextLong() - 1;
        String binary = "";
        while(M > 0) {
            binary += M % 2;
            M = M / 2;
        }

        System.err.println(binary);

        if (binary.length() > B - 2) {
            out = "IMPOSSIBLE";
        } else {
            out = "POSSIBLE";
            for (int i = 0; i < B; i++) {
                String line = "";
                for (int j = 0; j <= i; j++) {
                    line += "0";
                }
                for (int j = 0; j < B - 2 - i; j++) {
                    line += "1";
                }
                if (i < B - 1) {
                    if (i == 0) {
                        line += "1";
                    } else if (i-1 < binary.length()) {
                        line += binary.charAt(i-1);
                    } else {
                        line += "0";
                    }
                }
                out += "\n" + line;
            }
        }
        return out;
    }
}
