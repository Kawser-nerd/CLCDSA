import java.util.*;

class Main{            
     
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);  
       
       int N = sc.nextInt();
       
       String S[]= new String[N];
       
       for(int i = 0;i < N;i++){
          String temp = sc.next();
          StringBuffer sb = new StringBuffer(temp);
          S[i] = sb.reverse().toString();
       }
        
       Arrays.sort(S);
       
       for(int i = 0;i < N;i++){
         StringBuffer sb = new StringBuffer(S[i]);   
         System.out.println(sb.reverse().toString());
       }
       
       
   }
}