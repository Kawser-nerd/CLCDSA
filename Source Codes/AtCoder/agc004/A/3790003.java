import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        long c=sc.nextLong();
        if(a%2*b%2*c%2==0){
            out.println(0);
        }else{
            long x=a*b;
            long y=c*b;
            long z=a*c;
            out.println(min(x,min(y,z)));
        }
    }
}