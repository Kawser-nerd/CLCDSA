import java.util.*;

public class Main {                     
    
    public static void main(String[] args) {		        

        Scanner sc = new Scanner(System.in);                                                                     
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int L = sc.nextInt();
        
        int P = sc.nextInt();
        int Q = sc.nextInt();
        int R = sc.nextInt();        
        
        int max = Integer.MIN_VALUE;
        
        max = Math.max(max,((N/P)*(M/Q)*(L/R)));
        max = Math.max(max,((N/P)*(M/R)*(L/Q)));
        max = Math.max(max,((N/Q)*(M/R)*(L/P)));
        max = Math.max(max,((N/Q)*(M/P)*(L/R)));
        max = Math.max(max,((N/R)*(M/Q)*(L/P)));
        max = Math.max(max,((N/R)*(M/P)*(L/Q)));                       
        
        System.out.println(max);        
        
  }
}