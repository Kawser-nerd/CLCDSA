using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static string[] mp;
        static bool inrange(int t, int di, int dj, int i, int j, int r, int c)
        {
            int ii=i + di * t;
            int jj=j + dj * t;
            return ii >= 0 && jj >= 0 && ii < r && jj < c;
        }
        static void Main(string[] args)
        {
            int tt= int.Parse(Console.ReadLine());
            StreamWriter s=new StreamWriter(File.Open("o.out", FileMode.Create));
            for(int cc=1; cc <= tt; cc++)
            {
                string[] ss=Console.ReadLine().Split(new char[] { ' ' });
                int r=int.Parse(ss[0]);
                int c=int.Parse(ss[1]);

                bool lose=false;
                int ans=0;

                mp = new string[r];
                for(int i=0; i < r; i++)
                    mp[i] = Console.ReadLine();

                for(int i=0; i < r; i++)
                    for(int j=0; j < c; j++) {
                        if(mp[i][j] == '.')
                            continue;

                        int di,dj;
                        switch(mp[i][j])
                        {
                            case '<':
                                di=0;dj=-1;break;
                            case '>':
                                di=0;dj=1;break;
                            case '^':
                                di = -1;dj=0;break;
                            case 'v':
                                di = 1;dj=0;break;
                            default:
                                throw new Exception();
                        }

                        bool has_arrow=false;
                        for(int t=1; inrange(t, di, dj, i, j, r, c); t++)
                        {
                            if(mp[i+t*di][j+t*dj] != '.')
                                has_arrow=true;
                        }
                        bool final_has_arrow=false;
                        if(!has_arrow)
                        {
                            di = 0;
                            dj = -1;
                            has_arrow = false;
                            for(int t=1; inrange(t, di, dj, i, j, r, c); t++)
                            {
                                if(mp[i + t * di][j + t * dj] != '.')
                                    has_arrow = true;
                            }
                            if(has_arrow)
                                final_has_arrow = true;
                            di = 0;
                            dj = 1;
                            has_arrow = false;
                            for(int t=1; inrange(t, di, dj, i, j, r, c); t++)
                            {
                                if(mp[i + t * di][j + t * dj] != '.')
                                    has_arrow = true;
                            }
                            if(has_arrow)
                                final_has_arrow = true;
                            di = 1;
                            dj = 0;
                            has_arrow = false;
                            for(int t=1; inrange(t, di, dj, i, j, r, c); t++)
                            {
                                if(mp[i + t * di][j + t * dj] != '.')
                                    has_arrow = true;
                            }
                            if(has_arrow)
                                final_has_arrow = true;
                            di = -1;
                            dj = 0;
                            has_arrow = false;
                            for(int t=1; inrange(t, di, dj, i, j, r, c); t++)
                            {
                                if(mp[i + t * di][j + t * dj] != '.')
                                    has_arrow = true;
                            }
                            if(has_arrow)
                                final_has_arrow = true;
                        }
                        if(final_has_arrow)
                            ans++;
                        else if(!has_arrow)
                            lose = true;
                    }

                if(lose)
                {
                    Console.WriteLine("Case #" + cc.ToString() + ": IMPOSSIBLE");
                    s.WriteLine("Case #" + cc.ToString() + ": IMPOSSIBLE");
                }
                else
                {
                    Console.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString());
                    s.WriteLine("Case #" + cc.ToString() + ": " + ans.ToString());
                }
            }
        }
    }
}
