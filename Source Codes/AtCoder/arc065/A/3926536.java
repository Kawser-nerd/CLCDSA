import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        char[][] addeds = {"dream".toCharArray(), "dreamer".toCharArray(), "erase".toCharArray(), "eraser".toCharArray()};
        char[] s = sc.next().toCharArray();

        int endIndex = s.length;
        while (endIndex > 0) {
            boolean f = false;
            for (char[] added : addeds) {
                if (isMatch(s, added, endIndex)) {
                    endIndex -= added.length;
                    f = true;
                    break;
                }
            }

            if (f == false) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    boolean isMatch(char[] s, char[] added, int endIndex) {
        if (endIndex - added.length < 0) {
            return false;
        }

        for (int i = 0; i < added.length; i++) {
            if (added[i] != s[endIndex - added.length + i]) {
                return false;
            }
        }

        return true;
    }
}