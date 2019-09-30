import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
           
     HashMap map = new HashMap<String,Integer>();
     
     map.put("Sunday"  ,0);
     map.put("Saturday",0);
     map.put("Monday",5);
     map.put("Tuesday",4);
     map.put("Wednesday",3);
     map.put("Thursday",2);
     map.put("Friday",1);
     
     
     String day = sc.next();
     
     System.out.println(map.get(day));
     
     
  }                            
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.