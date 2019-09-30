using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


class Program
{
    static int GetCount(int[] scheduleX, int[] scheduleY, int x, int y)
    {        
        int n = scheduleX.Length;
        int m = scheduleY.Length;
        int xi = 0;
        int yi = 0;
        int time = 0;
        int count = 0;
        while(true)
        {
            while(time > scheduleX[xi])
            {
                xi++;
                if(xi == n)
                    return count;
            }
            time = scheduleX[xi] + x;
            while(time > scheduleY[yi])
            {
                yi++;
                if(yi == m)
                    return count;
            }
            time = scheduleY[yi] + y;
            count++;
            //Console.WriteLine(time);
        }
    }
    public void Slove()
    {    
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        inputs = Console.ReadLine().Split();
        int xTime = int.Parse(inputs[0]);
        int yTime = int.Parse(inputs[1]);
        int[] scheduleX = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .ToArray(); 
        int[] scheduleY = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .ToArray();
        int result = GetCount(scheduleX, scheduleY, xTime, yTime);
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}