using System;

public class GridColoring
{
    public static void Main(string[] args)
    {
        int[] dimension = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int h = dimension[0];
        int w = dimension[1];
        int n = int.Parse(Console.ReadLine());
        int[] occuranceCountArr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

        int[,] result = new int[h, w];
        int rollingPointer = 0;
        for (int i = 0; i < occuranceCountArr.Length; i++)
        {
            int ai = (i + 1);
            int aiCount = occuranceCountArr[i];
            for (int c = 0; c < aiCount; c++)
            {
                int rollingRow = rollingPointer / w;
                int rollingColumn = ((rollingPointer / w) % 2 == 0) ? (rollingPointer % w) : (w - 1 - (rollingPointer % w));
                //Console.WriteLine("rollingPointer = {0}, rollingRow = {1}, rollingColumn = {2}, ai={3}", rollingPointer, rollingRow, rollingColumn, ai);
                result[rollingRow, rollingColumn] = ai;
                rollingPointer++;
            }
        }

        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                Console.Write(result[r, c] + " ");
            }
            Console.WriteLine();
        }
    }
}