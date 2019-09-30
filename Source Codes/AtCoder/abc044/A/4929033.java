import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int x=sc.nextInt();
        int y=sc.nextInt();
        System.out.println(x*Math.min(n, k)+y*(n-k>0?n-k:0));
    }
    
 
}