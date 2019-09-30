import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int p[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        int data[] = new int[n];
        init(n, data);
        for (int i = 0; i < m; i++) {
            link(sc.nextInt(), sc.nextInt(), data);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (isSame(i + 1, p[i], data)) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    public void init(int n, int data[]) {
        for (int i = 0; i < n; i++) {
            data[i] = i + 1;
        }
    }

    public void link(int x, int y, int data[]) {
        data[root(x, data) - 1] = root(y, data);
    }

    public boolean isSame(int x, int y, int data[]) {
        return root(x, data) == root(y, data);
    }

    public int root(int p, int data[]) {
        return (data[p - 1] == p) ? p : (data[p - 1] = root(data[p - 1], data));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}