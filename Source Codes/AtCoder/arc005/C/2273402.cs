using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using static System.Math;
using static System.Console;
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
        static void Main() => new J();
    }
	class J
	{
		int F() => int.Parse(ReadLine());

		long FL() => int.Parse(ReadLine());
		int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
		long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
		public const int MOD = 1000000007;
        public J()
		{
            SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
			Solve();
			Out.Flush();
		}


		private void Solve()
		{
            var I = G();
			int H = I[0];
            int W = I[1];
            int sy = 0;
            int sx = 0;
            int gy = 0;
            int gx = 0;


			var map = new bool[H,W];
			var d = new int[H, W];//????????????

			for (int y = 0; y < H; y++)
			{
                var L = ReadLine();
                for (int x = 0; x < W; x++)
                {
                    if(L[x]=='s'){
                        sy = y;
                        sx = x;
                    }else if(L[x]=='g'){
                        gy = y;
                        gx = x;
                    }
                    d[y, x] = 3;
                    map[y,x] = L[x] != '#';

                }
			}
            d[sy, sx] = 0;

			var dx = new [] { 1,0, -1, 0, 1 };

			//bfs
            var que = new Deque<Tuple<int, int>>();
            que.PushFront(new Tuple<int, int>(sy, sx));
			d[sy, sx] = 0;//??????

			while (que.Count > 0)
			{
                Tuple<int, int> p = que.PopFront();
                //?????????
                for (int i = 0; i < 4; i++)
                {
                    int ny = p.Item1 + dx[i], nx = p.Item2 + dx[i + 1];
                    //????
                    if ((uint)nx >= (uint)W || (uint)ny >= (uint)H) continue;
                    int cost = map[ny, nx] ? 0 : 1,tmp = d[p.Item1, p.Item2] + cost;
                    if (d[ny, nx] > tmp)
                    {
                        d[ny, nx] = tmp;
                        if (cost == 1) que.PushBack(new Tuple<int, int>(ny, nx));
                        else que.PushFront(new Tuple<int, int>(ny, nx));
                    }         
				}
            }

            Console.WriteLine(d[gy,gx]<=2?"YES":"NO");
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

	class Deque<T>
	{
		T[] array;
		int offset, capacity;
		public int Count { get; protected set; }
		public Deque(int capacity) { array = new T[this.capacity = capacity]; Count = 0; offset = 0; }
		public Deque() : this(16) { }
		public T this[int index] { get { return array[GetIndex(index)]; } set { array[GetIndex(index)] = value; } }
		int GetIndex(int index) { var tmp = index + offset; return tmp >= capacity ? tmp - capacity : tmp; }
		public T PeekFront() => array[offset];
		public T PeekBack() => array[GetIndex(Count - 1)];
		public void PushFront(T item)
		{
			if (Count == capacity) Extend();
			if (--offset < 0) offset += array.Length;
			array[offset] = item;
			Count++;
		}
		public T PopFront()
		{
			Count--;
			var tmp = array[offset++];
			if (offset >= capacity) offset -= capacity;
			return tmp;
		}
		public void PushBack(T item)
		{
			if (Count == capacity) Extend();
			var id = (Count++) + offset;
			if (id >= capacity) id -= capacity;
			array[id] = item;
		}
		public T PopBack() => array[GetIndex(--Count)];
		public void Insert(int index, T item)
		{
			PushFront(item);
			for (var i = 0; i < index; i++) this[i] = this[i + 1];
			this[index] = item;
		}
		public T RemoveAt(int index)
		{
			var tmp = this[index];
			for (var i = index; i > 0; i--) this[i] = this[i - 1];
			PopFront();
			return tmp;
		}
		void Extend()
		{
			var newArray = new T[capacity << 1];
			if (offset > capacity - Count)
			{
				var length = array.Length - offset;
				Array.Copy(array, offset, newArray, 0, length);
				Array.Copy(array, 0, newArray, length, Count - length);
			}
			else Array.Copy(array, offset, newArray, 0, Count);
			array = newArray;
			offset = 0;
			capacity <<= 1;
		}
	}

}