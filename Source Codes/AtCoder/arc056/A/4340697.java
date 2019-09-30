import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        long a=sc.nextLong(),b=sc.nextLong(),k=sc.nextLong(),l=sc.nextLong();
        out.println(min((k+l-1)/l*b,k/l*b+(k%l)*a));
    }
}