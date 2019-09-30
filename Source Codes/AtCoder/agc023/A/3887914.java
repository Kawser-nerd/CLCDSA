import java.util.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        long[] a=new long[n+1];
        a[0]=0;
        HashMap<Long,Integer> m=new HashMap<>();
        m.put(a[0],0);
        for (int i = 1; i <n+1; i++) {
            a[i]=a[i-1]+Long.parseLong(sc.next());
            m.put(a[i],0);
        }
        long ans=0;
        for(int i=0;i<=n;i++){
            ans+=m.get(a[i]);
            m.put(a[i],m.get(a[i])+1);
        }
        System.out.println(ans);
    }
}