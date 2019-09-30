import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        List<Pair> pairs = new ArrayList<Pair>();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            pairs.add(new Pair(i, a[i]));
        }
        Collections.sort(pairs);
        for (int i = n - 1; i >= 0; i--) {
            System.out.println(pairs.get(i).from + 1);
        }

    }

}

class Pair implements Comparable {
    int from;
    int to;

    Pair(int from, int to) {
        this.from = from;
        this.to = to;
    }

    @Override
    public int compareTo(Object other) {
        Pair otherPair = (Pair) other;
        if (this.to == otherPair.to)
            return this.from - this.to;
        return this.to - otherPair.to;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.