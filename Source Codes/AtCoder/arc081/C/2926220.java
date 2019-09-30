import java.util.*;

public class Main {
    public void main(Scanner sc) {
        char a[] = sc.next().toCharArray();
        int len = a.length;

        Map<Character, TreeSet<Integer>> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            map.putIfAbsent(a[i], new TreeSet<>());
            map.get(a[i]).add(i + 1);
        }

        int data[] = new int[len + 1];
        BitSet bset = new BitSet();
        data[len] = 0;
        for (int i = len - 1; i >= 0; i--) {
            bset.set(a[i] - 'a');
            data[i] = data[i + 1];
            if (bset.cardinality() == 26) {
                bset.clear();
                data[i]++;
            }
        }

        int p = 0;
        int ansLen = data[0] + 1;
        char ans[] = new char[ansLen];
        for (int i = 0; i < ansLen; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (!map.containsKey(c)) {
                    ans[i] = c;
                    p = len + 1;
                    break;
                } else {
                    Integer next = map.get(c).higher(p);
                    if (next == null || (data[p] - data[next] == 1)) {
                        ans[i] = c;
                        p = getOrDefault(next, len + 1);
                        break;
                    }
                }
            }
        }

        System.out.println(new String(ans));
    }

    private int getOrDefault(Integer n, int def) {
        return n == null ? def : n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}