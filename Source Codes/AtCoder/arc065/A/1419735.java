import java.util.*;

public class Main {    
    
  public static void main(String[] args) {              
     Scanner sc = new Scanner(System.in);
     
     String S = sc.next();
     
     int N = S.length();                              
     int current = N;
     
     
     while(current > 0){
         
             if(current >= 7){
                 String sub = S.substring(current-7,current);
                 if(sub.equals("dreamer")){
                     current -= 7;
                     continue;
                 }             
             }
             
             if(current >= 6){
                 String sub = S.substring(current - 6,current);
                 if(sub.equals("eraser")){
                     current -= 6;
                     continue;
                 }
             }
         
             if(current >= 5){
                 String sub = S.substring(current - 5,current);
                 if(sub.equals("dream") || sub.equals("erase")){
                     current -= 5;
                     continue;
                 }                                  
             }
                       
             System.out.println("NO");
             return;                                   
     }
     
     System.out.println("YES");     
     
  }          
}