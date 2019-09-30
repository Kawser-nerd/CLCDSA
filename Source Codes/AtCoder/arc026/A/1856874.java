import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        int dyn = Math.min(n,5);
        int hdn = n - dyn;
        
        System.out.println(a*hdn + b*dyn);
    }
}