import java.util.*;

public class Main {        
    
  public static void main(String[] args) {              
     Scanner sc = new Scanner(System.in);                                    
     
     int N = sc.nextInt();
     int L = sc.nextInt();
     
     String S = sc.next();
     
     int crash_count = 0;
         
     int tab = 1;
     
     for(int i = 0;i < S.length();i++){
         
         if(S.charAt(i) == '+'){
             tab++;
         }    
         
         if(S.charAt(i) == '-'){
             if(tab == 1){
                continue; 
             }             
             tab--;             
         }
         
         if(tab > L){
             crash_count++;
             tab = 1;
         }    
         
     }
     
     System.out.println(crash_count);     
     
  }     
}