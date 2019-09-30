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
        int sum = findSumOfDigits(N);
		
       if(N%sum==0){
         System.out.print("Yes");
       }else{
         System.out.print("No");
       }
       
		
    }
}