using System;
using System.Text;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Runtime.InteropServices.ComTypes;
using DNNX.GoogleCodeJam.Common;

namespace DNNX.GoogleCodeJam.HouseOfKittens
{
    public class HouseOfKittens : Solution<Tuple<int, int[], int[]>>
    {
        public HouseOfKittens(TextReader input, TextWriter output)
            : base(input, output)
        {
        }
        
        public HouseOfKittens() {}
        
        public override object Solve(Tuple<int, int[], int[]> input)
        {
            int n = input.Item1;
            int[] u = input.Item2;
            int[] v = input.Item3;
            List<List<int>> rooms = new List<List<int>>(u.Length + 1);
            List<int> room0 = new List<int>(n);
            for (int i=1; i<=n; ++i)
                room0.Add(i);
            rooms.Add(room0);
            for (int i=0; i<u.Length; ++i)
            {
                List<int> room = FindRoom(rooms, u[i], v[i]);
                int x = room.IndexOf(u[i]);
                int y = room.IndexOf(v[i]);
                if (x > y)
                {
                    int tmp = x; x = y; y = tmp;
                }
                List<int> newRoom = room.GetRange(x, y-x+1);
                room.RemoveRange(x+1, y-x-1);
                rooms.Add(newRoom);
            }
            int minc = 100000;
            int maxc = 0;
            foreach (var room in rooms)
            {
                if (minc > room.Count)
                    minc = room.Count;
                if (maxc < room.Count)
                    maxc = room.Count;
            }
            int[] maxSol = new int[n];
            int max = 1;
            for (int i=0; i<n; ++i)
                maxSol[i] = 1;
            
            int top = (int)Math.Pow(maxc, n);
            int[] sol = new int[n];
            int maxMask = 1;
            
            for (int code = 0; code < top; ++code)
            {
                int mask = 0;
                int cd = code;
                for (int i=0; i<n; ++i)
                {
                    mask |= 1 << (cd % maxc);
                    sol[i] = cd % maxc;
                    cd /= maxc;
                }
                if ((mask & (mask + 1)) != 0)
                    continue;
                if (maxMask >= mask)
                    continue;
                int num = 0;
                int m = mask;
                while (m > 0) { ++num; m >>= 1; }
                
                bool allOk = true;
                foreach (var room in rooms)
                {
                    int rmask = 0;
                    foreach (int nip in room)
                    {
                        rmask |= 1 << sol[nip-1];
                    }
                    if (rmask != mask)
                    {
                        allOk = false;
                        break;
                    }
                }
                if (!allOk)
                    continue;
                for (int i=0; i<n; ++i)
                {
                    maxSol[i] = sol[i] + 1;
                }
                maxMask = mask;
                max = num;
            }
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(max.ToString());
            foreach (int i in maxSol){
                sb.Append(i);
                sb.Append(' ');
            }
            return sb.ToString();
        }
        
        
        public List<int> FindRoom(List<List<int>> rooms, int x, int y)
        {
            foreach (var room in rooms)
                if (room.Contains(x) && room.Contains(y))
                    return room;
            return null;
        }
        
        public override Tuple<int, int[], int[]> ReadTestCase()
        {
            int[] a = ReadInts();
            int n = a[0];
            int[] u = ReadInts();
            int[] v = ReadInts();
            return Tuple.Create(n, u, v);
        }
    
        public static void Main(string[] args)
        {
            new HouseOfKittens().REPL();
//            Console.ReadLine();
        }    
    }
}