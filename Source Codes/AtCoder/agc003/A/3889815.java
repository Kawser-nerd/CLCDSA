import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        String s = sc.next();
        if (!s.contains("N") && s.contains("S") || s.contains("N") && !s.contains("S")) {
            System.out.println("No");
        } else if (!s.contains("W") && s.contains("E") || s.contains("W") && !s.contains("E")) {
                System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}