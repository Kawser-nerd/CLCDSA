import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),a=sc.nextInt(),b=sc.nextInt();
        String ans="";
        if(n<=a)ans="Ant";
        else if(a<n&&n-a<=b)ans="Bug";
        else if(n%(a+b)==0)ans="Bug";
        else if(n%(a+b)<=a)ans="Ant";
        else ans="Bug";
        out.println(ans);
    }
}