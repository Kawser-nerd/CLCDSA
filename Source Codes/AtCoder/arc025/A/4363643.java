import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int ans=0;
        int[] d=new int[7];
        int[] j=new int[7];
        for (int i = 0; i < 7; i++) {
            d[i]=sc.nextInt();
        }
        for (int i = 0; i < 7; i++) {
            j[i]=sc.nextInt();
        }
        for (int i = 0; i < 7; i++) {
            ans+=max(d[i],j[i]);
        }
        out.println(ans);
    }
}