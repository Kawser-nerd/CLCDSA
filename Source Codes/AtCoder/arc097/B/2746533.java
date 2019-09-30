import java.util.*;

public class Main {
    static int n, m;
    static int[] p;
    static int modP = 1000000007;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        p = new int[n];

        UF uf = new UF(n);
        for(int i = 0; i < n; i++) p[i] = in.nextInt();
        for(int i = 0; i < m; i++) {
            int x = in.nextInt()-1;
            int y = in.nextInt()-1;
            uf.union(x, y);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(uf.same(i, p[i]-1)) cnt++;
        }
        print(cnt);
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }
}

class UF {
    int[] table, ranks;

    UF(int s) {
        table = new int[s];
        ranks = new int[s];
        for(int i = 0; i < s; i++) {
            table[i] = i;
        }
    }

    public int find(int x) {
        if(table[x] != x) table[x] = find(table[x]);

        return table[x];
    }

    public void union(int x , int y) {
        int xR = find(x);
        int yR = find(y);
        if(xR == yR) return;

        if(ranks[xR] < ranks[yR]) {
            table[xR] = yR;
        }else{
            table[yR] = xR;
            if(ranks[xR] == ranks[yR]) ranks[xR]++;
        }
    }

    public boolean same(int x, int y) {
        return find(x) == find(y);
    }
}