import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int h = sc.nextInt();
        int w = sc.nextInt();
        int count = 0;
        for (int i = 0; i < h; i++) {
            String row = sc.next();
            for (char c : row.toCharArray()) {
                if (c == '#') {
                    count++;
                }
            }
        }
        System.out.println(count == h + w - 1 ? "Possible" : "Impossible");
    }
}