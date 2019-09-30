import java.util.*;

class Main{           
    
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                                          
       
       String S = sc.next();
       
       String target = S.toLowerCase();
       
       int i = target.indexOf("i");
       
       if(i == -1){
           System.out.println("NO");
           return;           
       }
       
       int j = target.indexOf("c",i);
       
       if(j == -1){
           System.out.println("NO");
           return;
       }
       
       int k = target.indexOf("t",j);
       
       if(k == -1){
           System.out.println("NO");
           return;
       }
       
       System.out.println("YES");
       
       
       
   }
   
 }