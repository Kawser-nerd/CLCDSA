import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        if(a*b<=0)out.println("Zero");
        else if(b<0&&(b-a+1)%2==0)out.println("Positive");
        else if(b<0&&(b-a+1)%2==1)out.println("Negative");
        else out.println("Positive");
    }
}