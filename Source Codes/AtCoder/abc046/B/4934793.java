import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n=sc.nextInt();
        long k=sc.nextInt();
        System.out.println(k*(long)Math.pow(k-1,n-1));

    }
    
 
}