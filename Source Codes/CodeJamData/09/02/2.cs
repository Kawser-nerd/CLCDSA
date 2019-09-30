using System;
using System.Linq;

class Watersheds
{
    char nextBasin = 'a';

    String NewBasin()
    {
        return (nextBasin++).ToString();
    }

    static void Main(string[] args)
    {
        var mapsCount = Int32.Parse(Console.ReadLine());

        for (int caseNumber = 0; caseNumber < mapsCount; caseNumber++)
        {
            Console.WriteLine("Case #{0}:", caseNumber+1);
            var split = Console.In.ReadLine().Split(' ');

            int H = int.Parse(split[0]);
            int W = int.Parse(split[1]);

            int[,] heights = new int[H, W];
            for (int i = 0; i < H; i++)
            {
                String [] mapLine = Console.ReadLine().Split();

                for (int j = 0; j < W; j++)
                    heights[i, j] = int.Parse(mapLine[j]);
            }

            new Watersheds(H, W, heights).Solve();
        }

    }

    String[,] labels;
    int[,] heights;
    int W;
    int H;

    public Watersheds(int H, int W, int[,] heights)
    {
        this.W = W;
        this.H = H;
        this.heights = heights;
    }

    private void Solve()
    {
        labels = new String[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (j != 0)
                    Console.Write(' ');
                Console.Write(getLabel(i, j));
            }
            Console.WriteLine();
        }
    }

    private string getLabel(int i, int j)
    {
        if (labels[i, j] != null)
            return labels[i, j];

        int newi, newj;

        bool isSink = !chooseDirection(i, j, out newi, out newj);

        string result;

        if (isSink)
            result = NewBasin();
        else
            result = getLabel(newi, newj);

        labels[i, j] = result;
        return result;
    }

    private bool chooseDirection(int i, int j, out int newi, out int newj)
    {
        var coords = new []{new{i=i-1, j=j}, new{i=i, j=j-1}, new{i=i, j=j+1}, new{i=i+1, j=j}}
            .Where(c => isValid(c.i, c.j));

        if(!coords.Any())
        {
            newj = -1;
            newi = -1;
            return false;
        }
        int minimalHeight = coords.Min(c => heights[c.i, c.j]);
        if (minimalHeight >= heights[i, j])
        {
            newj = -1;
            newi = -1;
            return false;
        }

        var result = coords.First(c => heights[c.i, c.j] == minimalHeight);

        newi = result.i;
        newj = result.j;

        return true;
    }

    private bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < H && j < W;
    }
}