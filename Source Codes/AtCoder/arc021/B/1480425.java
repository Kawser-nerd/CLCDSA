import java.util.*;

public class Main {  
    
    public static void main(String[] args){           
      Scanner sc = new Scanner(System.in);        
      int L = sc.nextInt();
      
      int[] B = new int[L+2];      
      int check = 0;
      
      for(int i =0 ;i < L;i++){
          B[i] = sc.nextInt();
          if(i != L-1)
              check = check^B[i];
      }
      
      if(check != B[L-1]){
          System.out.println(-1);
          return;
      }
      
      int A[] = new int[L+2];
      A[0] = 0;
      
      for(int i = 1;i < L-1;i++){
          A[i] = A[i-1]^B[i-1];
      }
      
      A[L-1] = A[0]^B[L-1];
      
      for(int i = 0;i < L;i++){
         System.out.println(A[i]);
      }      
                  
  }        
}