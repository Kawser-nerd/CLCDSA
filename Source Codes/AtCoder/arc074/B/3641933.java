import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[3*n];
        for(int i=0; i<n*3; i++){
            a[i] = sc.nextLong();
        }
        sc.close();

        long ans = Long.MIN_VALUE;
        long[] a1 = Arrays.copyOfRange(a, 0, n);
        long[] a2 = Arrays.copyOfRange(a, 2*n, 3*n);
        PriorityQueue<Long> p1 = new PriorityQueue<Long>((Long x, Long y) -> Long.compare(x, y));
        PriorityQueue<Long> p2 = new PriorityQueue<Long>((Long x, Long y) -> Long.compare(-x, -y));
        long[] sum1 = new long[n+1];
        long[] sum2 = new long[n+1];
        Arrays.sort(a2);
        for(int i=0; i<n; i++){
            p1.add(a1[i]);
            p2.add(a2[i]);
            sum1[0] += a1[i];
            sum2[0] += a2[i];
        }
        for(int i=0; i<n; i++){
            long c1 = a[i+n];
            long m1 = p1.poll();
            sum1[i+1] = sum1[i] - m1;
            m1 = Math.max(c1, m1);
            sum1[i+1] += m1;
            p1.add(m1);
            long c2 = a[2*n-1-i];
            long m2 = p2.poll();
            sum2[i+1] = sum2[i] - m2;
            m2 = Math.min(c2, m2);
            sum2[i+1] += m2;
            p2.add(m2);
        }

        for(int i=0; i<n+1; i++){
            ans = Math.max(ans, sum1[i] - sum2[n-i]);
        }

        System.out.println(ans);
    }
}