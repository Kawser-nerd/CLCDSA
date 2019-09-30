import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s=sc.next();
        String[] b={"O","D","I","Z","S","B"};
        String[] a={"0","0","1","2","5","8"};
        for (int i = 0; i < b.length; i++) {
            s=s.replaceAll(b[i],a[i]);
        }
        out.println(s);
    }
}