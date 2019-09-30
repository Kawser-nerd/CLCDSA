import java.util.*;

public class Main {
  
  public static void main(String[] args) {
         
      Scanner sc = new Scanner(System.in);
      
      String str = sc.next();
      
      int count = 0;
      
      for(int i = 0;i < str.length();i++){
          char ch = str.charAt(i);
          if(ch == 'g'){
              count++;
          }          
      }
      
      if(str.length()%2 == 1){
           System.out.println(count - (str.length()/2 + 1));       
      }else{
           System.out.println(count - str.length()/2);    
      }
         
  }  
}