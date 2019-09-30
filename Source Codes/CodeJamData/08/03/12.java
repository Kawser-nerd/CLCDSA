import java.text.DecimalFormat;
import java.util.*;
public class FlySwatter {
   public static void main(String[] args) {
      try {
         Scanner s = new Scanner(System.in);
         int n = Integer.parseInt(s.nextLine());
         DecimalFormat format = new DecimalFormat("0.00000000");
         for (int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(s.nextLine(), " ");
            double f = Double.parseDouble(st.nextToken());
            double R = Double.parseDouble(st.nextToken());
            double t = Double.parseDouble(st.nextToken());
            double r = Double.parseDouble(st.nextToken());
            double g = Double.parseDouble(st.nextToken());
            double safetyZone = calc(f, R, t, r, g);
            double totalArea = Math.PI * R * R;
            double res = 1.0 - safetyZone / totalArea;
            System.out.println("Case #" + (i+1) + ": " + format.format(res));
         }
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
   
   static double calc(double f, double R, double t, double r, double g) {
      if (g-2*f <= 0) return 0;
      int nStrings = 0; // only looking at the upper right quadrant
      double currLen = r+f;
      while (true) {
         currLen += g + 2*r;
         nStrings++;
         if (currLen > R-t) break;
      }
      nStrings += 3; // buffer
      double safetyArea = 0;
      double R2 = (R-t-f)*(R-t-f);
      double bit = (g-2*f)*(g-2*f);
      for (int x=0; x<nStrings; x++) {
         double xLow = (2*x+1)*r + f + x*g;
         double xHigh = (2*x+1)*r - f + (x+1)*g;
         for (int y=0; y<nStrings; y++) {
            double yLow = (2*y+1)*r + f + y*g;
            double yHigh = (2*y+1)*r - f + (y+1)*g;
            // If the square is outside the racket
            if (xLow*xLow + yLow*yLow > R2) {
               break;
            }
            // If the entire square is inside the racket
            if (xHigh*xHigh + yHigh*yHigh < R2) {
               safetyArea += bit;
            } else {
               boolean circleContainsNW = (xLow*xLow + yHigh*yHigh < R2);
               boolean circleContainsSE = (xHigh*xHigh + yLow*yLow < R2);
               if (!circleContainsNW && !circleContainsSE) {
                  double xMid = Math.sqrt(R2 - yLow*yLow);
                  safetyArea += integrate(xLow, xMid, R2, yLow);
               } else if (!circleContainsNW && circleContainsSE) {
                  safetyArea += integrate(xLow, xHigh, R2, yLow);
               } else if (circleContainsNW && !circleContainsSE) {
                  double xMid1 = Math.sqrt(R2 - yHigh*yHigh);
                  double xMid2 = Math.sqrt(R2 - yLow*yLow);
                  safetyArea += (g-2*f)*(xMid1-xLow) + integrate(xMid1, xMid2, R2, yLow);
               } else if (circleContainsNW && circleContainsSE) {
                  double xMid = Math.sqrt(R2 - yHigh*yHigh);
                  safetyArea += (g-2*f)*(xMid-xLow) + integrate(xMid, xHigh, R2, yLow);
               }
            }
         }
      }
      return 4*safetyArea;
   }
   
   // Computes the definite integral of (sqrt(R2-x*x)-yLow)dx from x=x0 to x=x1.
   static double integrate(double x0, double x1, double R2, double yLow) {
      double ret = 0;
      double R = Math.sqrt(R2);
      double theta0 = Math.acos(x0/R);
      double theta1 = Math.acos(x1/R);
      ret += R2*(theta0-theta1)/2.0;
      ret += R2*(Math.sin(2*theta1) - Math.sin(2*theta0))/4.0;
      ret += yLow*R*(Math.cos(theta0)-Math.cos(theta1));
      return ret;
   }
}
