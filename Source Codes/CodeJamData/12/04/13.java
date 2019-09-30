import java.util.*;
import java.io.*;

class Frac
{
    public static int gcd(int u, int v)
    {
        while (v != 0)
        {
            int t = v;
            v = u % v;
            u = t;
        }
        return Math.abs(u);
    }
    
    public int n;
    public int d;
    
    public Frac(int n, int d)
    {
        int dd = gcd(n, d);
        
        this.n = n / dd;
        this.d = d / dd;
    }
    
    public Frac add(Frac other)
    {
        int tempn = this.n * other.d + other.n * this.d;
        int tempd = this.d * other.d;
        
        return new Frac(tempn, tempd);
    }
    
    public Frac sub(Frac other)
    {
        int tempn = this.n * other.d - other.n * this.d;
        int tempd = this.d * other.d;
        
        return new Frac(tempn, tempd);
    }
    
    public Frac mul(Frac other)
    {
        int tempn = this.n * other.n;
        int tempd = this.d * other.d;
    
        return new Frac(tempn, tempd);
    }
    
    public Frac div(Frac other)
    {
        int tempn = this.n * other.d;
        int tempd = this.d * other.n;
    
        return new Frac(tempn, tempd);
    }
    
    public double doubl()
    {
        return ((double) this.n) / this.d;
    }
    
    public boolean eq(Frac other)
    {
        return this.n == other.n && this.d == other.d;
    }
    
    public String toString()
    {
        return String.format("%d/%d", n, d);
    }
}

class Grid
{
    private int[] grid;
    public int xsize;
    public int ysize;
    public int xstart = 0;
    public int ystart = 0;    
    
    public Grid(int xsize, int ysize)
    {
        this.xsize = xsize;
        this.ysize = ysize;
        
        grid = new int[xsize * ysize];
    }
    
    public int get(int x, int y)
    {
        return grid[x + y * xsize];
    }
    
    public void set(int x, int y, int v)
    {
        grid[x + y * xsize] = v;
    }
    
    public void write()
    {
        for (int y = 0; y < ysize; y++)
        {
            for (int x = 0; x < xsize; x++)
            {
                System.out.print("" + get(x,y));
            }
            System.out.println();
        }
    }
    
    public Grid rotate()
    {
        Grid newg = new Grid(ysize, xsize);
        for (int x = 0; x < xsize; x++)
        {
            for (int y = 0; y < ysize; y++)
            {
                int v = get(x,y);
                int newx = ysize - y - 1;
                int newy = x;
                newg.set(newx, newy, v);
                if (v == 2 && (newx % 2) == 1 && (newy % 2) == 1)
                {
                    newg.xstart = newx;
                    newg.ystart = newy;
                }
            }
        }
        
        return newg;
    }
}

public class D
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        
        int ncases = sc.nextInt();
        for (int caseno = 0; caseno < ncases; caseno++)
        {
            int ysize = sc.nextInt() * 2;
            int xsize = sc.nextInt() * 2;
            int maxdist = sc.nextInt() * 2;
            
            Grid g = new Grid(xsize, ysize);
            
            for (int y = 0; y < (ysize / 2); y++)
            {
                String row = sc.next();
                for (int x = 0; x < (xsize / 2); x++)
                {
                    if (row.charAt(x) == '#')
                    {
                        g.set(x*2+0,y*2+0,1);
                        g.set(x*2+1,y*2+0,1);
                        g.set(x*2+1,y*2+1,1);
                        g.set(x*2+0,y*2+1,1);
                    }
                    else if (row.charAt(x) == 'X')
                    {
                        g.set(x*2+0,y*2+0,2);
                        g.set(x*2+1,y*2+0,2);
                        g.set(x*2+1,y*2+1,2);
                        g.set(x*2+0,y*2+1,2);
                        g.xstart = x * 2 + 1;
                        g.ystart = y * 2 + 1;
                    }
                }
            }
            
            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                // System.out.println("" + g.xstart);
                // System.out.println("" + g.ystart);
                // g.write();
                
                for (int xdiff = 0; xdiff < maxdist+2; xdiff += 2)
                {
                    for (int ydiff = 2; ydiff < maxdist+2; ydiff += 2)
                    {
                        if (xdiff * xdiff + ydiff * ydiff <= maxdist * maxdist)
                        {
                            boolean res = testray(g.xstart, g.ystart, xdiff, ydiff, g);
                            
                            if (res)
                                count += 1;
                                
                        }
                    }
                }
                    
                g = g.rotate();
            }
            
            System.out.printf("Case #%d: %d\n", caseno+1, count);
        }
    }
    
    public static boolean testray(int xstartt, int ystartt, int xdifff, int ydifff, Grid g)
    {
        //System.out.printf("%d %d %d %d\n", xstartt, ystartt, xdifff, ydifff);
        
        int xmirror = 1;
        int ymirror = 1;
        
        int xgrid = xstartt;
        int ygrid = ystartt;
        Frac xend = new Frac(xstartt + xdifff, 1);
        Frac yend = new Frac(ystartt + ydifff, 1);
        
        Frac xstart = new Frac(xstartt, 1);
        Frac ystart = new Frac(ystartt, 1);
        
        //System.out.println("" + xstart);
        Frac xdiff = xend.sub(xstart);
        Frac ydiff = yend.sub(ystart);
        
        Frac xslope = xdiff.div(ydiff);
        Frac yslope = ydiff.div(xdiff);
        
        Frac xpos = xstart;
        Frac ypos = ystart;
        
        while (true)
        {
            if (xpos.eq(xend) && ypos.eq(yend))
            {
                break;
            }
            
            int xcorner = xpos.n / xpos.d;
            int ycorner = ypos.n / ypos.d;
            
            Frac yedge = new Frac(ycorner + 1, 1);
            Frac xres = xpos.add(xslope.mul(yedge.sub(ypos)));
            
            Frac xedge = new Frac(xcorner + 1, 1);
            Frac yres = ypos.add(yslope.mul(xedge.sub(xpos)));
            
            double h = (xres.sub(xpos)).doubl();
            double v = (xedge.sub(xpos)).doubl();
            
            if (h < v)
            {
                xpos = xres;
                ypos = yedge;
                xcorner = xpos.n / xpos.d;
                int xmod = xpos.n % xpos.d;
                ycorner = ypos.n / ypos.d;
                int ymod = ypos.n % ypos.d;
                
                if (xmod == 0)
                {
                    ygrid += ymirror;
                    if (g.get(xgrid, ygrid) == 1)
                    {
                        ymirror *= -1;
                        ygrid += ymirror;
                    }
                    else if (g.get(xgrid, ygrid) == 2 && (ycorner % 2) == 1)
                    {
                        if (xpos.eq(xend) && ypos.eq(yend))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    ygrid += ymirror;
                    if (g.get(xgrid, ygrid) == 1)
                    {
                        ymirror *= -1;
                        ygrid += ymirror;
                    }
                }
            }
            else if (v < h)
            {
                xpos = xedge;
                ypos = yres;
                xcorner = xpos.n / xpos.d;
                int xmod = xpos.n % xpos.d;
                ycorner = ypos.n / ypos.d;
                int ymod = ypos.n % ypos.d;

                xgrid += xmirror;
                if (g.get(xgrid, ygrid) == 1)
                {
                    xmirror *= -1;
                    xgrid += xmirror;
                }
            }
            else
            {
                xpos = xedge;
                ypos = yedge;
                xcorner = xpos.n / xpos.d;
                int xmod = xpos.n % xpos.d;
                ycorner = ypos.n / ypos.d;
                int ymod = ypos.n % ypos.d;
                
                int blockE  = g.get(xgrid + xmirror, ygrid);
                int blockSE = g.get(xgrid + xmirror, ygrid + ymirror);
                int blockS  = g.get(xgrid, ygrid + ymirror);
                
                if (blockE == 2 && blockSE == 2 && blockS == 2)
                {
                    if (xpos.eq(xend) && ypos.eq(yend))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                    
                if (blockE == 2)
                    blockE = 0;
                if (blockSE == 2)
                    blockSE = 0;
                if (blockS == 2)
                    blockS = 0;
                
                if (blockE == 0 && blockSE == 0 && blockS == 0)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                }
                else if (blockE == 1 && blockSE == 0 && blockS == 0)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                }
                else if (blockE == 1 && blockSE == 0 && blockS == 1)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                }
                else if (blockE == 0 && blockSE == 0 && blockS == 1)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                }
                else if (blockE == 0 && blockSE == 1 && blockS == 0)
                {
                    return false;
                }
                else if (blockE == 1 && blockSE == 1 && blockS == 0)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                    xmirror *= -1;
                    xgrid += xmirror;
                }
                else if (blockE == 0 && blockSE == 1 && blockS == 1)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                    ymirror *= -1;
                    ygrid += ymirror;
                }
                else if (blockE == 1 && blockSE == 1 && blockS == 1)
                {
                    xgrid += xmirror;
                    ygrid += ymirror;
                    xmirror *= -1;
                    ymirror *= -1;
                    xgrid += xmirror;
                    ygrid += ymirror;
                }

            }
        }
        return false;
    }
}