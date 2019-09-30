using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace d
{
	class Chest
	{
		public int id;
		public int type;
		public List<int> keys;
		public bool open = false;

		public Chest(int idx, string[] linea)
		{
			id = idx;
			type = int.Parse(linea[0]);
			int k = int.Parse(linea[1]);
			keys = new List<int>();
			for (int i = 0; i < k; i++)
			{
				keys.Add(int.Parse(linea[i + 2]));
			}
		}

		public void Open(Keys currentKeys, List<int> order)
		{
			open = true;
			currentKeys.Remove(type);
			order.Add(id);
			foreach (int k in keys)
			{
				currentKeys.Add(k);
			}
		}

		public void Close(Keys currentKeys, List<int> order)
		{
			open = false;
			currentKeys.Add(type);
			order.Remove(id);
			foreach (int k in keys)
			{
				currentKeys.Remove(k);
			}
		}

		public string ToString()
		{
			return string.Format("{0}{1} ({2}): {3}", open ? "*" : "", id, type, string.Join(", ", keys));
		}
	}

	class Keys
	{
		Dictionary<int, int> keys;
		public Keys(string[] linea)
		{
			keys = new Dictionary<int, int>();
			foreach (string s in linea)
			{
				Add(int.Parse(s));
			}
		}

		public void Add(int k)
		{
			if (!keys.ContainsKey(k))
			{
				keys.Add(k, 0);
			}
			keys[k]++;
		}

		public void Remove(int k)
		{
			if (!keys.ContainsKey(k))
			{
				keys.Add(k, 0);
			}
			keys[k]--;
		}

		public bool Has(int k)
		{
			return keys.ContainsKey(k) && keys[k] > 0;
		}

		public bool Impossible()
		{
			return keys.Any(kvp => kvp.Value < 0);
		}

		public string ToString()
		{
			return string.Join(", ", keys.Select(kvp => string.Format("{0}: {1}", kvp.Key, kvp.Value)).ToArray());
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] linea = Console.ReadLine().Split(' ');
				int K = int.Parse(linea[0]);
				int N = int.Parse(linea[1]);

				Keys keys = new Keys(Console.ReadLine().Split(' '));

				List<Chest> chests = new List<Chest>();
				for (int i = 0; i < N; i++)
				{
					chests.Add(new Chest(i + 1, Console.ReadLine().Split(' ')));
				}
				List<int> order = new List<int>();

				foreach (Chest c in chests) c.Open(keys, order);
				bool ok = !keys.Impossible();
				foreach (Chest c in chests) c.Close(keys, order);

				Console.WriteLine("Case #{0}: {1}", caso, ok && solve(chests, keys, order, new List<string>()) ? string.Join(" ", order.ToArray()) : "IMPOSSIBLE");
			}
		}

		static bool solve(List<Chest> chests, Keys keys, List<int> order, List<string> fails)
		{
			var openable = chests.Where(c => !c.open && keys.Has(c.type)).ToList();
			foreach (Chest chest in openable)
			{
				chest.Open(keys, order);
				string open = string.Join(",", chests.Where(c => c.open).Select(c => c.id));
				if (fails.IndexOf(open) < 0)
				{
					if (keys.Has(chest.type) || !chests.Any(c => !c.open && c.type == chest.type) ||
						chests.Any(c => !c.open && c.keys.IndexOf(chest.type) > -1 && keys.Has(c.type)))
					{
						if (solve(chests, keys, order, fails))
						{
							return true;
						}
					}
					fails.Add(open);
				}
				chest.Close(keys, order);
			}

			return chests.All(c => c.open);
		}
	}
}
