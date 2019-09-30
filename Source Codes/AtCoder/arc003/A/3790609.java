import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        char[] r=sc.next().toCharArray();
        double sum=0;
        for (int i = 0; i <n ; i++) {
            if(r[i]!='F')sum+=(69-(int)r[i]);
        }
        out.println(sum/n);
    }
}