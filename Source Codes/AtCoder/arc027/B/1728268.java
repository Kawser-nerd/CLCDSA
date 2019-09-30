import java.util.*;

public class Main {
    private static int n;
    private static String s1;
    private static String s2;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        s1 = scan.next();
        s2 = scan.next();
    }

    public static void main(String args[]) {
        //??
        input();

        UnionFind uf = new UnionFind(10 + 'Z' - 'A' + 1);
        int count[] = new int['Z' - 'A' + 1];

        for(int i = 0;i < n;i++){
            if(s1.charAt(i) >= 'A' && s1.charAt(i) <= 'Z' && count[s1.charAt(i) - 'A'] == 0){
                count[s1.charAt(i) - 'A'] = 10 - (i == 0 ? 1: 0);
            }
            if(s2.charAt(i) >= 'A' && s2.charAt(i) <= 'Z' && count[s2.charAt(i) - 'A'] == 0){
                count[s2.charAt(i) - 'A'] = 10 - (i == 0 ? 1: 0);
            }

            int i1,i2;

            if(s1.charAt(i) >= '0' && s1.charAt(i) <= '9') i1 = s1.charAt(i) - '0';
            else i1 = s1.charAt(i) - 'A' + 10;

            if(s2.charAt(i) >= '0' && s2.charAt(i) <= '9') i2 = s2.charAt(i) - '0';
            else i2 = s2.charAt(i) - 'A' + 10;

            uf.union(i1,i2);
        }

        for(int i = 0;i < 10;i++){
            for(int j = 10;j <= 10 + 'Z' - 'A';j++){
                if(uf.same(i,j)) count[j - 10] = 1;
            }
        }

        long ret = 1;
        for(int i = 10;i <= 'Z' - 'A' + 10;i++){
            if(count[i-10] != 0){
                boolean flag = true;
                for(int j = 10;j < i;j++){
                    if(uf.same(i,j)) flag = false;
                }
                if(flag) ret *= count[i-10];
            }
        }

        System.out.println(ret);
    }

    private static class UnionFind {

        private int[] parent;    //????
        private int[] rank;      //?? or ??

        /**<h1>???????</h1>
         * <p></p>
         * @param size ? ????
         */
        public UnionFind(int size) {
            parent = new int[size+1];
            rank = new int[size];

            for (int i = 0; i < size; i++) makeSet(i);
        }

        /**<h1>????????</h1>
         * <p>????????????????
         * <br>????????????????????????</p>
         * @param x ? ???
         */
        public void makeSet(int x) {
            parent[x] = x;
            rank[x] = 0;
        }

        /**<h1>x, y ????????????</h1>
         * <p>?????????????</p>
         * @param x ? ???1
         * @param y ? ???2
         */
        public void union(int x, int y) {
            final int xRoot = find(x);
            final int yRoot = find(y);

            if (rank[xRoot] > rank[yRoot]) parent[yRoot] = xRoot;        //x ?????
            else if(rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;        //y ?????
            else if (xRoot != yRoot) {        //???????????
                parent[yRoot] = xRoot;        //x ?????
                rank[xRoot]++;                //x ????????
            }
        }

        /**<h1>?????????????</h1>
         * <p>??????????????????</p>
         * @param x ? ???
         * @return<b>int</b> ? ???????
         */
        public int find(int x) {
            if (x != parent[x]) {    //??????
                parent[x] = find(parent[x]);    //???????(????)
            }
            return parent[x];
        }

        /**<h1>????????????????</h1>
         * <p>??????????????????</p>
         * @param x ? ???1
         * @param y ? ???2
         * @return<b>boolean</b> ? true = ?????????
         */
        public boolean same(int x, int y) {
            return find(x) == find(y);
        }
    }
}