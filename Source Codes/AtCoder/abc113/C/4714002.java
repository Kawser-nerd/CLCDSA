import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        V[] a = new V[m];
        for (int i = 0; i < m; i++) {
            int p = sc.nextInt();
            int y = sc.nextInt();
            a[i] = new V(p, y, i);
        }

        Arrays.sort(a);

        int[] num = new int[n];
        String[] ans = new String[m];
        for (int i = 0; i < m; i++) {
            int p = a[i].p;
            num[p-1]++;

            String id = String.format("%06d%06d", p, num[p-1]);
            ans[a[i].i] = id;
        }
        
        for (String s : ans)
            System.out.println(s);
    }

    static class V implements Comparable<V> {
        int p, y, i;

        V(int p, int y, int i) {
            this.p = p;
            this.y = y;
            this.i = i;
        }

        public int compareTo(V o) {
            return y - o.y;
        }
    }
}