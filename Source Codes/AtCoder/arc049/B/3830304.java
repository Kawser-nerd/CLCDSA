import java.util.*;
public class Main{
  static int n;
  static double[][] xy = new double[1000][1000];
  static double[] c = new double[1000];
  static boolean check(double t){
  	double R = xy[0][0] + t/c[0];
  	double L = xy[0][0] - t/c[0];
  	double U = xy[0][1] + t/c[0];
  	double D = xy[0][1] - t/c[0];
  	for(int i=1; i<n; i++){
  	  double r = xy[i][0] + t/c[i];
  	  double l = xy[i][0] - t/c[i];
 	  double u = xy[i][1] + t/c[i];
  	  double d = xy[i][1] - t/c[i];
      if(r<L || l>R || u<D || d>U){
        return false;
      }
      else{
        R = Math.min(R, r);
        L = Math.max(L, l);
        U = Math.min(U, u);
        D = Math.max(D, d);
      }
    }
    return true;
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    for(int i=0; i<n; i++){
      xy[i][0] = sc.nextInt();
      xy[i][1] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    double ok = 1000000000;
    double ng = 0;
    for(int i=0; i<100; i++){
      double mid = (ok+ng) / 2;
      if(check(mid)){
        ok = mid;
      }
      else{
        ng = mid;
      }
    }
    System.out.println(ok);
  }
}