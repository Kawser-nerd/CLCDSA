import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
        int[] b = new int[n];
        List<Pair> pairs = new ArrayList<Pair>();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            pairs.add(new Pair(a[i], b[i]));
        }
        Collections.sort(pairs);

        long cnt = 0;
        sc.close();
        for (int i = 0; i < n; i++) {
            int value = pairs.get(i).value;
            cnt += value;
            if (cnt >= k) {
                System.out.println(pairs.get(i).key);
                return;
            }
        }

    }
}

class Pair implements Comparable {
    int key;
    int value;

    Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Object other) {
        Pair otherPair = (Pair) other;
        if (this.key == otherPair.key)
            return this.value - this.value;
        return this.key - otherPair.key;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.