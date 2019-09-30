import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0 ; i < m ; i++) {
            a[i] = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
        }
        long[] ans = new long[m];
        ans[m - 1] = (long) n * (n - 1) / 2;

        UnionFindTree uf = new UnionFindTree(n);

        for (int i = m - 1; i >= 1; i--) {
            ans[i - 1] = ans[i];
            if (uf.find(a[i]) != uf.find(b[i])) {
                ans[i - 1] -= (long) uf.size(a[i]) * uf.size(b[i]);
                uf.union(a[i], b[i]);
            }
        }

        for (int i = 0; i < m; i++) {
            System.out.println(ans[i]);
        }
    }

    static class UnionFindTree {
        ArrayList<Integer> parent;

        public UnionFindTree(int size) {
            parent = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                parent.add(-1);
            }
        }

        public boolean union(int x, int y) {

            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }

            if (size(x) < size(y)) {
                int temp = x;
                x = y;
                y = temp;
            }

            parent.set(x, parent.get(x) + parent.get(y));

            parent.set(y, x);
            return true;
        }

        //????????root?id????
        public int find(int i) {
            if (parent.get(i) < 0) {
                return i;
            } else {
                int root = find(parent.get(i));
                parent.set(i, root);
                return root;
            }
        }

//        //????????????
//        public boolean same(int x, int y) {
//            return find(x) == find(y);
//        }

        public int size(int x) {
            return -parent.get(find(x));
        }
    }

}