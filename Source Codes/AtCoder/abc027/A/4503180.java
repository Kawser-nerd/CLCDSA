import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),m=sc.nextInt(),l=sc.nextInt();
        if(n==m) System.out.println(l);
        else if(n==l) System.out.println(m);
        else System.out.println(n);
    }
}