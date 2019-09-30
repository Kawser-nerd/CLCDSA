import java.util.*;

class Main{            
     
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);  
       
       int b4 = 0;
       int b2 = 0;
       int b1 = 0;
       
       int N = sc.nextInt();
       
       for(int i = 0;i < N;i++){
           int a = sc.nextInt();
           int count = 0;
           while(a%2 ==0){
               a/=2;
               count++;
           }           
           if(count >=2){
               b4++;
           }
           else if(count >= 1){
               b2++;
           }
           else if(count == 0){
               b1++;
           }
       }
       
       if(b2 > 0){
           if(b4 >= b1){
               System.out.println("Yes");
               return;
           }else{
               System.out.println("No");
               return;
           }
       }       
       
       if(b2 == 0){
           if(b4 +1>=b1){
               System.out.println("Yes");
           }else{
               System.out.println("No");               
           }           
       }
              
       
   }
}