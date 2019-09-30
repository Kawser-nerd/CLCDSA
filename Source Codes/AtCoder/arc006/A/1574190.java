import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
               
     String S = "";
     
     for(int i = 0;i < 6;i++){
         S += String.valueOf(sc.nextInt());
     }
     
     int bonus = sc.nextInt();
     
     int count = 0;
     boolean bonus_flag = false;
     
     for(int i = 0;i < 6;i++){
         int l = sc.nextInt();         
         if(S.contains(String.valueOf(l))){
             count++;
         }else if(l == bonus){
             bonus_flag = true;
         }
     }
     
     if(count == 6){
         System.out.println(1);
         return;
     }else if(count == 5 && bonus_flag){
         System.out.println(2);
         return;                
     }else if(count == 5){
         System.out.println(3);
         return;
     }else if(count == 4){
         System.out.println(4);
         return;
     }else if(count == 3){
         System.out.println(5);
         return;
     }else{
         System.out.println(0);         
         return;
     }
     
     
     
  }                            
}