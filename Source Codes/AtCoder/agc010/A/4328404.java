import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int d=0;
        for (int i = 0; i < n; i++) {
            d+=sc.nextInt()%2;
        }
        out.println(d%2==0?"YES":"NO");
    }
}