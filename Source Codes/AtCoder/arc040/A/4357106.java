import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int t=0,a=0;
        for (int i = 0; i < n; i++) {
            String s=sc.next();
            for (int j = 0; j < n; j++) {
                if(s.charAt(j)=='R')t++;
                else if(s.charAt(j)=='B')a++;
            }
        }
        if(t>a)out.println("TAKAHASHI");
        else if(a==t)out.println("DRAW");
        else out.println("AOKI");
    }
}