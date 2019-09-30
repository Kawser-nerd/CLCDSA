import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
       Scanner sc = new Scanner(System.in);       
      
       String red  = "YES";
       String blue = "YES";
       
       int x1 = sc.nextInt();
       int y1 = sc.nextInt();
       int  r = sc.nextInt();
       
       //red
       int x1_left  = x1 - r;
       int x1_right = x1 + r;
       int y1_up    = y1 + r;
       int y1_down  = y1 - r;
       
       //blue
       int x2 = sc.nextInt();
       int y2 = sc.nextInt();
       int x3 = sc.nextInt();
       int y3 = sc.nextInt();
                            
       if(x2 <= x1_left && x1_right <= x3 &&  y2 <= y1_down && y1_up <= y3){
           red = "NO";
       }
       
     if((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= r*r && (x3 - x1)*(x3 - x1) + (y2 - y1)*(y2 - y1) <= r*r
      &&(x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1) <= r*r && (x2 - x1)*(x2 - x1) + (y3 - y1)*(y3 - y1) <= r*r){
           blue = "NO";
       }
       
       System.out.println(red);
       System.out.println(blue);
       
    }      
}