import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Pair> pairs = new ArrayList<Pair>();
        for (int i = 0; i < m; i++) {
            pairs.add(new Pair(sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(pairs);

        int hashi = pairs.get(0).to;
        int ans = 1;
        for (int i = 0; i < m; i++) {
            int left = pairs.get(i).from;
            if (left < hashi)
                continue;
            hashi = pairs.get(i).to;
            ans++;
        }
        System.out.println(ans);

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