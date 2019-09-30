import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String ans="";
        int a=sc.nextInt(),b=sc.nextInt();
        a=abs(a);
        b=abs(b);
        if(a<b)ans="Ant";
        else if(a>b)ans="Bug";
        else ans="Draw";
        out.println(ans);
    }
}