import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int k = sc.nextInt();
        List<Pair> lr = new ArrayList<Pair>();
        for (int i = 0; i < d; i++) {
            lr.add(new Pair(sc.nextInt(), sc.nextInt()));
        }
        List<Pair> st = new ArrayList<Pair>();
        for (int i = 0; i < k; i++) {
            st.add(new Pair(sc.nextInt(), sc.nextInt()));
        }
        for (int i = 0; i < k; i++) {
            int pos = st.get(i).from;
            int goal = st.get(i).to;
            if (st.get(i).go()) {
                for (int j = 0; j < d; j++) {
                    int s = lr.get(j).from;
                    int g = lr.get(j).to;
                    if (s <= pos) {
                        if (pos <= g) {
                            pos = g;
                        }
                    }
                    if (pos >= goal) {
                        System.out.println(j + 1);
                        break;
                    }

                }
            } else {
                for (int j = 0; j < d; j++) {
                    int s = lr.get(j).from;
                    int g = lr.get(j).to;
                    if (s <= pos) {
                        if (pos <= g) {
                            pos = s;
                        }
                    }
                    if (pos <= goal) {
                        System.out.println(j + 1);
                        break;
                    }

                }
            }
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

    public boolean go() {
        if (from < to) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public int compareTo(Object other) {
        Pair otherPair = (Pair) other;
        if (this.to == otherPair.to)
            return this.from - this.to;
        return this.to - otherPair.to;
    }
}