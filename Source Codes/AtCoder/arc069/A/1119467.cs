class Program
{
    static void Main(string[] args)
    {
        string line = System.Console.ReadLine().Trim();

        string[] Data = line.Split(' ');
        long N = long.Parse(Data[0]);
        long M = long.Parse(Data[1]);


        if(N*2 <= M)
        {
            long x = N + (M - N * 2L) / 4L;
            System.Console.WriteLine(x);
        }
        else
        {
            long x = M / 2L;
            System.Console.WriteLine(x);
        }             
    }
}