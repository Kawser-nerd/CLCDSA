import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        String s = sc.next();
        String t = sc.next();
        if (s.length() + t.length() <= n) {
            System.out.println(n);
        } else {
            for (int i = 0; i < s.length(); i++) {
                if (t.startsWith(s.substring(i))) {
                    System.out.println(s.length() + i);
                    return;
                }
            }
            System.out.println(s.length() + t.length());
        }
    }
}