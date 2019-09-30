using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Program
{

    public void Proc()
    {
        int inputCount = int.Parse(Reader.ReadLine());
        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        PriorityList listZ = new PriorityList();
        PriorityList listK = new PriorityList();

        for (int i = 0; i < inputCount; i++) {
            listZ.Push(items[i]);
            listK.Push(items[inputCount * 3 - i - 1]*-1);
        }

        long[] zenhan = new long[inputCount * 3];

		zenhan[inputCount-1] = listZ.GetTotal();
        for (int i = inputCount; i < inputCount * 2;i++) {
            listZ.Push(items[i]);
            listZ.Pop();
            zenhan[i] = listZ.GetTotal();
        }
        long max = long.MinValue;
        max = zenhan[inputCount * 2 - 1] + listK.GetTotal();

		for (int i = inputCount * 2 - 1; i >= inputCount; i--) {
            listK.Push(items[i]*-1);
            listK.Pop();
            max = Math.Max(max, zenhan[i-1] + listK.GetTotal());
        }
        Console.WriteLine(max);

    }


    private class PriorityList {
        public long GetTotal() {
            return this.Total;
        }
        private long Total = 0;
        private SortedDictionary<int, int> Items = new SortedDictionary<int, int>();
        public void Push(int num) {
            if(this.Items.ContainsKey(num)) {
                Items[num]++;
            } else {
                Items.Add(num, 1);
            }
            Total += num;
		}
        public int Pop() {
            int key = Items.First().Key;
            int num = key;
            Items[key]--;
            if(Items[key]<=0) {
                Items.Remove(key);
            }
            Total -= num;
            return num;
        }


    }

    public class Reader
	{
		private static StringReader sr;
		public static bool IsDebug = false;
		public static string ReadLine()
		{
			if (IsDebug)
			{
				if (sr == null)
				{
					sr = new StringReader(InputText.Trim());
				}
				return sr.ReadLine();
			}
			else
			{
				return Console.ReadLine();
			}
		}
		private static string InputText = @"


3
8 2 2 7 4 6 5 3 8


";
	}

	public static void Main(string[] args)
	{
#if DEBUG
		Reader.IsDebug = true;
#endif
		Program prg = new Program();
		prg.Proc();
	}
}