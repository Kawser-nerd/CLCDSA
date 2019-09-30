using System;

public class AtCoderFourAdjacent 
{
    public static void Main(String[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int numDivisibleByFour = 0;
        int numOdd = 0;
        foreach (var e in arr)
        {
            if (e % 2 != 0)
            {
                numOdd++;
            }
            else if (e % 4 == 0)
            {
                numDivisibleByFour++;
            }
        }

        if (numDivisibleByFour >= numOdd)
        {
            Console.WriteLine("Yes");
        }
        else if (numDivisibleByFour == (numOdd - 1) &&
                numDivisibleByFour + numOdd == n)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}