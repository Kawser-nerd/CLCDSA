import java.util.*;
 
class Main {
  
   public static int findSumOfDigits (int n){
     int sum = 0;
     while(n>0){
       sum += n%10;
       n = n/10;
     } 
     return sum;
   }
  
  
    public static void main(String[] args) {
      
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int total = 0;
      
      for(int i = 1;i<=N;i++){
        int sum = findSumOfDigits(i);
        if(A<=sum&&sum<=B){
          total = total + i;
        }
      }
		System.out.print(total);
    }
}