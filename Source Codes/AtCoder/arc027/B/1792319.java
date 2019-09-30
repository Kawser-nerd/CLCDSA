import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String s1 = sc.next();
        String s2 = sc.next();
        HashSet<Character> set = new HashSet<>();
        UnionFind unionFind = new UnionFind();

        for (int i=0; i<N; i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            Boolean c1IsDigit = Character.isDigit(c1);
            Boolean c2IsDigit = Character.isDigit(c2);
            if (!c1IsDigit && c2IsDigit) {
                set.add(c1);
            }
            else if (c1IsDigit && !c2IsDigit) {
                set.add(c2);
            }
            else if (!c1IsDigit && !c2IsDigit){
                unionFind.union(c1, c2);
            }
        }

        for (char c: (HashSet<Character>)set.clone()) {
            set.add(unionFind.getParentChar(c));
        }

        long result = 1;
        boolean first = true;
        for (char c: s1.toCharArray()) {
            if (!Character.isDigit(c) && !set.contains(unionFind.getParentChar(c))) {
                result *= first ? 9 : 10;
                set.add(unionFind.getParentChar(c));
            }
            first = false;
        }

        System.out.println(result);

    }
}

class UnionFind {
    private int[] tree = new int[26];

    public UnionFind() {
        Arrays.fill(tree, -1);
    }

    public int find(char c) {
        return _find((int)c - 65);
    }

    public char getParentChar(char c) {
        return (char)(find(c)+65);
    }

    private int _find(int x) {
        if (tree[x] >= 0) {
            tree[x] = _find(tree[x]);
            return tree[x];
        }
        else {
            return x;
        }
    }

    public void union(char c1, char c2) {
        if (find(c1) != find(c2)) {
            tree[find(c1)] = find(c2);
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.