using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC022
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			new MainClass().solve();
		}
		Scanner cin;

		int N,M;
        int[] u, v, l;
		void solve()
		{
			cin = new Scanner();
            WarshallFloyd wf = new WarshallFloyd();
			N = cin.nextInt();
            M = cin.nextInt();

            u = new int[M];
            v = new int[M];
            l = new int[M];
            for (int i = 0; i < M;i++){
                u[i] = cin.nextInt();
                v[i] = cin.nextInt();
                l[i] = cin.nextInt();
                u[i]--;
                v[i]--;
            }

            int[,] t = wf.Init(N);
            for (int i = 0; i < M;i++){
                if (u[i] == 0 || v[i] == 0)
                    continue;
                t[u[i], v[i]] = t[v[i], u[i]] = l[i];
            }
            t = wf.Run(t);

            //???????????
            for (int i = 0; i < M; i++)
                if (u[i] == 0 )
                    t[0, v[i]] = t[v[i], 0] = l[i];
                else if (v[i] == 0)
                    t[0, u[i]] = t[u[i], 0] = l[i];
            
			int ans = (int)(1e8);
            for (int i = 0; i < N;i++){
                for (int j = 0; j < N;j++){
                    if (i == 0||j==0||i==j)
                        continue;
                    ans = Math.Min(ans, t[0, i] + t[i, j] + t[j, 0]);
                }
            }

            Console.WriteLine(ans==(int)(1e8)?-1:ans);
		}
	}

	class Scanner
	{
		string[] nextBuffer;
		int BufferCnt;
		char[] cs = new char[] { ' ' };
		public Scanner()
		{
			nextBuffer = new string[0];
			BufferCnt = 0;
		}
		public string next()
		{
			if (BufferCnt < nextBuffer.Length)
				return nextBuffer[BufferCnt++];
			string st = Console.ReadLine();
			while (st == "")
				st = Console.ReadLine();
			nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			BufferCnt = 0;
			return nextBuffer[BufferCnt++];
		}
		public int nextInt()
		{
			return int.Parse(next());
		}
		public long nextLong()
		{
			return long.Parse(next());
		}
		public double nextDouble()
		{
			return double.Parse(next());
		}
	}
	class WarshallFloyd
	{
        //???
		int INF;
		public WarshallFloyd()
		{
			INF = (int)(1e8);
		}
		public WarshallFloyd(int INF)
		{
			this.INF = INF;
		}
		/// <summary>
		/// ??????????O(????^3)
		/// </summary>
		/// <param name="m">????????INF???????????</param>
		/// <returns></returns>
		public int[,] Run(int[,] m)
		{
			int edgeLength = m.GetLength(0);
			for (int i = 0; i < edgeLength; i++)
				for (int j = 0; j < edgeLength; j++)
					for (int k = 0; k < edgeLength; k++)
						m[j, k] = Math.Min(m[j, k], m[j, i] + m[i, k]);
			return m;
		}
		/// <summary>
		/// ????????????INF??????0????????????
		/// </summary>
		/// <param name="n">????</param>
		/// <returns></returns>
		public int[,] Init(int n)
		{
			int[,] m = new int[n, n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					m[i, j] = INF;
			for (int i = 0; i < n; i++)
				m[i, i] = 0;
			return m;
        }
		public bool isNegative(int[,] m)
		{
			for (int i = 0; i < m.GetLength(0); i++)
				if (m[i, i] < 0)
					return true;    //???
			return false;           //???
		}
	}
	class AssociativeArray
	{
		Dictionary<int, int> iDic=null;
		Dictionary<char, int> cDic=null;
        Dictionary<string, int> sDic=null;
		public void CountInit(int[] arr)
		{
			iDic = new Dictionary<int, int>();
			for (int i = 0; i < arr.Length; i++)
			{
				if (!iDic.ContainsKey(arr[i])) iDic[arr[i]] = 0;
				iDic[arr[i]]++;
			}
		}
		public void CountInit(string[] arr)
		{
			iDic = new Dictionary<int, int>();
			for (int i = 0; i < arr.Length; i++)
			{
				if (!sDic.ContainsKey(arr[i])) sDic[arr[i]] = 0;
				sDic[arr[i]]++;
			}
		}
		public void CountInit(char[] arr)
		{
			iDic = new Dictionary<int, int>();
			for (int i = 0; i < arr.Length; i++)
			{
				if (!cDic.ContainsKey(arr[i])) cDic[arr[i]] = 0;
				cDic[arr[i]]++;
			}
		}
		public int CountValueSum()
		{
			int sum = 0;
			if (iDic != null)
				foreach (KeyValuePair<int, int> item in iDic)
					sum += item.Value;
			else if (sDic != null)
				foreach (KeyValuePair<string, int> item in sDic)
					sum += item.Value;
			else if (cDic != null)
				foreach (KeyValuePair<char, int> item in cDic)
					sum += item.Value;
			return sum;
		}
		public int CountKeyNum()
		{
			if (iDic != null)
				return iDic.Count;
			else if (sDic != null)
				return sDic.Count;
			else if (cDic != null)
				return cDic.Count;
			return -1;
		}
	}
	static class StringEx
	{
		/// <summary>
		/// ????????????
		/// </summary>
		/// <param name="s"></param>
		/// <returns></returns>
		public static string Reversed(this string s)
		{
			return string.Join("", s.Reverse());
		}
	}
}