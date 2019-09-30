import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();

        int p[] = new int[n];
        int data[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
            data[i] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            int x = root(sc.nextInt(), data);
            int y = root(sc.nextInt(), data);
            if (x != y) {
                data[x - 1] = y;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (isSame(p[i], i + 1, data)) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    public boolean isSame(int x, int y, int data[]) {
        return root(x, data) == root(y, data);
    }

    public int root(int p, int data[]) {
        if (data[p - 1] == p) {
            return p;
        }

        return data[p - 1] = root(data[p - 1], data);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}