import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int m=sc.nextInt(),n=sc.nextInt(),N=sc.nextInt();
        int ans=0,c=0,a=N,b=0;
        while (c<10){
            ans+=a;
            b+=a;
            a=(b/m)*n;
            b%=m;
            if(a==0)c++;
        }
        out.println(ans);
    }
}