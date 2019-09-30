import java.util.*;

class Main{       
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                            
              
       int N = sc.nextInt();
       
       String ans = "1";
       
       for(int i = 0;i < N-1;i++){
           ans += "0";
       }
       
       ans += "7";
       
       System.out.println(ans);
       
   }
}