import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static double[][] e;
    static long[][] nodes;
    static long[] barriers;
    static boolean[] flags;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int xs = sc.nextInt();
        int ys = sc.nextInt();
        int xt = sc.nextInt();
        int yt = sc.nextInt();
        int n = sc.nextInt();
        e = new double[n + 2][n + 2];
        nodes = new long[n + 2][2];
        barriers = new long[n + 2];
        flags = new boolean[n + 2];
        nodes[0][0] = xs;
        nodes[0][1] = ys;
        nodes[1][0] = xt;
        nodes[1][1] = yt;
        for (int i = 0; i < n; i++) {
            nodes[i + 2][0] = sc.nextInt();
            nodes[i + 2][1] = sc.nextInt();
            barriers[i + 2] = sc.nextInt();
        }
        calc_edge();

        PriorityQueue<Path> queue = new PriorityQueue<>(Comparator.comparingDouble(p -> p.score));
        queue.add(new Path(0, 0));
        while(!flags[1]) {
            Path next = queue.poll();
            if(flags[next.current]) {
                continue;
            }
            flags[next.current] = true;
            if(next.current == 1) {
                System.out.println(next.score);
                return;
            }
            for (int i = 0; i < flags.length; i++) {
                if(!flags[i]) {
                    queue.add(new Path(next.score + e[next.current][i], i));
                }
            }
        }
    }

    static class Path {
        double score;
        int current;
        Path(double score, int current) {
            this.score = score;
            this.current = current;
        }
    }

    static void calc_edge() {
        for (int i = 0; i < barriers.length; i++) {
            for (int j = i; j < barriers.length; j++) {
                double tmp = Math.pow((nodes[i][0] - nodes[j][0]) * (nodes[i][0] - nodes[j][0]) + (nodes[i][1] - nodes[j][1]) * (nodes[i][1] - nodes[j][1]), 0.5);
                tmp = Math.max(0, tmp - barriers[i] - barriers[j]);
                e[i][j] = tmp;
                e[j][i] = tmp;
            }
        }
    }
}