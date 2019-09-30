import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for(int i = 0; i < m; i++) {
            a[i] = sc.nextInt()-1;
            b[i] = sc.nextInt()-1;
        }
        long[] answer = new long[m];
        answer[m - 1] = (long)n * (n-1) / 2;
        UnionFind uf = new UnionFind(n);
        for(int i = m - 1; i >= 1; i--) {
            answer[i - 1] = answer[i];
            if(uf.root(a[i]) != uf.root(b[i])) {
                answer[i - 1] -=(long)uf.size(a[i]) * uf.size(b[i]);
                uf.connect(a[i], b[i]);
            }
        }
        for(int i = 0; i < m; i++) {
            System.out.println(answer[i]);
        }
    }
}

class UnionFind {
    private int[] parents;

    UnionFind(int n) {
        parents = new int[n];
        Arrays.fill(parents, -1);
    }

    int size(int node) {
        return -parents[root(node)];
    }

    int root(int node) {
        if(parents[node] < 0) return node;
        else return parents[node] = root(parents[node]);
    }

    boolean connect(int node1, int node2) {
        int root1 = root(node1);
        int root2 = root(node2);
        if(root1 == root2) return false;
        else {
            if(root1 < root2) {
                int temp = root1;
                root1 = root2;
                root2 = temp;
            }
            parents[root1] += parents[root2];
            parents[root2] = root1;
            return true;
        }
    }
}