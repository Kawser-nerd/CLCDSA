import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        double[] a=new double[n];
        double[] b=new double[n];
        double ans=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextDouble();
            b[i]=sc.nextDouble();
            ans+=a[i]*b[i];
        }
        out.println((int)(floor(ans*1.05)));
    }
}