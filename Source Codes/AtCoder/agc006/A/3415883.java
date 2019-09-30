import java.util.*;
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        String t=sc.next();
        int a=2*n;
        for (int i = 0; i <= n; i++) {
            String p=s.substring(n-i,n);
            String q=t.substring(0,i);
            if(p.equals(q))a=2*n-i;
        }
        System.out.println(a);
    }
}