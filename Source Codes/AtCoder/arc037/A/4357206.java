import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int ans=0;
        for (int i = 0; i < n; i++) {
            ans+=max(80-sc.nextInt(),0);
        }
        out.println(ans);
    }
}