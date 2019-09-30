import java.awt.geom.Line2D;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int Ax = sc.nextInt();
        int Ay = sc.nextInt();
        int Bx = sc.nextInt();
        int By = sc.nextInt();
        int N = sc.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            Y[i] = sc.nextInt();
        }
        int intersects = 0;
        for (int i = 0; i < N - 1; i++) {
            if (Line2D.linesIntersect(Ax, Ay, Bx, By, X[i], Y[i], X[i + 1], Y[i + 1])) {
                intersects++;
            }
        }
        if (Line2D.linesIntersect(Ax, Ay, Bx, By, X[0], Y[0], X[N - 1], Y[N - 1])) {
            intersects++;
        }
        System.out.println(intersects / 2 + 1);
    }
}