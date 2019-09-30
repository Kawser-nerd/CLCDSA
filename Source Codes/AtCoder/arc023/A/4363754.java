import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int y=sc.nextInt(),m=sc.nextInt(),d=sc.nextInt();
        out.println(c(2014,5,17)-c(y,m,d));
    }
    static int c(int y,int m,int d){
        if(m<3){
            m+=12;
            y--;
        }
        return 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;
    }
}