import java.util.*;

class Main{       
   public static void main(String[] args){

       Scanner sc = new Scanner(System.in);                                            
      
       String day[] = {
                         "Monday",
                         "Tuesday",
                         "Wednesday",
                         "Thursday",
                         "Friday",
                         "Saturday",
                         "Sunday"
                       };
       
       String s = sc.next();
       
       for(int i = 0 ;i < 7;i++){
           if(day[i].equals(s)){
               System.out.println(Math.max(5-i,0));  
               return;
           }           
       }
       
   }
}