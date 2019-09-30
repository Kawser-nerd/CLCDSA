import java.util.*;

public class Main {
    static int[] bit;
    static int n;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        bit = new int[n+1];
        int[] pos = new int[n+1];
        int[] a = new int[n+1];
        for(int i=1;i<=n;i++){
            a[i] = sc.nextInt();
            pos[a[i]] = i;
        }
        int[] left = new int[n+1], right = new int[n+1];
        TreeSet<Integer> ts = new TreeSet<>();
        for(int v=1;v<=n;v++){
            int p = pos[v];
            Integer x = ts.lower(p);
            if(x==null) left[v]=p; // 1-base.
            else left[v] = p-x;
            ts.add(p);
        }
        ts = new TreeSet<>();
        for(int v=1;v<=n;v++){
            int p = pos[v];
            Integer y = ts.higher(p);
            if(y==null) right[v] = n+1-p;
            else right[v] = y-p;
            ts.add(p);
        }
        long ans = 0;
        for(int v=1;v<=n;v++){
            long cur = ((long) v)*((long)left[v])*((long)right[v]);
            ans += cur;
        }
        System.out.println(ans);
    }
}