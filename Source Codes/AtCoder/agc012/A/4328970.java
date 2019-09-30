import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        long[] a=new long[3*n];
        for (int i = 0; i < n*3; i++) {
            a[i]=sc.nextLong();
        }
        Arrays.sort(a);
        long ans=0;
        for (int i = n*3-2; i >= n; i-=2) {
            ans+=a[i];
        }
        out.println(ans);
    }
}