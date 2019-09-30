import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        double p=sc.nextDouble();
        if(p>=1.5/log(2)){
            out.println(f(1.5*log(log(2)*p/1.5)/log(2),p));
        }else {
            out.println(p);
        }
    }
    static double f(double x,double p){
        return x+p/(pow(2,x/1.5));
    }
}