import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        String ans="1";
        out.println(p(n,ans)+"7");
    }
    static String p(int n,String s){
        if(n==1)return s;
        else return p(n-1,s+"0");
    }
}