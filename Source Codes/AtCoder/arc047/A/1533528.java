import java.util.*;

public class Main{      
    
    public static void main(String[] args){
      
       Scanner sc = new Scanner(System.in);
     
       int N  = sc.nextInt();
       int L  = sc.nextInt();
       
       String S = sc.next();
       
       int crash = 0;
       
       int count = 1;
       
       for(int i = 0;i < N;i++){
           char ch = S.charAt(i);
           
           if(ch == '+'){
               count++;
           }
           
           if(ch == '-'){
               count--;
               if(count == 0){
                  count = 1;   
               }               
           }
           
           if(count > L){
               crash++;
               count = 1;
           }
           
       }
       
       System.out.println(crash);
              
    }        
}