import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String d=sc.next();
        int a=0;
        if(d.equals("Monday"))a=5;
        else if(d.equals("Tuesday"))a=4;
        else if(d.equals("Wednesday"))a=3;
        else if(d.equals("Thursday"))a=2;
        else if(d.equals("Friday"))a=1;
        out.println(a);
    }
}