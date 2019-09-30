using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main() { Models.GetInstance.Run(); }
    }

    public class Models
    {
        static Models instance = new Models();
        private Models() { }

        public static Models GetInstance
            {get{return instance;} }

        public void Run()
        {
            double Ans = 0;
            int n = int.Parse(Console.ReadLine());
            List<PointClass> Points = new List<PointClass>();
            PointClass tmpPoint;

            for (int i = 0; i < n; i++)
            {
                string[] line = Console.ReadLine().Split(' ');
                tmpPoint = new PointClass();
                tmpPoint.x = int.Parse(line[0]);
                tmpPoint.y = int.Parse(line[1]);
                Points.Add(tmpPoint);
            }

            foreach (PointClass tmpP in Points)
            {
                foreach (PointClass tmpQ in Points)
                {
                    double comparator = tmpP.CalcDistance(tmpP, tmpQ);
                    if (comparator < Ans) continue;
                    Ans = comparator;
                }
            }

            Console.WriteLine(Ans);
            ;


        }

    }

    public class PointClass
    {
        public int x;
        public int y;

        public PointClass()
        { }

        public double CalcDistance(PointClass a, PointClass b)
        {
            if (a == b)
            { return 0; }

            double tmpDis;

            tmpDis = Math.Sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));

            return tmpDis;
        }
    }
        
    
}