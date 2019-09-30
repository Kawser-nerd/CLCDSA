import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        boolean [] node = new boolean[n + 1];
        for (int i = 0; i < m; ++i) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            node[a] = !node[a];
            node[b] = !node[b];
        }
        for (int i = 1; i <= n; ++i) {
            if (node[i]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}