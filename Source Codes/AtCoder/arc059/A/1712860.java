import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
            
      int N = sc.nextInt();
      int a[] = new int[N];
      
      for(int i = 0;i < N;i++){
          a[i] = sc.nextInt();
      }
      
      Arrays.sort(a);
      
      int start = a[0];
      int end = a[a.length - 1];
      
     int sum = Integer.MAX_VALUE;
     
     for(int i = start; i <= end;i++){
         int ans = 0;
         for(int j = 0;j < N;j++){
           ans += (a[j]-i)*(a[j] - i);         
         }
         sum = Math.min(sum,ans);
     }

      System.out.println(sum);
      
   }
}