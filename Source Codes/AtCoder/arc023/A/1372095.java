import java.util.*;

public class Main {    
    public static void main(String[] args){

       Scanner sc = new Scanner(System.in);
                
       int y = sc.nextInt();
       int m = sc.nextInt();
       int d = sc.nextInt();
                            
       if(m == 1){
           m = 13;
       }else if(m == 2){
           m = 14;
       }
       
       double A = distance(y,m,d);
       
       double B = distance(2014,5,17);
       
       System.out.println((int)(B - A));
             
  }    
    
  static double distance(int y,int m,int d){    
      if(y == 1 && m == 13 && d == 1){
          return 0;
      }
      
      if(m == 14 || m == 13){
         y--;   
         if(m == 14 && d == 29 && y%400 == 0 || y%4 == 0){
             d--;
         }
      }            
      
      return 365*y + Math.floor(y/4) - Math.floor(y/100) + Math.floor(y/400) + Math.floor(306*(m+1)/10) + d - 429;      
      
  }    
    
}