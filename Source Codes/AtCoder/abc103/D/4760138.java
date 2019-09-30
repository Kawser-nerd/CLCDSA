import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    private static class Task implements Comparable<Task> {
        int s;
        int t;

        Task(int s, int t) {
            this.s = s;
            this.t = t;
        }

        public int compareTo(Task task) {
            return t - task.t;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        sc.nextInt();
        int m = sc.nextInt();

        PriorityQueue<Task> que = new PriorityQueue<>();
        for(int i = 0; i < m; i++) {
            que.add(new Task(sc.nextInt(), sc.nextInt()));
        }

        int ans = 0;
        int t = 0;
        while(!que.isEmpty()) {
            Task task = que.poll();
            if(t <= task.s) {
                ans++;
                t = task.t;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}