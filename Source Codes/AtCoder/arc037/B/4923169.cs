using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {        
        public bool Flag;
        static void Main(string[] args)
        {
            Program instance = new Program();
            instance.Run();
        }

        public void Run()
        {
            int ret = 0;
            List<PointClass> Points = new List<PointClass>();

            int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();

            //??????
            for (int i = 1; i <= nm[0]; i++)
            {
                PointClass tmpPoint = new PointClass();
                tmpPoint.Num = i;
                Points.Add(tmpPoint);
            }

            for (int i = 0; i < nm[1]; i++)
            {
                int[] uv = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Points[uv[0] - 1].Connections.Add(Points[uv[1] - 1]);
                Points[uv[1] - 1].Connections.Add(Points[uv[0] - 1]);
            }

            PointClass EntryP = new PointClass();
            foreach (PointClass tmpPoint in Points)
            {
                if (tmpPoint.CheckedFkag) continue;

                Flag = true;
                DFS(tmpPoint, EntryP);
                if (Flag) ret++;

            }

            Console.WriteLine(ret);
        }

        public void DFS(PointClass NewP, PointClass BeforeP)
        {
            if (NewP.VisitedFlag) { Flag = false; return; }

            NewP.VisitedFlag = true;
            NewP.CheckedFkag = true;

            if (NewP.Connections.Count > 0)
            {
                foreach (PointClass tmpP in NewP.Connections)
                {
                    if (tmpP == BeforeP) continue;
                    DFS(tmpP, NewP);
                }
            }

            return;

        }
    }

    class PointClass
    {
        public int Num;

        public bool VisitedFlag; //DFS?????

        public bool CheckedFkag;

        public List<PointClass> Connections = new List<PointClass>();

        public PointClass()
        { }
    }
}