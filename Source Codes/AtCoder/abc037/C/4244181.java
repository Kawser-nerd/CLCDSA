import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),k=sc.nextInt();
        long ans=0;
        long[] a=new long[n+1];
        for (int i = 1; i <= n; i++) {
            a[i]=sc.nextLong();
            a[i]+=a[i-1];
        }
        for (int i = k; i <= n; i++) {
            ans+=a[i]-a[i-k];
        }
        out.println(ans);
    }
}