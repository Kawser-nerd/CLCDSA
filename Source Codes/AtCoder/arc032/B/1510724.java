import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static class UnionFind {

        public int[] par;
        public int[] rank;

        void init(int n) {
            par = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                par[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x) {
            if (x == par[x]) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);

            if(x != y){
                if (rank[x] < rank[y]) {
                    par[x] = y;
                } else {
                    par[y] = x;
                    if (rank[x] == rank[y]) rank[x]++;
                }
            }
        }

        boolean same(int x, int y) {
            return find(x) == find(y);
        }

        int count(){
            int ret = 0;
            for(int i=0; i<par.length; i++){
                if(i == find(i)) ret++;
            }
            return ret;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        UnionFind unif = new UnionFind();
        unif.init(n);

        for(int i=0; i<m; i++){
            str = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]) -1;
            int b = Integer.parseInt(str[1]) -1;
            if(!unif.same(a, b)) unif.unite(a, b);
        }

        System.out.println(unif.count() - 1);
    }
}