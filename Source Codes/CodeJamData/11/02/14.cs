using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Magicka
{
    class Magicka
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                new Magicka().Solve();
            }
        }

        private void Solve()
        {            
            var input = new Queue<string>(Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));

            var merge = new char[128, 128];
            var clear = new bool[128, 128];
            
            var comb = int.Parse(input.Dequeue());
            for (int i = 0; i < comb; i++)
            {
                var s = input.Dequeue();
                merge[s[0], s[1]] = s[2];
                merge[s[1], s[0]] = s[2];
            }

            var d = int.Parse(input.Dequeue());
            for (int i = 0; i < d; i++)
            {
                var s = input.Dequeue();
                clear[s[0], s[1]] = true;
                clear[s[1], s[0]] = true;
            }

            var playN = input.Dequeue();
            var play = input.Dequeue();
            
            var list = new List<char>();
            var count = new int[128];

            for (int i = 0; i < play.Length; i++)
            {
                bool wasMerged = false;
                if (list.Count > 0)
                {
                    var m = merge[list[list.Count - 1], play[i]];
                    if (m != 0)
                    {
                        count[list[list.Count - 1]]--;
                        count[m]++;
                        list[list.Count - 1] = m;
                        wasMerged = true;
                    }
                }

                if (wasMerged)
                    continue;

                bool wasCleared = false;
                for (int j = 'A'; j <= 'Z'; j++)
                    if (count[j] > 0 && clear[play[i], j])
                    {
                        list.Clear();
                        Array.Clear(count, 0, 128);
                        wasCleared = true;
                        break;
                    }

                if (wasCleared)
                    continue;

                list.Add(play[i]);
                count[play[i]]++;
            }

            Console.WriteLine(string.Format("[{0}]", string.Join(", ", list)));
        }
    }
}
