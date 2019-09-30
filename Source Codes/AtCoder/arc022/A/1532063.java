import java.util.*;

public class Main{             
    public static void main(String[] args){
      
         Scanner sc = new Scanner(System.in);
         
         String S = sc.next();
         
         S = S.toLowerCase();
         
         int i = S.indexOf("i");
         
         if(i == -1){
             System.out.println("NO");
             return;
         }
         
         i = S.indexOf("c",i);
         if(i == -1){
             System.out.println("NO");
             return;
         }
         
         i = S.indexOf("t",i);
         if(i == -1){
             System.out.println("NO");
             return;
         }
         
         System.out.println("YES");
        
    }        
}