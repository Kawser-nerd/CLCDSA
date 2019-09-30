using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        bool ans = IsValid();
        Console.WriteLine(ans?"Yes":"No");
    }

    private bool IsValid() {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        this.PersonCount = inpt[0];
        int hintCount = inpt[1];
        this.PersonPos = new Nullable<long>[this.PersonCount];

        for (int i = 0; i < hintCount; i++)
        {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            int[] person = inpt.Take(2).Select(a => a - 1).ToArray();
            person.ToList().ForEach(a => {
                if (!Road.ContainsKey(a))
                {
                    Road.Add(a, new Dictionary<int, long>());
                }
            });
            if (Road[person[0]].ContainsKey(person[1]))
            {
                if(Road[person[0]][person[1]] != inpt[2]) {
                    return false;
                }
            } else {
                Road[person[0]][person[1]] = inpt[2];
            }
            if (Road[person[1]].ContainsKey(person[0]))
            {
                if (Road[person[1]][person[0]] != inpt[2]*-1)
                {
                    return false;
                }
            } else {
                Road[person[1]][person[0]] = inpt[2] * -1;
            }
        }
        Stack<int> q = new Stack<int>();
        for (int i = PersonCount-1; i>=0; i--) {
            if(Road.ContainsKey(i)) {
                q.Push(i);
            }            
        }
        if(q.Count==0) {
            return true;
        }
        PersonPos[q.Peek()] = 0;
        while(q.Count>0) {
            int current = q.Pop();
            if(PersonPos[current] == null) {
                PersonPos[current] = 0;
            }
            foreach(int next in Road[current].Keys) {
                if(PersonPos[next]==null) {
                    PersonPos[next] = PersonPos[current].Value + this.Road[current][next];
                    q.Push(next);
                    continue;
                }
                if(PersonPos[next].Value-PersonPos[current].Value != this.Road[current][next]) {
                    return false;
                }
            }
        }
        return true;
    }

    private Nullable<long>[] PersonPos;
    private Dictionary<int, Dictionary<int, long>> Road = new Dictionary<int, Dictionary<int, long>>();
    private int PersonCount;

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


10 3
1 2 0
3 2 0
4 5 6

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