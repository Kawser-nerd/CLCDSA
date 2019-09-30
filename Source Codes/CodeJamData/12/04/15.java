import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;

public class D
{
    static int gcd(int a, int b) { return b == 0 ? a : a == 0 ? b : gcd(b, a%b); }
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for(int t = 0; t++ < T; )
        {
            String[] line = br.readLine().split(" ");
            int H = parseInt(line[0]), W = parseInt(line[1]), D = parseInt(line[2]);
            char[][] G = new char[H][];
            for(int h = 0; h < H; h++)
                G[h] = br.readLine().toCharArray();
            int X = 0, Y = 0;
            outer:for(Y = 0; Y < H; Y++)
                for(X = 0; X < W; X++)
                    if(G[Y][X] == 'X')
                        break outer;
            int count = 0;
            for(int i = -D; i <= D; i++)
            {
                for(int j = -D; j <= D; j++)
                {
                    int dx = i, dy = j, scale = 2 * Math.abs((dx == 0 ? 1 : dx) * (dy == 0 ? 1 : dy)), x0, y0, x, y;
                    int steps = (int)Math.floor(scale * D / Math.sqrt(dx * dx + dy * dy));
                    if(gcd(Math.abs(dx), Math.abs(dy)) != 1)
                        continue;
                    x0 = x = X * scale + scale / 2;
                    y0 = y = Y * scale + scale / 2;
                    do
                    {
                        steps -= 1;
                        if(x % scale == 0 && y % scale == 0)
                        {
                            // at a corner
                            int dxi = dx > 0 ? 1 : -1, dyi = dy > 0 ? 1 : -1;
                            int xi = (x / scale) - (dxi + 1) / 2, yi = (y / scale) - (dyi + 1) / 2;
                            if(G[yi+dyi][xi+dxi] == '#')
                            {
                                if(G[yi+dyi][xi] != '#' && G[yi][xi+dxi] != '#')
                                    steps = -1; // kill the light
                                if(G[yi+dyi][xi] == '#')
                                    dy *= -1;
                                if(G[yi][xi+dxi] == '#')
                                    dx *= -1;
                            } else ;
                                // otherwise step as normal
                        } else if(x % scale == 0) {
                            int xi = x / scale, yi = y / scale;
                            if(G[yi][xi] == '#' || G[yi][xi-1] == '#')
                                dx *= -1;
                        } else if(y % scale == 0) {
                            int xi = x / scale, yi = y / scale;
                            if(G[yi][xi] == '#' || G[yi-1][xi] == '#')
                                dy *= -1;
                        } else ;
                            // smooth sailing
                        x += dx;
                        y += dy;
                    } while(steps >= 0 && !(x == x0 && y == y0));
                    if(steps >= 0)
                        ++count;
                }
            }
            out.println("Case #" + t +": " + count) ; 
        }
    }
}
