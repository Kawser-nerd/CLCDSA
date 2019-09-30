import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
    
     int N = sc.nextInt();
     
     int A = sc.nextInt();
     int B = sc.nextInt();          
     
     int count = 0;
     
     boolean aflag = false;
     boolean bflag = false;     
     
     while(true){
       if(count%2 == 0){
          N -= A;                    
          if(N <= 0){
              aflag = true;
              break;
          }          
       }else{
          N -= B; 
          if(N <= 0){
              bflag = true;
              break;
          }
       }
       count++;
     }
     
     if(aflag){
         System.out.println("Ant");
     }
     
     if(bflag){
         System.out.println("Bug");
     }
     
  
  }    
}