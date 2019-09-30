import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B implements Runnable
{
	public static String file = "b-large";
	public BufferedReader in;
	public BufferedWriter out;
	Point v1;
	Point v2;
	Point size;
	Point start;
	long ans;
	
	public void calcGeneral()
	{
		Point start=(Point)this.start.clone();
		prevleft=0;
		prevright=Long.MAX_VALUE;
		while (true)
		{
			long t=steps2(start,v1);
			if (t<0)
			{
				break;
			}
			ans+=t;
			start.x+=v2.x;
			start.y+=v2.y;
			//if (start.x<0 || start.x>=size.x || start.y<0 || start.y>=size.y)
			//{
			//	break;
			//}
		}
	}
	long prevleft;
	long prevright;
	public long steps2(Point p,Point d)
	{
		double dleft=0;
		double dright=1e+100;
		if (d.x>0)
		{
			dleft=Math.max(dleft,-p.x/(double)d.x);
			dright=Math.min(dright,(size.x-1-p.x)/(double)d.x);
		}else if (d.x<0)
		{
			dleft=Math.max(dleft,(size.x-1-p.x)/(double)d.x);
			dright=Math.min(dright, -p.x/(double)d.x);
		}else
		{
			if (p.x<0 || p.x>=size.x)
			{
				return -1;
			}
		}
		if (d.y>0)
		{
			dleft=Math.max(dleft,-p.y/(double)d.y);
			dright=Math.min(dright,(size.y-1-p.y)/(double)d.y);
		}else if (d.y<0)
		{
			dleft=Math.max(dleft,(size.y-1-p.y)/(double)d.y);
			dright=Math.min(dright, -p.y/(double)d.y);
		}else
		{
			if (p.y<0 || p.y>=size.y)
			{
				return -1;
			}
		}
		if (dleft>dright+1e-8)
		{
			return -1;
		}
		long left=(long)Math.ceil(dleft-1e-8);
		long right=(long)Math.floor(dright+1e-8);
		if (left>prevright)
		{
			return -1;
		}
		prevleft=left;
		prevright=right;
		return right-left+1;
		
	}
	public int gcd(int x,int y)
	{
		if (x==0)
		{
			return y;
		}else
		{
			return gcd(y%x,x);
		}
	}
	int ans2=0;
	public void calc2()
	{
		int[][] table=new int[size.x][size.y];
		if (start.x<0 || start.x>=size.x || start.y<0 || start.y>=size.y)
		{
			ans2=0;
			return;
		}
		table[start.x][start.y]=1;
		Point[] queue=new Point[size.x*size.y];
		int bqueue=0;
		int equeue=1;
		queue[0]=start;
		ans2=1;
		while (equeue>bqueue)
		{
			Point p=queue[bqueue];
			bqueue++;
			Point p1=new Point(p.x+v1.x,p.y+v1.y);
			if (p1.x>=0 && p1.x<size.x && p1.y>=0 && p1.y<size.y && table[p1.x][p1.y]==0)
			{
				table[p1.x][p1.y]=1;
				ans2++;
				queue[equeue]=p1;
				equeue++;
			}
			p1=new Point(p.x+v2.x,p.y+v2.y);
			if (p1.x>=0 && p1.x<size.x && p1.y>=0 && p1.y<size.y && table[p1.x][p1.y]==0)
			{
				table[p1.x][p1.y]=1;
				ans2++;
				queue[equeue]=p1;
				equeue++;
			}
		}
	}
	public void calcCollinear()
	{
		int dx,dy;
		int a1,a2;
		if (v1.x==0)
		{
			dy=gcd(Math.abs(v1.y),Math.abs(v2.y));
			a1=v1.y/dy;
			a2=v2.y/dy;
			dx=v1.x/a1;
		}else
		{
			dx=gcd(Math.abs(v1.x),Math.abs(v2.x));
			a1=v1.x/dx;
			a2=v2.x/dx;
			dy=v1.y/a1;
		}
		int min,max;
		max=steps(start,new Point(dx,dy));
		min=-steps(start,new Point(-dx,-dy));
		int[] temp=new int[max-min+1];
		int start=-min;
		int[] queue=new int[temp.length];
		temp[start]=1;
		int bqueue=0;
		int equeue=1;
		queue[0]=start;
		ans=1;
		while (equeue>bqueue)
		{
			int v=queue[bqueue];
			bqueue++;
			int v1=v+a1;
			if (v1>=0 && v1<temp.length && temp[v1]==0)
			{
				temp[v1]=1;
				queue[equeue]=v1;
				equeue++;
				ans++;
			}
			int v2=v+a2;
			if (v2>=0 && v2<temp.length && temp[v2]==0)
			{
				temp[v2]=1;
				queue[equeue]=v2;
				equeue++;
				ans++;
			}
		}
	}
	public int steps(Point p,Point d)
	{
		int ans=Integer.MAX_VALUE;
		if (d.x>0)
		{
			ans=Math.min((size.x-1-p.x)/d.x,ans);
		}else if (d.x<0)
		{
			ans=Math.min(p.x/(-d.x),ans);
		}
		if (d.y>0)
		{
			ans=Math.min((size.y-1-p.y)/d.y,ans);
		}else if (d.y<0)
		{
			ans=Math.min(p.y/(-d.y),ans);
		}
		return ans;
	}

	public void solve() throws Exception
	{
		int ntest=Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			int tx=Integer.parseInt(readWord());
			int ty=Integer.parseInt(readWord());
			size=new Point(tx,ty);
			tx=Integer.parseInt(readWord());
			ty=Integer.parseInt(readWord());
			v1=new Point(tx,ty);
			tx=Integer.parseInt(readWord());
			ty=Integer.parseInt(readWord());
			v2=new Point(tx,ty);
			tx=Integer.parseInt(readWord());
			ty=Integer.parseInt(readWord());
			start=new Point(tx,ty);
			ans=0;
			if (start.x>=0 && start.x<size.x && start.y>=0 && start.y<size.y)
			{
				if (v1.x*v2.y-v1.y*v2.x==0)
				{
					calcCollinear();
				}else
				{
					calcGeneral();
				}
			}
			//calc2();
			//if (ans!=ans2)
			//{
			//	System.out.println("bug");
			//	calcGeneral();
			//}
			out.write("Case #"+test+": "+ans+"\n");
		}
	}

	public String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = in.read();
			if (c < 0)
			{
				return "";
			}
			if (c > 32)
			{
				break;
			}
		}
		while (true)
		{
			b.append((char) c);
			c = in.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run()
	{
		try
		{
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new BufferedWriter(new FileWriter(file + ".out"));
			solve();
			in.close();
			out.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			new Thread(new B()).start();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

}
