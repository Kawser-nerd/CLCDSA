using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace BotTrust
{
    class BotTrust
    {
        static void Main(string[] args)
        {
            new BotTrust().Run();
        }

        private void Run()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                Solve();
            }
        }

        class Push
        {
            public int Index;
            public int Button;
        }

        private void Solve()
        {
            var p = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var n = int.Parse(p[0]);

            var pushes = new Queue<Push>[] { new Queue<Push>(), new Queue<Push>() };
            for (int i = 0; i < n; i++)
                pushes[p[i * 2 + 1] == "O" ? 0 : 1].Enqueue(new Push { Index = i, Button = int.Parse(p[i * 2 + 2]) });

            var pos = new int[] { 1, 1 };
            int index = 0, t = 0;
            while (index < n)
            {
                t++;
                bool hasPushed = false;
                for (int r = 0; r < 2; r++)
                {
                    var a = pushes[r].Count > 0 ? pushes[r].Peek() : null;
                    if (a != null)
                    {
                        if (a.Index == index && a.Button == pos[r] && !hasPushed)
                        {
                            index++;
                            hasPushed = true;
                            pushes[r].Dequeue();
                        }
                        else if (pos[r] < a.Button)
                            pos[r]++;
                        else if (pos[r] > a.Button)
                            pos[r]--;
                    }
                }
            }

            Console.WriteLine(t);
        }
    }
}
