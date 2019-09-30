import java.util.*;

public class Main {    
    
  public static void main(String[] args) {              
     Scanner sc = new Scanner(System.in);                
     
     long x = sc.nextLong();
     
     long a = x/11;          
     
     long count = a*2;
     
     if(x%11 > 6){
         count += 2;
     }else if(x%11 > 0){
         count++;
     }
     
     System.out.println(count);          
     
  }          
}