import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int[] dist = new int[k];
    for(int i = 0; i < k; i++) {
      dist[i] = Integer.MAX_VALUE;
    }
    dist[1] = 0;
    Deque<Integer> deque = new ArrayDeque<>();
    deque.addFirst(1);
    int[] visit = new int[k];
    visit[1] = 1;
    while(deque.size() > 0) {
      int u = deque.pollFirst();
      int v1 = (10 * u) % k;
      int v2 = (u + 1) % k;
      if(visit[v1] == 0)  {
        dist[v1] = Math.min(dist[v1], dist[u]);
        deque.addFirst(v1);
        visit[v1] = 1;
      } else {
        if(dist[v1] > dist[u]) {
          dist[v1] = dist[u];
          deque.addFirst(v1);
        }
      }
      if(visit[v2] == 0) {
        dist[v2] = Math.min(dist[v2], dist[u] + 1);
        deque.addLast(v2);
        visit[v2] = 1;
      }
    }
    System.out.println(dist[0] + 1);
  }
}