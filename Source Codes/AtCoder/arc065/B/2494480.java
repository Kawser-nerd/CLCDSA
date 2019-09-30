import java.util.*;
import java.util.stream.Collectors;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ss = br.readLine().split(" ");
        int n = Integer.parseInt(ss[0]), k = Integer.parseInt(ss[1]), l = Integer.parseInt(ss[2]);
        UnionFind ufr = new UnionFind(n), uft = new UnionFind(n);
        for(int i = 0; i < k; i++) {
            ss = br.readLine().split(" ");
            ufr.unite(Integer.parseInt(ss[0]) - 1, Integer.parseInt(ss[1]) - 1);
        }
        for(int i = 0; i < l; i++) {
            ss = br.readLine().split(" ");
            uft.unite(Integer.parseInt(ss[0]) - 1, Integer.parseInt(ss[1]) - 1);
        }
        Map<String, Integer> map = new HashMap<>();
        List<String> keys = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String key = new StringBuilder().append(ufr.find(i)).append(' ').append(uft.find(i)).toString();
            keys.add(key);
            Integer val = map.get(key);
            map.put(key, val == null ? 1 : val + 1);            
        }
        System.out.println(keys.stream()
            .map(key -> map.get(key))
            .map(val -> String.valueOf(val))
            .collect(Collectors.joining(" ")));
    }
}

class UnionFind {
    int[] parent;
    int[] rank;

    public UnionFind(int size) {
        parent = new int[size];
        rank = new int[size];
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }

    public void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return;
        }
        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x] ++;
        }
    }

    public boolean same (int x, int y) {
        return find(x) == find(y);
    }

    public void show() {
        System.out.println(Arrays.toString(parent));
    }
}