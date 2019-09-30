import java.util.*;

public class Main {
    private class Node {
        List<Integer> path = new ArrayList<>();
    }

    public void main(Scanner sc) {
        int n = sc.nextInt();
        Node nodes[] = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }

        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            nodes[a - 1].path.add(b);
            nodes[b - 1].path.add(a);
        }

        int tmp = nodes[0].path.get(0);
        BitSet bset = new BitSet();
        bset.set(1);
        bset.set(tmp);
        LinkedList<Integer> ans = new LinkedList<>();
        ans.add(1);
        ans.add(tmp);
        boolean send = false;
        boolean eend = false;
        while (!send || !eend) {
            if (!send) {
                send = true;
                int s = ans.getFirst();
                for (Integer sp : nodes[s - 1].path) {
                    if (!bset.get(sp)) {
                        bset.set(sp);
                        ans.addFirst(sp);
                        send = false;
                        break;
                    }
                }
            }
            if (!eend) {
                eend = true;
                int e = ans.getLast();
                for (Integer ep : nodes[e - 1].path) {
                    if (!bset.get(ep)) {
                        bset.set(ep);
                        ans.addLast(ep);
                        eend = false;
                        break;
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (Integer p : ans) {
            sb.append(p);
            sb.append(" ");
        }
        System.out.println(ans.size());
        System.out.println(sb.toString().trim());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}