import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
           
     double height = sc.nextDouble();
     double bmi    = sc.nextDouble();
     
     System.out.println(bmi*Math.pow(height/100,2));
     
  }                            
}