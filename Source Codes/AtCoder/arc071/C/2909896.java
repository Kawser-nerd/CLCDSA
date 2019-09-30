import java.util.*;

public class Main {
    private class Query {
        int a, b, c, d;

        public Query(int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
    }

    public void main(Scanner sc) {
        char s[] = sc.next().toCharArray();
        char t[] = sc.next().toCharArray();
        int q = sc.nextInt();
        Query data[] = new Query[q];
        for (int i = 0; i < q; i++) {
            data[i] = new Query(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        int sums[] = new int[s.length + 1];
        int sumt[] = new int[t.length + 1];
        for (int i = 0; i < s.length; i++) {
            sums[i + 1] = (sums[i] + (s[i] == 'A' ? 1 : 2)) % 3;
        }
        for (int i = 0; i < t.length; i++) {
            sumt[i + 1] = (sumt[i] + (t[i] == 'A' ? 1 : 2)) % 3;
        }

        int a, b, c, d;
        for (int i = 0; i < q; i++) {
            a = sums[data[i].a - 1];
            b = sums[data[i].b];
            c = sumt[data[i].c - 1];
            d = sumt[data[i].d];

            System.out.println(((3 + b - a) % 3 == (3 + d - c) % 3) ? "YES" : "NO");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}