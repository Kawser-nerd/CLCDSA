using System;
using System.IO;
using System.Linq;

namespace KyoproCSharp
{
    public class Program
    {
        public static void Main()
        {
            var writer = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Resolve(Console.In, writer);
            writer.Flush();
        }

        public void Resolve(TextReader reader, TextWriter writer)
        {
            var S = reader.ReadToEnd().Trim();
            var red = S.Count(_=>_=='0');
            var blue = S.Count(_=>_=='1');
            writer.WriteLine(red+blue - Math.Abs(red-blue));
        }
    }
}