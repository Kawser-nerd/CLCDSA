import java.util.*;

class Main{           
    
   public static void main(String[] args){
       Scanner sc= new Scanner(System.in); 
       
       int x = sc.nextInt();
       int y = sc.nextInt();
       int k = sc.nextInt();
       
       if(y >= k){
           System.out.println(x + k);
       }else{
           System.out.println(x + y - (k-y));
       }
       
       
    }
      
 }