import java.util.*;
import java.io.PrintWriter;
public class Main {
    public static void main(String[] args){
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        String A =sc.next();
        String B =sc.next();
        if(A.equals(B)){
            out.println("H");
        }else{
            out.println("D");
        }

        out.flush();
    }
}