import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);
     
     int N = sc.nextInt();
     
     int count = 0;
     
     for(int i = 0;i < N;i++){
         String w = sc.next();
         if(w.equals("Takahashikun")){
             count++;
         }else if(w.equals("TAKAHASHIKUN")){
             count++;
         }else if(w.equals("takahashikun")){
             count++;
         }
         if(i == N-1){
           if(w.equals("Takahashikun.")){
               count++;
           }else if(w.equals("TAKAHASHIKUN.")){
               count++;
           }else if(w.equals("takahashikun.")){
               count++;
           }
         }
     }
    
     System.out.println(count);
     
  }                  
}