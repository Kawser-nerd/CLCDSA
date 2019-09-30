import java.util.*;

public class Main {        
    
  public static void main(String[] args) {              
     
      Scanner sc = new Scanner(System.in);                                    
     
      HashMap<String,Integer> map = new HashMap<>();
      
      map.put("Sunday",0);      
      map.put("Saturday",0);           
      map.put("Friday",1);                 
      map.put("Thursday",2);                       
      map.put("Wednesday",3);                       
      map.put("Tuesday",4);                             
      map.put("Monday",5);     
      
      String ans = sc.next();
      
      System.out.println(map.get(ans) - 0);      
      
  }     
}