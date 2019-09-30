import java.util.*;
import java.awt.*;

public class D
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        
        int cases = scan.nextInt();
        
        for(int ca=0;ca < cases;ca++)
        {
            int n = scan.nextInt();
            int m = scan.nextInt();
            
            Point[] p = new Point[2];
            Point[] q = new Point[m];
            
            for(int i=0;i < p.length;i++)
                p[i] = new Point(scan.nextInt(), scan.nextInt());
            
            for(int i=0;i < q.length;i++)
                q[i] = new Point(scan.nextInt(), scan.nextInt());
                
            double[] rtn = new double[m];
            
            double c = Math.sqrt((p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y));
                
            for(int i=0;i < m;i++)
            {
                //Do they overlap at *all*?
                double r0 = Math.sqrt((p[0].x - q[i].x)*(p[0].x - q[i].x) + (p[0].y - q[i].y)*(p[0].y - q[i].y));
                double r1 = Math.sqrt((p[1].x - q[i].x)*(p[1].x - q[i].x) + (p[1].y - q[i].y)*(p[1].y - q[i].y));
                
                if(r0+r1 <= c)
                    continue;
                    
                //Do they overlap *entirely*?
                if(r1 >= (c+r0))
                {
                    //Return p0's area
                    rtn[i] = Math.PI * r0 * r0;
                    continue;
                }
                if(r0 >= (c+r1))
                {
                    rtn[i] = Math.PI * r1 * r1;
                    continue;
                }
                
                
                double CAD = 2 * Math.acos((r0*r0 + c*c - r1*r1) / (2*r0*c));
                double CBD = 2 * Math.acos((r1*r1 + c*c - r0*r0) / (2*r1*c));
                
                double area = (CBD*r1*r1) - (r1*r1*Math.sin(CBD)) + (CAD*r0*r0) - (r0*r0*Math.sin(CAD));
                
                area *= 0.5;
                
                rtn[i] = area;
                
            }
            
            System.out.print("Case #" + (ca+1) + ":");
            
            for(int i=0;i < m;i++)
                System.out.printf(" %.7f", rtn[i]);
            System.out.println();
            
        }
    }
}
