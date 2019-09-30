import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String[] s = sc.next().split("\\+");
        int ans=0;
        for (int i = 0; i < s.length; i++) {
            if(!s[i].contains("0"))ans++;
        }
        out.println(ans);
    }
}