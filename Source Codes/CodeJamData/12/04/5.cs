using System;
using System.Collections.Generic;
using System.Linq;


public struct BresenhamStep
{
    public int dx;
    public int dy;
    public BresenhamStep(int dx, int dy)
    {
        this.dx = dx;
        this.dy = dy;
    }
}

public class MirrorMaze
{
    string[] m_walls;
    int m_startX;
    int m_startY;
    int m_locX;
    int m_locY;
    int m_plusX;
    int m_plusY;
    bool m_blocked;
    public bool PlayerAt(int x, int y)
    {
        return m_walls[y][x]=='X';
    }
    public bool MirrorAt(int x, int y)
    {
        return m_walls[y][x]=='#';
    }
    public void Walk(int dx, int dy)
    {
        int x = m_locX;
        int y = m_locY;
        dx *= m_plusX;
        dy *= m_plusY;
        bool mirrorVert = MirrorAt(x,y+dy);
        bool mirrorHoriz = MirrorAt(x+dx,y);
        bool mirrorCorner = MirrorAt(x+dx,y+dy);
        if (dx!=0 && dy!=0)
        {
            // Diagonal movement.
            if (!mirrorCorner)
            {
                // Straight through.
                m_locX += dx;
                m_locY += dy;
                return;
            }
            if (!mirrorHoriz && !mirrorVert)
            {
                // Hit a convex corner. Blocked.
                m_blocked=true;
                return;
            }
            // Hit a flat mirror or a concave corner.
        }
        if (dx!=0)
        {
            if (mirrorHoriz)
            {
                m_plusX *= -1;
            }
            else
            {
                m_locX += dx;
            }
        }
        if (dy!=0)
        {
            if (mirrorVert)
            {
                m_plusY *= -1;
            }
            else
            {
                m_locY += dy;
            }
        }
    }
    public bool MirrorHere() { return MirrorAt(m_locX, m_locY); }
    public bool Blocked { get { return m_blocked; } }
    public bool PlayerHere() { return PlayerAt(m_locX, m_locY); }
    public void Reset()
    {
        m_locX = m_startX;
        m_locY = m_startY;
        m_blocked = false;
        m_plusX = 1;
        m_plusY = 1;
    }
    public MirrorMaze(IEnumerable<string> walls)
    {
        m_walls = walls.ToArray();
        int width = m_walls[0].Length;
        int height = m_walls.Length;
        for (int y=0; y!=height; ++y)
        {
            for (int x=0; x!=width; ++x)
            {
                if (PlayerAt(x,y))
                {
                    m_startX = x;
                    m_startY = y;
                }
            }
        }
        Reset();
    }

}

class Mirrors
{
    public static IEnumerable<BresenhamStep> Bresenham(int dx, int dy)
    {
        //Console.WriteLine("{0},{1}", dx, dy);
        if (dx==0 && dy==0)
        {
            yield break;
        }
        int mx = dx>=0 ? 1 : -1;
        int my = dy>=0 ? 1 : -1;
        dx *= mx;
        dy *= my;
        int tx = 0;
        int ty = 0;
        //int ax = 0; //?
        if (dx>=dy)
        {
            int acc = dx - dy; //?
            while (tx<dx)
            {
                acc+=2*dy;
                if (acc==2*dx)
                {
                    tx += 1;
                    ty += 1;
                    acc-=2*dx;
                    yield return new BresenhamStep(mx, my);
                    continue;
                }
                if (acc>2*dx)
                {
                    ty += 1;
                    acc-=2*dx;
                    yield return new BresenhamStep(0, my);
                }
                tx += 1;
                yield return new BresenhamStep(mx, 0);
            }
        }
        else
        {
            foreach (var step in Bresenham(dy, dx))
            {
                yield return new BresenhamStep(step.dy*mx, step.dx*my);
            }
        }
    }

    static int Gcd(int a, int b)
    {
        a = a<0?-a:a;
        b = b<0?-b:b;
        while (true)
        {
            if (a==0) return b;
            if (b==0) return a;
            if (a==b) return a;
            int tmp = a % b;
            a = b;
            b = tmp;
        }
    }

    public static int SolveCase()
    {
        int[] values = Console.ReadLine().Trim().Split().Select(s=>int.Parse(s)).ToArray();
        int height = values[0];
        //int width = values[1];
        int visibility = values[2];
        int vis_sq = visibility * visibility;
        var maze = new MirrorMaze(Enumerable.Range(0,height).Select(x=>Console.ReadLine().Trim()));
        int images = 0;

        // For debugging, track which cells we decided to have a visible image:
        //bool[,] matches = new bool[2*visibility+1, 2*visibility+1];
        
        // Cast a ray toward the centre of every cell in range of our
        // starting point.
        for (int x=-visibility; x<=visibility; ++x)
        {
            for (int y=-visibility; y<=visibility; ++y)
            {
                if (x*x+y*y>vis_sq) continue;
                if (x==0 && y==0) continue;
                // The cell is in range and not our starting point.
                maze.Reset();
                int cx = 0;
                int cy = 0;
                bool blocked = false;
                int gcd = Gcd(x,y);
                // Find the sequence of cells the ray crosses through.
                foreach (var step in Bresenham(x,y))
                {
                    cx += step.dx;
                    cy += step.dy;
                    bool perfectX = x==0 || cx%(x/gcd)==0;
                    bool perfectY = y==0 || cy%(y/gcd)==0;
                    maze.Walk(step.dx, step.dy);
                    // Rays are blocked when:
                    //     * they hit a convex mirror edge (maze reports Blocked)
                    //     * they pass through the player (except when the player is in the target cell)
                    if (perfectX && perfectY && maze.PlayerHere() && (cx!=x||cy!=y) || maze.Blocked)
                    {
                        blocked = true;
                        break;
                    }
                }
                if (blocked) continue;
                if (maze.PlayerHere())
                {
                    images += 1;
                }
            }
        }
        /*for (int y=-visibility; y<=visibility; ++y)
        {
            for (int x=-visibility; x<=visibility; ++x)
            {
                Console.Write(matches[y+visibility,x+visibility]?"Y":".");
            }
            Console.WriteLine();
        }*/
        return images;
    }

    public static void Main()
    {
        int cases = int.Parse(Console.ReadLine().Trim());
        for (int i=0; i!=cases; ++i)
        {
            int images = SolveCase();
            Console.WriteLine("Case #{0}: {1}", i+1, images);
        }
    }

}
