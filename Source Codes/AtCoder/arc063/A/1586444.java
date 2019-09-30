import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);                                      
     
     String S = sc.next();
     
     char ch = S.charAt(0);
     
     int l = 0;
     
     int count = 1;
     
     for(int i = 1;i < S.length();i++){         
         if(ch == S.charAt(i)){
            continue; 
         }else{
            ch = S.charAt(i);
            count++;            
         }                  
     }
     
     System.out.println(count-1);
             
  }   
}