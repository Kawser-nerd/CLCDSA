import java.util.*;

public class Main {           
    public static void main(String[] args) {		        
       Scanner sc = new Scanner(System.in);                                 
         
       long N = sc.nextInt();
       
       long K = sc.nextLong();
       
       System.out.println((K<= Math.ceil((float)(N-1)/2)) ? "YES":"NO");
       
    }
}