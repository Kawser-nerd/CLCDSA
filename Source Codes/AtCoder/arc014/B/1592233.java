import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);                                              
     
     int N = sc.nextInt();
     
     HashSet<String> used = new HashSet<String>();
     
     String last = "";
     
     int lostindex = -1;
     
     boolean flag = false;
     
     for(int i = 0;i < N;i++){
         String w = sc.next();         
         if(i!=0){
            if(w.charAt(0) != last.charAt(last.length() - 1) && !flag){
                lostindex = i;
                flag = true;
            }             
         }         
         if(i%2 == 0){
            if(used.contains(w) && !flag){
               lostindex = i;               
               flag = true;
            }
            used.add(w);         
         }         
         if(i%2 != 0){
            if(used.contains(w) && !flag){
               lostindex = i;
               flag = true;
            }
            used.add(w);         
         }
         last = w;
     }
     
     if(lostindex == -1){
         System.out.println("DRAW");
         return;
     }
 
     if(lostindex%2 == 0){
         System.out.println("LOSE");
         return;
     }else if(lostindex%2 == 1){
         System.out.println("WIN");         
         return;
     }
     
  }           
}