import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        long[] a=new long[n];
        long[] b=new long[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
            b[i]=sc.nextLong();
        }
        long ans=0;
        for (int i = n-1; i > -1; i--) {
            a[i]+=ans;
            if(a[i]%b[i]!=0) {
                long t = b[i] - a[i] % b[i];
                ans+=t;
            }
        }
        out.println(ans);
    }
}