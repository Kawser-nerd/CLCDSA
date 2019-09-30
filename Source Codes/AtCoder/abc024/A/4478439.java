import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a,b,c,k,s,t,g=0;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();
        s = sc.nextInt();
        t = sc.nextInt();
        g = a*s+b*t;
        if(s+t>=k)
            g -= (s+t)*c;
        System.out.println(g);
    }
}