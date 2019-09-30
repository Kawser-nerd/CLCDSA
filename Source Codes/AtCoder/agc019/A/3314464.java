import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        long q=sc.nextLong();
        long h=sc.nextLong();
        long s=sc.nextLong();
        long d=sc.nextLong();
        long n=sc.nextLong();
        long half=min(h,2*q);
        long one=min(half*2,s);
        long two=min(one*2,d);
        out.println((n/2)*two+n%2*one);
    }
}