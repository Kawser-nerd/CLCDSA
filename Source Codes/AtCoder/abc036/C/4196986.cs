using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Build
{
    int h;
    int w;
    int r;
    int c;
    static int idGen = 1;
    public int Id { get;}
    public int Height { get { return h;} }
    public int Width { get { return w;} }
    public int DoorR { get { return r;} }
    public int DoorC { get { return c;} }
    public Build(string[] args)
    {
        h = int.Parse(args[0]);
        w = int.Parse(args[1]);
        r = int.Parse(args[2]) - 1;
        c = int.Parse(args[3]) - 1;
        Id = idGen++;
    }
}

class Program
{
    static int Bisect(int target, int[] data)
    {
        int start = 0;
        for(int end = data.Length - 1; start <= end; )
        {
            int mid = (start + end) / 2;
            if(data[mid] == target)
            {
                return mid;
            }
            if(data[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
    public void Slove()
    {   
        int n = int.Parse(Console.ReadLine());
        int[] data =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine())
            .Select(int.Parse)
            .ToArray();
        int[] sorted =
            data.Distinct()
            .OrderBy(x => x)
            .ToArray();

        Console.WriteLine(string.Join("\n", data.Select(x => Bisect(x, sorted))));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}