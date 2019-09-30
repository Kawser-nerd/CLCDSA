import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),k=sc.nextInt();
        int a=sc.nextInt();
        int m=a;
        int g=a;
        for (int i = 0; i < n - 1; i++) {
            int b=sc.nextInt();
            m=max(m,b);
            g=gcd(a,b);
            a=b;
        }
        if(k<=m&&k%g==0)out.println("POSSIBLE");
        else out.println("IMPOSSIBLE");
    }
    static int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
}