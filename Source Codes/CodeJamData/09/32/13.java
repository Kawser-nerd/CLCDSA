import java.util.*;
import java.io.*;

public class p2
{
	public static void main(String[] eleusive_loves_men) throws Throwable
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in")));
		PrintWriter out=new PrintWriter(new FileOutputStream("B-small.out"));
		String[] sa=in.readLine().trim().split("\\s+");
		int KK=Integer.parseInt(sa[0]);
		for(int qq=1;qq<=KK;qq++)
		{
			sa=in.readLine().trim().split("\\s+");
			int nflies=Integer.parseInt(sa[0]);
			double x0=0,y0=0,z0=0,dx=0,dy=0,dz=0;
			for(int i=0;i<nflies;i++)
			{
				sa=in.readLine().trim().split("\\s+");
				x0+=Double.parseDouble(sa[0]);
				y0+=Double.parseDouble(sa[1]);
				z0+=Double.parseDouble(sa[2]);
				dx+=Double.parseDouble(sa[3]);
				dy+=Double.parseDouble(sa[4]);
				dz+=Double.parseDouble(sa[5]);
			}
			x0/=nflies;
			y0/=nflies;
			z0/=nflies;
			dx/=nflies;
			dy/=nflies;
			dz/=nflies;
			if(qq==5)
			{
				System.out.println("-b/2="+(-(x0*dx+y0*dy+z0*dz)));
				System.out.println("a="+(dx*dx+dy*dy+dz*dz));
			}
			double tmin=-(x0*dx+y0*dy+z0*dz)/(dx*dx+dy*dy+dz*dz);
			if(tmin < 0.0)
				tmin=0.0;
			if(tmin != tmin)
				tmin=0.0;
			double dmin=Math.sqrt((x0+dx*tmin)*(x0+dx*tmin)+
							(y0+dy*tmin)*(y0+dy*tmin)+
							(z0+dz*tmin)*(z0+dz*tmin));
			out.println("Case #"+(qq)+": "+dmin+" "+tmin);
		}
		out.close();
	}
}
