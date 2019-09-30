import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s=sc.next();
        for (char i = 'a'; i <= 'z'; i++) {
            s=s.replaceAll(String.valueOf(i),"");
        }
        for (char i = 'A'; i <= 'Z'; i++) {
            s=s.replaceAll(String.valueOf(i),"");
        }
        out.println(s);
    }
}