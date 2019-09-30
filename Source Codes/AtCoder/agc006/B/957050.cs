using LIB;
using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;

class Program
{
    public static IO IO = new IO();
    static void Main(string[] args)
    {
        int[] _a = IO.INT(' ');
        int N = _a[0];
        int x = _a[1];
        int a = 2 * N - 1;
        List<int> m = new List<int>();
        if (x > 1 && x < a)
        {
            IO.WRITE("Yes");
            for (int i = 0; i < a; i++)
            {
                m.Add(i + 1);
            }
            m.Remove(x - 1);
            m.Remove(x);
            m.Remove(x + 1);
            for (int i = 0; i < a; i++)
            {
                if (i < N - 2)
                {
                    IO.WRITE(m[i]);
                }
                else if (i > N)
                {
                    IO.WRITE(m[i - 3]);
                }
                else
                {
                    IO.WRITE(x + i - (N - 2) - 1);
                }
            }
        }
        else
        {
            IO.WRITE("No");
        }
        IO.FLUSH();
    }
}

namespace LIB
{
    public class IO
    {
        private const int WMAX = 1000;
        private StringBuilder S = new StringBuilder();
        private T R<T>(Func<string, T> f) { return f(Console.ReadLine()); }
        private T[] R<T>(Func<string, T> f, char c) { return STRING().Split(c).Select(f).ToArray(); }
        private T[] R<T>(Func<string, T> f, int l) { T[] r = new T[l]; for (int i = 0; i < l; i++) { r[i] = R(f); } return r; }
        private T[][] R<T>(Func<string, T> f, int l, char c) { T[][] r = new T[l][]; for (int i = 0; i < l; i++) { r[i] = R<T>(f, c); } return r; }
        private void W<T>(Func<T, string> f, T v, bool lf = true) { S.Append(f(v)); if (lf == true) { S.Append('\n'); } if (S.Length >= WMAX) { FLUSH(); } }
        public string STRING() { return R(s => s); }
        public string[] STRING(char c) { return R(s => s, c); }
        public string[] STRING(int l) { return R(s => s, l); }
        public string[][] STRING(int l, char c) { return R(s => s, l, c); }
        public int INT() { return R(int.Parse); }
        public int[] INT(char c) { return R(int.Parse, c); }
        public int[] INT(int l) { return R(int.Parse, l); }
        public int[][] INT(int l, char c) { return R(int.Parse, l, c); }
        public long LONG() { return R(long.Parse); }
        public long[] LONG(char c) { return R(long.Parse, c); }
        public long[] LONG(int l) { return R(long.Parse, l); }
        public long[][] LONG(int l, char c) { return R(long.Parse, l, c); }
        public double DOUBLE() { return R(double.Parse); }
        public double[] DOUBLE(char c) { return R(double.Parse, c); }
        public double[] DOUBLE(int l) { return R(double.Parse, l); }
        public double[][] DOUBLE(int l, char c) { return R(double.Parse, l, c); }
        public void WRITE(string s, bool lf = true) { W(v => v, s, lf); }
        public void WRITE(int s, bool lf = true) { W(v => v.ToString(), s, lf); }
        public void WRITE(long s, bool lf = true) { W(v => v.ToString(), s, lf); }
        public void WRITE(double s, bool lf = true) { W(v => v.ToString(), s, lf); }
        public void FLUSH() { Console.Write(S); S.Length = 0; }
    }
}