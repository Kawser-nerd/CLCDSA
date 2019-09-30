import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
      
     String s = sc.next();
     
     int size = s.length();
     
     for(int i = 0;i < size/2;i++){
         char start = s.charAt(i);
         char   end = s.charAt(size - 1 -i);
         if(start == '*' || end == '*'){
             continue;
         }else if(start == end){
             continue;
         }else if(start != end){
             System.out.println("NO");
             return;
         }      
     }
   
     System.out.println("YES");
     
  }                            
}