import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        char[] s = sc.next().toCharArray();
        int p = 0;
        for (char c : s) {
            if (c == 'p') {
                p++;
            }
        }
        System.out.println(s.length / 2 - p);
    }
}