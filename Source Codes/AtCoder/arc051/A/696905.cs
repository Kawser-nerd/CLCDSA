using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] red = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] blue = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool isRed = false;
            bool isBlue = false;
            if (blue[0] <= red[0] - red[2] && red[0] + red[2] <= blue[2] &&
                blue[1] <= red[1] - red[2] && red[1] + red[2] <= blue[3])
            {
                isRed = false;
            }
            else isRed = true;

            if ((red[0] - blue[0]) * (red[0] - blue[0]) +
                (red[1] - blue[1]) * (red[1] - blue[1]) <= red[2] * red[2] &&
                (red[0] - blue[0]) * (red[0] - blue[0]) +
                (red[1] - blue[3]) * (red[1] - blue[3]) <= red[2] * red[2] && 
                (red[0] - blue[2]) * (red[0] - blue[2]) +
                (red[1] - blue[1]) * (red[1] - blue[1]) <= red[2] * red[2] &&
                (red[0] - blue[2]) * (red[0] - blue[2]) +
                (red[1] - blue[3]) * (red[1] - blue[3]) <= red[2] * red[2] 
                )
            {
                isBlue = false;
            }
            else isBlue = true;


            if (isRed) Console.WriteLine("YES");
            else Console.WriteLine("NO");
            if (isBlue) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}