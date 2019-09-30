import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        if(n%9==0){
            a(String.valueOf(9),n/9);
        }else {
            a(String.valueOf(n%9),(n+8)/9);
        }
    }
    static void a(String s,int i){
        for (int j = 0; j < i; j++) {
            out.print(s);
        }
        out.println();
    }
}