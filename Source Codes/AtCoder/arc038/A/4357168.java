import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int[] a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        Arrays.sort(a);
        int[] b=new int[n];
        for (int i = 0; i < n; i++) {
            b[n-1-i]=a[i];
        }
        int ans=0;
        for (int i = 0; i < n; i++) {
            if(i%2==0)ans+=b[i];
        }
        out.println(ans);
    }
}