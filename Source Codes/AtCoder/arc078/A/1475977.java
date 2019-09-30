import java.util.*;

public class Main {              
    
    public static void main(String[] args){           
        
         Scanner sc = new Scanner(System.in);
                     
         int N = sc.nextInt();
         
         int a[] = new int[N];
         
         long sum = 0;
         
         for(int i = 0;i < N;i++){
             a[i] = sc.nextInt();
             sum += a[i];
         }
         
         long left = a[0],right = sum - a[0];
         long min = Math.abs(left - right);
         
         for(int i = 1;i < N-1;i++){
             left  += a[i];
             right -= a[i];
             if(Math.abs(left - right) < min){
                 min = Math.abs(left - right);
             }
         }
         
         System.out.println(min);
         
  }        
}