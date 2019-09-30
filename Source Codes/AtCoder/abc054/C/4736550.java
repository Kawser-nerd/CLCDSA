import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static int n;
    private static List<List<Integer>> edge;

    private static int root(Set<Integer> set, int from, int i) {
        if(i == n - 1) return 1;

        int res = 0;
        for(int to : edge.get(from)) {
            if(!set.contains(to)) {
                Set<Integer> nset = new HashSet<>();
                for(int j : set) {
                    nset.add(j);
                }
                nset.add(to);
                res += root(nset, to, i + 1);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        int m = sc.nextInt();
        edge = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            edge.add(new ArrayList<>());
        }
        for(int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            edge.get(a).add(b);
            edge.get(b).add(a);
        }

        Set<Integer> set = new HashSet<>();
        set.add(0);
        System.out.println(root(set, 0, 0));

        sc.close();
    }
}