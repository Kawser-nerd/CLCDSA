import java.util.*;

class Main{           
 
   public static void main(String[] args){
      
       Scanner sc = new Scanner(System.in);
       int a[][] = new int[4][4];
      for(int i = 0;i < 4;i++){
          for(int j = 0;j < 4;j++){
                a[i][j] = sc.nextInt();
          }          
      }      
      
      for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            if(a[i][j] == a[i][j+1]){
                System.out.println("CONTINUE");
                return;
            }
        }          
      }
      
      for(int i = 0;i < 3;i++){
         for(int j = 0;j < 4;j++){
            if(a[i][j] == a[i+1][j]){
                System.out.println("CONTINUE");
                return;
            }   
         }          
      }
       
      
      System.out.println("GAMEOVER");
                            
   }    
      
 }