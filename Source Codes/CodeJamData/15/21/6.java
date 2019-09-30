import java.util.*;
public class Slam {
/*    static int MAX = 10_000_000;
    static int[] dist = new int[MAX+1];
    static int[] pred = new int[MAX+1];
    {
        Arrays.fill(dist, -1);
    }
    static ArrayDeque<Integer> q = new ArrayDeque<>();
    {
        q.addFirst(1);
        dist[1] = 1;
        while (!q.isEmpty()) {
            int v = q.removeLast();
//            System.out.println(v + " " + dist[v]);
            int w = Integer.parseInt(new StringBuilder().append(v).reverse().toString());
            if (w <= MAX && dist[w] == -1) {
                dist[w] = dist[v]+1;
                q.addFirst(w);
                pred[w] = v;
            }
            if (v+1 <= MAX && dist[v+1] == -1) {
                dist[v+1] = dist[v]+1;
                q.addFirst(v+1);
                pred[v+1] = v;
            }
        }
    }
    static void bt(int target) {
        if (target==0) return;
        while (pred[target]==target-1 && target!=0)
            target--;
        bt(pred[target]);
        if (pred[target] != target-1) {
            System.out.println(pred[target]);
            System.out.println(target);
        }
    }*/
    static int[] basic = new int[15];
    {
    basic[1] = 10;
    for (int i=2; i<15; i++) {
        if (i%2==0) {
            basic[i] = basic[i-1] + 2*(int)(Math.pow(10, i/2)) - 1;            
        }
        else {
            basic[i] = basic[i-1] + (int)((Math.pow(10, i/2)) + (Math.pow(10, (i+1)/2)) - 1);            
        }            
    }
    }
    static boolean allzero(String t) {
        for (char ch:t.toCharArray()) 
            if (ch != '0') return false;
        return true;
    }
    static long f(long v) {
        if (v<10) return v;
        int L = (""+v).length();
        String right = (""+v).substring(L/2, L);
        String left = (""+v).substring(0, L/2);
        if (allzero(right)) return 1+f(v-1);
        long result = basic[L-1] + Integer.parseInt(right) + Integer.parseInt(new StringBuilder(left).reverse().toString());
        result = Math.min(result, basic[L-1] + (v - (long)Math.pow(10, L-1)));
        return result;
    }
    public static void main(String[] args) {
        new Slam();
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        for (int kk=1; kk<=k; kk++)
            System.out.println("Case #"+kk+": "+f(sc.nextLong()));
        
/*        System.out.println(Arrays.toString(basic));
        Scanner sc = new Scanner(System.in);
        for (int N=1; N<10000000; N++)
            if (dist[N] != f(N))
            System.out.println(N+" "+dist[N]+" "+f(N));
            */
            
/*        while (true) {
            int N = sc.nextInt();
//            bt(N);
            System.out.println(dist[N]);
            System.out.println(f(N));
        }*/
    }
}