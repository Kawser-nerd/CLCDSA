import java.util.*;

public class Main {                     
   public static void main(String[] args) {		                
      Scanner sc = new Scanner(System.in);    
       
      double L = sc.nextInt();
      double X = sc.nextInt();
      double Y = sc.nextInt();
      
      double S = sc.nextInt();
      double D = sc.nextInt();                  
            
     if(S < D){  
        if(X < Y){
           System.out.printf("%.10f\n",Math.min((D-S)/(X+Y),(L - (D - S) )/(Y-X)));
        }else{
           System.out.printf("%.10f\n",(D-S)/(X+Y));
        }
     }else if(D < S){
        if(X < Y){
           System.out.printf("%.10f\n",Math.min((S-D)/(Y-X),(L - (S - D) )/(X+Y)));           
        }else{
           System.out.printf("%.10f\n",(L - (S-D))/(X+Y));           
        }        
     }else{
          System.out.println("0");
     }
            
  }       
}