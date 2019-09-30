using System;
 
namespace AtCoder
{
    class Program
    {
        static IO io = new IO();
 
        static void Main(string[] args)
        {
            //??
            io.Read();
            int n = io.Int();
            io.ReadSplit();
            int[] a = io.Int(n);
 
            //??
            long operations1 = EnumeratOperation(a, 1);
            long operations2 = EnumeratOperation(a, -1);
 
            //??
            io.WriteLine(Math.Min(operations1, operations2).ToString());
        }
        static long EnumeratOperation(int[] a, int sign)
        {
            long sum = 0;
            long operations = 0;
            for (int i = 0; i < a.Length; ++i)
            {
                sum += a[i];
                if (sum == 0)
                {
                    operations += 1;
                    sum -= sign;
                }
                else if (sum * sign > 0)
                {
                    long newoperation = -sum - sign;
                    operations += Math.Abs(newoperation);
                    sum += (newoperation);
                }
                sign *= -1;
            }
            return operations;
        }
    }
    class IO
    {
        private string[] _Inputs;
        private int _Index;
        public void Read()
        {
            _Inputs = new string[1];
            _Inputs[0] = Console.ReadLine();
            _Index = 0;
        }
        public void ReadSplit()
        {
            _Inputs = Console.ReadLine().Split(' ');
            _Index = 0;
        }
        public string String()
        {
            return _Inputs[_Index++];
        }
        public string[] String(int xCount)
        {
            string[] rv = new string[xCount];
            Array.Copy(_Inputs, _Index, rv, 0, xCount);
            _Index += xCount;
            return rv;
        }
        public int Int()
        {
            return int.Parse(_Inputs[_Index++]);
        }
        public int[] Int(int xCount)
        {
            int[] rv = new int[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = int.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public long Long()
        {
            return long.Parse(_Inputs[_Index++]);
        }
        public long[] Long(int xCount)
        {
            long[] rv = new long[xCount];
            for (int i = 0; i < xCount; ++i)
            {
                rv[i] = long.Parse(_Inputs[_Index++]);
            }
            return rv;
        }
        public void Write(string xStr)
        {
            Console.Write(xStr);
        }
        public void WriteLine(string xStr)
        {
            Console.WriteLine(xStr);
        }
    }
}