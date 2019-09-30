import java.util.*;

public class Main {
    static int[][] dp;
    static Scanner sc;
    static int n;
    static int m;
    static Node[] nodes;
    static boolean[] contains;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        nodes = new Node[n];
        contains = new boolean[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            nodes[a].nexts.add(nodes[b]);
            nodes[b].nexts.add(nodes[a]);
        }

        LinkedList<Integer> path = new LinkedList<>();

        path.add(nodes[0].a);
        path.add(nodes[0].nexts.stream().findAny().get().a);
        for (Integer i: path) {
            contains[i] = true;
        }
        boolean flag = true;
        while (flag) {
            flag = false;
            int first = path.getFirst();
            for (Node node : nodes[first].nexts) {
                if(contains[node.a]) {
                    continue;
                }
                contains[node.a] = true;
                path.addFirst(node.a);
                flag =true;
                break;
            }
            int last = path.getLast();
            for (Node node : nodes[last].nexts) {
                if(contains[node.a]) {
                    continue;
                }
                contains[node.a] = true;
                path.addLast(node.a);
                flag = true;
                break;
            }
        }
        System.out.println(path.size());
        for (Integer i : path) {
            System.out.print((i + 1) + " ");
        }
    }

    static class Node{
        int a;
        Set<Node> nexts;

        public Node(int a) {
            this.a = a;
            this.nexts = new HashSet<>();
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Node node = (Node) o;

            return a == node.a;
        }

        @Override
        public int hashCode() {
            return a;
        }
    }
}