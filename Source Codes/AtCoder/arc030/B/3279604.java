import java.util.*;
import java.awt.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int x = sc.nextInt() - 1;

    int[] h = new int[n];
    for (int i = 0; i < n; i++) {
      h[i] = sc.nextInt();
    }

    Queue<Integer> qa = new ArrayDeque<Integer>();
    Queue<Integer> qb = new ArrayDeque<Integer>();
    for (int i = 0; i < n-1; i++) {
      qa.add(sc.nextInt() - 1);
      qb.add(sc.nextInt() - 1);
    }

    int[] parent = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = -2;
    }
    parent[x] = -1;

    while (true) {
      if (qa.size() == 0) break;

      int a = qa.poll();
      int b = qb.poll();

      if (parent[a] == -2 && parent[b] == -2) {
        qa.add(a);
        qb.add(b);
      } else if (parent[a] != -2 && parent[b] == -2) {
        parent[b] = a;
      } else if (parent[a] == -2 && parent[b] != -2) {
        parent[a] = b;
      }
    }

    for (int i = 0; i < n; i++) {
      int flag = h[i];

      if (flag == 1) {
        int node = i;

        while (true) {
          int next_node = parent[node];
          if (next_node == -1) break;

          int next_flag = h[next_node];
          if (next_flag == 1) break;

          h[next_node] = 1;
          node = next_node;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += 2 * h[i];
    }


    System.out.println(ans - h[x] * 2);
  }
}