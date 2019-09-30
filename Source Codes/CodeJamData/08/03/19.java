package qround;

import java.util.Arrays;
import java.util.Scanner;

public class C {
  static double solve(double f , double R , double t , double r , double g){
    if(2 * f >= g)return 1.0;
    double total = 0.25 * Math.PI * R * R;
    double safe   = 0.0;
    double inRad = R - t;
    if(inRad - f <= 0)return 1.0;
    double square = (g - 2 * f) * (g - 2 * f);
    int count[] = new int[4];
    for(double x = r ; x < inRad ; x+= (g + 2 * r)){
      for(double y = r ; y < inRad ; y += (g + 2 * r)){
        double ux = x + g;
        double uy = y + g;
        if(ux * ux + uy * uy < inRad * inRad){
          safe += square;
        }else{
          if(Math.hypot(x + f, y + f) > inRad - f)continue;
          double dx = ux - f;
          double dy = uy - f;
          if(Math.hypot(dx, dy) < inRad - f){
            safe += (dx - (x + f)) * (dy - (y + f));
            continue;
          }
          double irf = (inRad - f);
          irf = irf * irf;
          if(Math.hypot(x + f, dy) < inRad - f){
            if(Math.hypot(dx , y + f) < inRad - f){
              double a = Math.sqrt(irf - dy * dy);
              double b = Math.sqrt(irf - dx * dx);
              safe += (a - (x + f)) * (dy - (y + f));
              safe += 0.5 * (b - (y + f) + dy - (y + f)) * (dx - a);
              safe += area(inRad - f, a , dy , dx,  b);
            }else{
              double a = Math.sqrt(irf - dy * dy);
              double b = Math.sqrt(irf - (y + f) * (y+f));
              safe += 0.5 * (a + b - 2 * (x + f)) * (dy - (y + f));
              safe += area(inRad - f, a , dy,  b ,  y + f);
            }
          }else{
            if(Math.hypot(dx , y + f) < inRad - f){
              double a = Math.sqrt(irf - (x + f) * (x + f));
              double b = Math.sqrt(irf - dx * dx);
              safe += 0.5 * ((a + b) - 2 * (y + f)) * (dx - (x + f));
              safe += area(inRad - f, x + f, a, dx , b);
            }else{
              double a = Math.sqrt(irf - (x + f) * (x+f));
              double b = Math.sqrt(irf - (y + f) * (y+f));
              safe += 0.5 * (b - (x + f) ) * (a - (y + f));
              safe += area(inRad - f , x + f , a , b , y + f);
            }
          }
        }
      }
    }
    return 1.0 - safe / total;
  }
  static double area(double R , double x1 , double y1 , double x2 , double y2){
    double theta = Math.abs(Math.atan2(y1, x1) - Math.atan2(y2, x2));
    double circle = 0.5 * R * R * theta;
    double tri = 0.5 * Math.abs(x1 * y2 - x2 * y1);
    return circle - tri ;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for(int i = 1 ; i <= N ; i++){
      double f = sc.nextDouble();
      double R = sc.nextDouble();
      double t = sc.nextDouble();
      double r = sc.nextDouble();
      double g = sc.nextDouble();
      System.out.printf("Case #%d: %.6f\n" , i , solve(f, R, t, r, g));
    }
  }
}
