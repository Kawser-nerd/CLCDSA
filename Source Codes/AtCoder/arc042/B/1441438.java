import java.util.*;

public class Main {
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);    

      double cx = sc.nextDouble();
      double cy = sc.nextDouble();
      
      int N = sc.nextInt();
      
      double[] x = new double[N+2];
      double[] y = new double[N+2];
      
      for(int i = 0;i < N;i++){
          x[i] = sc.nextDouble();
          y[i] = sc.nextDouble();
      }
      
      double min = 100000000;
      
      for(int i = 0 ;i < N - 1;i++){
          double l = dist(x[i],x[i+1],y[i],y[i+1],cx,cy);
          min = Math.min(l,min);
      }
      
      double l = dist(x[N-1],x[0],y[N-1],y[0],cx,cy);
      
      min = Math.min(l,min);
      
      System.out.println(min);      
    
  }
  
  public static double dist(double x1,double x2,double y1,double y2,double x,double y){
		if(x1 == x2){
			return Math.abs(x-x1);
		}
		else if(y1 == y2){
			return Math.abs(y-y1);
		}				
		else{
			double a = (y1-y2)/(x1-x2);
			double b = y1 - a*x1;
			return Math.abs(y - a*x - b)/Math.sqrt(1+a*a);
		}   
  }    
  
}