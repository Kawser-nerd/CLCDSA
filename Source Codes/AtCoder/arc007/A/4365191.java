import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        char x=sc.next().charAt(0);
        String s=sc.next();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)!=x)out.print(s.charAt(i));
        }
        out.println();
    }
}