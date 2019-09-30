using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var io = new StandardIO();
        new Process(io).Run();
    }

}

class Process
{
    public Process(IIO io)
    {
        this.io = io;
    }

    IIO io;

    public void Run()
    {
        var ns = io.GetIntegerArray();
        int n = io.GetInteger();

        long one = new long[] { ns[0] * 4, ns[1] * 2, ns[2] }.Min();
        long two = new long[] { one * 2, ns[3] }.Min();

        long r = (n / 2) * two + (n % 2) * one;
        io.Write(r.ToString());
    }
}

public interface IIO
{
    string Get();
    void Write(string s);
    void Flush();
}

public class StandardIO : IIO
{
    string IIO.Get()
    {
        return Console.ReadLine();
    }

    void IIO.Write(string s)
    {
        Console.WriteLine(s);
    }

    void IIO.Flush()
    {
        Console.Out.Flush();
    }
}

public static class InputExtension
{
    public static int GetInteger(this IIO input)
    {
        return int.Parse(input.Get());
    }

    public static string[] GetStrings(this IIO input, char separator = ' ')
    {
        return input.Get().Split(separator);
    }

    public static int[] GetIntegerArray(this IIO input, char separator = ' ')
    {
        return input.GetStrings().Select(s => int.Parse(s)).ToArray();
    }
}