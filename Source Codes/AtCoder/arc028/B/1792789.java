import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();
        String[] s = sc.nextLine().split(" ");
        int[] n = new int[N];
        for (int i=0; i<N; i++) {
            n[i] = Integer.parseInt(s[i]);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new MyComp());
        PrintWriter out = new PrintWriter(System.out);

        for (int i=0; i<N; i++) {
            pq.add(new int[]{i+1, n[i]});
            if (i >= K-1) {
                if (i >= K) pq.poll();
                out.println(pq.peek()[0]);
            }
        }
        out.flush();
    }
}

class MyComp implements Comparator {
    @Override
    public int compare (Object arg1, Object arg2) {
        int v1 = ((int[]) arg1)[1];
        int v2 = ((int[]) arg2)[1];
        return Integer.compare(v2, v1);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.