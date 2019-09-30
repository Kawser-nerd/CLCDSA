using System;
using System.Text;
using System.IO;
using System.Globalization;
using System.Collections.Generic;

namespace ConsoleApplication21
{
    class Program
    {
        static void Main()
        {
            StreamScanner sc = new StreamScanner(Console.OpenStandardInput());
            double P = sc.Double();
            double a = 0;
            double b = P;
            while (b - a > 0.00000001)
            {
                double X1 = (b - a) / 3 + a;
                double X2 = (b - a) * 2 / 3 + a;
                double x1 = P / Math.Pow(2, X1 / 1.5) + X1;
                double x2 = P / Math.Pow(2, X2 / 1.5) + X2;
                if (x1 > x2)
                    a = X1;
                else
                    b = X2;
            }
            Console.Write(P / Math.Pow(2, a / 1.5) + a + "\n");
        }
        public class StreamScanner
        {
            public StreamScanner(Stream stream) { str = stream; }
            private readonly Stream str;
            private readonly byte[] buf = new byte[1024];
            private long len, ptr;
            public bool isEof = false;
            public bool IsEndOfStream { get { return isEof; } }
            private byte read()
            {
                if (isEof) throw new EndOfStreamException();
                if (ptr >= len)
                {
                    ptr = 0;
                    if ((len = str.Read(buf, 0, 1024)) <= 0)
                    {
                        isEof = true;
                        return 0;
                    }
                }
                return buf[ptr++];
            }
            public char Char()
            {
                byte b = 0;
                do b = read();
                while (b < 33 || 126 < b);
                return (char)b;
            }
            public string Scan()
            {
                var sb = new StringBuilder();
                for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                    sb.Append(b);
                return sb.ToString();
            }
            public long Long()
            {
                long ret = 0; byte b = 0; var ng = false;
                do b = read();
                while (b != '-' && (b < '0' || '9' < b));
                if (b == '-') { ng = true; b = read(); }
                for (; true; b = read())
                {
                    if (b < '0' || '9' < b)
                        return ng ? -ret : ret;
                    else ret = ret * 10 + b - '0';
                }
            }
            public int integer() { return (int)Long(); }
            public double Double() { return double.Parse(Scan(), CultureInfo.InvariantCulture); }
        }
    }
}