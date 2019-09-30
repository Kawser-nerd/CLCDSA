using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;
using static Reader;

class P
{
    static void Main()
    {
        ((NextInt - 1) * (NextInt - 1)).WriteLine();
    }
}

#region io
static class Reader
{
    static TextReader stdinReader = Console.In;

    public static char NextChar => (char)stdinReader.Read();
    public static int NextInt => ReadInt();
    public static long NextLong => ReadLong();
    public static string NextString => ReadString();
    public static IEnumerable<int> NextIntCollection => ReadIntCollection();
    public static IEnumerable<long> NextLongCollection => ReadLongCollection();
    public static IEnumerable<string> NextStringCollection => ReadStringCollection();
    public static string NextLine => stdinReader.ReadLine();

    public static int ReadInt()
    {
        int i;
        bool isNegative;
        checked
        {
            i = 0;
            isNegative = false;
            char next = NextChar;
            while (char.IsWhiteSpace(next)) next = NextChar;
            while (true)
            {
                if (!char.IsDigit(next))
                {
                    if (next == '-')
                    {
                        isNegative = true;
                    }
                    else if (next != '+') break;
                }
                else
                {
                    i *= 10;
                    i += next - '0';
                }
                next = NextChar;
            }
        }
        return isNegative ? -i : i;
    }

    public static long ReadLong()
    {
        long i;
        bool isNegative;
        checked
        {
            i = 0;
            isNegative = false;
            char next = NextChar;
            while (char.IsWhiteSpace(next)) next = NextChar;
            while (true)
            {
                if (!char.IsDigit(next))
                {
                    if (next == '-')
                    {
                        isNegative = true;
                    }
                    else if (next != '+') break;
                }
                else
                {
                    i *= 10;
                    i += next - '0';
                }
                next = NextChar;
            }
        }
        return isNegative ? -i : i;
    }

    public static string ReadString()
    {
        StringBuilder builder = new StringBuilder();
        char next = NextChar;
        while (char.IsWhiteSpace(next)) next = NextChar;
        while (true)
        {
            if (char.IsWhiteSpace(next)) break;
            builder.Append(next);
            next = NextChar;
        }
        return builder.ToString();
    }

    public static IEnumerable<int> ReadIntCollection()
    {
        int i;
        bool isNegative;
        char next;
        while (true)
        {
            i = 0;
            isNegative = false;
            next = NextChar;
            while (char.IsWhiteSpace(next)) next = NextChar;
            while (true)
            {
                if (!char.IsDigit(next))
                {
                    if (next == '-')
                    {
                        isNegative = true;
                    }
                    else if (next != '+') break;
                }
                else
                {
                    i *= 10;
                    i += next - '0';
                }
                next = NextChar;
            }
            yield return isNegative ? -i : i;
            if (!char.IsSeparator(next)) break;
        }
    }

    public static IEnumerable<long> ReadLongCollection()
    {
        long i;
        bool isNegative;
        char next;
        while (true)
        {
            i = 0;
            isNegative = false;
            next = NextChar;
            while (char.IsWhiteSpace(next)) next = NextChar;
            while (true)
            {
                if (!char.IsDigit(next))
                {
                    if (next == '-')
                    {
                        isNegative = true;
                    }
                    else if (next != '+') break;
                }
                else
                {
                    i *= 10;
                    i += next - '0';
                }
                next = NextChar;
            }
            yield return isNegative ? -i : i;
            if (!char.IsSeparator(next)) break;
        }
    }

    public static IEnumerable<string> ReadStringCollection()
    {
        StringBuilder builder = new StringBuilder();
        char next;
        while (true)
        {
            builder.Clear();
            next = NextChar;
            while (char.IsWhiteSpace(next)) next = NextChar;
            while (true)
            {
                if (char.IsWhiteSpace(next)) break;
                builder.Append(next);
                next = NextChar;
            }
            yield return builder.ToString();
            if (!char.IsSeparator(next)) break;
        }
    }
}

static class Writer
{
    public static void WriteLine<T>(this T item) => Console.WriteLine(item);

    public static void WriteLog<T>(this T item) => Debug.WriteLine(item);
}
#endregion