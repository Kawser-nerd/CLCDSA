import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        out.println(n>=10?min((n/10)*100+(n%10)*15,(n/10+1)*100):min(n*15,100));
    }
}