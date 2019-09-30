import java.util.*;

public class Main {              
    
    public static void main(String[] args){           
        
         Scanner sc = new Scanner(System.in);
                     
         int N = sc.nextInt();
         
         String S = sc.next();
         
         String str[] = new String[]{"A","B","X","Y"};

         int min = Integer.MAX_VALUE;

         for(int i = 0;i < 4;i++){
             for(int j = 0;j < 4;j++){
                 for(int k = 0;k < 4;k++){
                     for(int l = 0;l < 4;l++){
                         String shortA = str[i] + str[j];
                         String shortB = str[k] + str[l];
                         
                         String tempA = S.replace(shortA,"L").replace(shortB,"R");
                         String tempB = S.replace(shortB,"L").replace(shortA,"R");
                         
                        min = Math.min(min,Math.min(tempA.length(),tempB.length()));
                         
                     }   
                 }                 
             }                                       
         }
         
         System.out.println(min);
                  
  }        
}