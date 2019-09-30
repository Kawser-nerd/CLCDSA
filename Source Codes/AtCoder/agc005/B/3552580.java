import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int[] rev = new int[n+1];
        for(int i=0; i<n; i++){
            int idx = Integer.parseInt(sc.next());
            rev[idx] = i;
        }
        
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(-1);
        ts.add(n);
        
        long ans = 0L;
        for(int i=1; i<=n; i++){
            int ridx = rev[i];
            ts.add(ridx);
            int l = ridx - ts.lower(ridx);
            int r = ts.higher(ridx) - ridx;
            ans += (long)l*r*i;
        }
        
        System.out.println(ans);
    }
}