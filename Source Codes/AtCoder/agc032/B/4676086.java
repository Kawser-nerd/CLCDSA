import java.util.ArrayList;
import java.util.Scanner;

class Problem {
    private int N;

    Problem() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
    }

    void solve() {
        int n = N % 2 == 1 ? N : N + 1;
        int M = N % 2 == 1 ? (N - 1) / 2 : N / 2;

        ArrayList<String> edges = new ArrayList<>();

        for (int i = 1; i < M; i++) {
            edges.add(i + " " + (i + 1));
            edges.add(i + " " + (n - (i + 1)));
            edges.add((i + 1) + " " + (n - i));
            edges.add((n - (i + 1)) + " " + (n - i));
        }

        if (N % 2 == 0 && M > 2) {
            edges.add(1 + " " + M);
            edges.add(1 + " " + (M + 1));
            edges.add(M + " " + (n - 1));
            edges.add((M + 1) + " " + (n - 1));
        } else if (N % 2 == 1) {
            edges.add(1 + " " + N);
            edges.add((n - 1) + " " + N);
            if (M > 1) {
                edges.add(M + " " + N);
                edges.add((M + 1) + " " + N);
            }
        }
        System.out.println(edges.size());
        for (String e: edges){
            System.out.println(e);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        new Problem().solve();
    }
}