import java.util.*;

public class Main {                   
    
  public static void main(String[] args) {                     
      
      Scanner sc = new Scanner(System.in);
      
      int ans[] = new int[6];
      
      int N = sc.nextInt();
      
      for(int i = 0;i < N;i++){
         double high = sc.nextDouble();
         double low = sc.nextDouble();
         
         if(high >= 35){
             ans[0]++;
         }else if(high >= 30 && high < 35){
             ans[1]++;
         }else if(high >= 25 && high < 30){
             ans[2]++;
         }
         
         if(low >= 25){
             ans[3]++;
         }
         
         if(low < 0 && high >= 0){
             ans[4]++;
         }
         
         if(high < 0){
             ans[5]++;
         }                  
     }
      
      
      for(int i = 0;i < 6;i++){
          if(i > 0){
              System.out.print(" ");
          }
          System.out.print(ans[i]);
      }
      
      System.out.println();
      
  }   
   
}