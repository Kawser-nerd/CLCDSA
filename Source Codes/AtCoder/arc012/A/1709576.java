import java.util.*;

class Main{       
   public static void main(String[] args){

       Scanner sc = new Scanner(System.in);                               
             
       HashMap<String,Integer> map = new HashMap<>(); 
      
       map.put("Saturday",0);
       map.put("Sunday",0);
       map.put("Monday",5);
       map.put("Tuesday",4);
       map.put("Wednesday",3);
       map.put("Thursday",2);
       map.put("Friday",1);
       
       String day = sc.next();
       
       System.out.println(map.get(day));
       
   }
}