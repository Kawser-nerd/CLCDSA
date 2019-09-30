import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
       double n=sc.nextDouble();
       double a=sc.nextDouble();
       int b=sc.nextInt();
       double sum=0;
       double sax=0,sin=1e9;
        for (int i = 0; i < n; i++) {
            double s=sc.nextDouble();
            sum+=s;
            sax=max(sax,s);
            sin=min(sin,s);
        }
        double d=sax-sin;
        if(d==0){
            out.println(-1);
        }else {
            out.println(b/d+" "+(a-b/d*sum/n));
        }
    }
}