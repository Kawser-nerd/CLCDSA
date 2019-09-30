import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
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
        int K = sc.nextInt();
        int[] one = new int[K];
        int[] zero = new int[K];
        for (int i = 1; i < K; i++) {
            one[i] = (i + 1) % K;
            zero[i] = (i * 10) % K;
        }
        Deque<Integer> que = new ArrayDeque<>();
        int[] min = new int[K];
        for (int i = 0; i < K; i++) {
            min[i] = Integer.MAX_VALUE;
        }
        que.addLast(1);
        min[1] = 1;
        while (!que.isEmpty()) {
            int cur = que.pollFirst();
            if (min[cur] + 1 < min[one[cur]]) {
                que.addLast(one[cur]);
                min[one[cur]] = min[cur] + 1;
            }
            if (min[cur] < min[zero[cur]]) {
                que.addFirst(zero[cur]);
                min[zero[cur]] = min[cur];
            }
        }
        System.out.println(min[0]);
    }
}