import java.util.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        if (n<=2) {
            out.println(1);
            exit(0);
        }
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans=0;
        for (int i = 1; i < n-1; i++) {
            long difL=a[i]-a[i-1];
            difL/=max(1,abs(difL));
            long difR=a[i+1]-a[i];
            difR/=max(1,abs(difR));
            if(difR==0){
                a[i+1]=a[i];
                a[i]=a[i-1];
            }
            if(difL*difR<0){
                ans++;
                a[i]=a[i+1];
            }
        }
      out.println(ans+1);
    }
}