using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


class Program
{

    public void Slove()
    {      
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] top = new int[3];
        foreach(int num1 in Enumerable.Range(0, inputs.Length))
            foreach(int num2 in Enumerable.Range(0, inputs.Length).Skip(num1 + 1))
            {
                int sum = inputs[num1] + inputs[num2];
                foreach(int num3 in Enumerable.Range(0, inputs.Length).Skip(num2 + 1))
                {
                    int tSum = sum + inputs[num3];
                    if(top[0] < tSum)
                    {
                        //Console.WriteLine($"{inputs[num1]} {inputs[num2]} {inputs[num3]} {tSum}");
                        top[0] = tSum;
                        top = top.OrderBy(x => x).ToArray();
                    }
                }
            }
        Console.WriteLine(top[0]);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}