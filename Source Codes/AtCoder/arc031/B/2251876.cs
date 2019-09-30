using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace C_test_For_Atcorder
{
    public static class Extensions
    {
        public static string Reverse(this string sourse){
            char[] chrAry = sourse.ToCharArray();
            Array.Reverse(chrAry);
            return new string(chrAry);
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve(new ConsoleInput(Console.In, ' '));
        }

        private static char[,] map;
        private static char[,] map2;
        public void Solve(ConsoleInput cin)
        {
            map = new char[10, 10];
            map2 = new char[10, 10];
            for (int i = 0; i < 10; i++)
            {
                var str = cin.Read;
                for (int j = 0; j < 10; j++)
                {
                    map[j, i] = str[j];
                }
            }

            for (int i = 0; i < 10;i++){
                for (int j = 0; j < 10;j++){
                    if(map[j,i]=='x')
                    {
                        for (int p = 0; p < 10;p++){
                            for (int q = 0; q < 10;q++){
                                map2[p, q] = map[p, q];
                            }
                        }
						
						map2[j, i] = 'o';
						Search(j, i);
						int counto = 0;
                        for (int t = 0; t < 10;t++){
                            for (int q = 0; q < 10;q++){
								if (map2[q,t] == 'o')
								{
									counto++;

								}   

                            }
                             
                        }



						if (counto == 0)
						{
							Console.WriteLine("YES");
							return;
						}
                    }
                }
            }    
            Console.WriteLine("NO");
            return;

        }

        public void Search(int x, int y)
        {
            if (x < 0 || 10 <= x || y < 0 || 10 <= y || map2[x, y] == 'x')
            {
                return;
            }
            map2[x, y] = 'x';


            Search(x + 1, y);
            Search(x , y+1);
            Search(x -1, y);
            Search(x , y-1);

            return;
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private char _separator = ' ';
        private Queue inputStream;

        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            this._separator = separator;
            this._stream = stream;
            inputStream = new Queue();
        }
        public string Read
        {
            get
            {
                if (inputStream.Count != 0) return (string)inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(_separator);
                for (int i = 0; i < tmp.Length; ++i)
                    inputStream.Enqueue(tmp[i]);
                return (string)inputStream.Dequeue();
            }
        }
        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
    }

}