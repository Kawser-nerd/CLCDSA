import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        n=n*(n+1)/2;
        int t=(int)sqrt(n)+1;
        for (int i = 2; i <= t; i++) {
            if(n%i==0){
                out.println("BOWWOW");
                exit(0);
            }
        }
        if(n!=1)out.println("WANWAN");
        else out.println("BOWWOW");
    }
}