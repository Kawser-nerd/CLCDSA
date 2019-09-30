using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Universe
{
  class Program
  {
    static void Main(string[] args)
    {
      String prefix = "A-large";
      FileStream read = File.OpenRead(prefix + ".in");
      StreamReader sr = new StreamReader(read);
      FileStream write = File.OpenWrite(prefix + ".out");
      StreamWriter wr = new StreamWriter(write);
      int numCases = int.Parse(sr.ReadLine());
      for (int i = 1; i <= numCases; i++)
      {
        HandleCase(i, sr, wr);
      }
      wr.Flush();
      wr.Close();
    }

    public static void HandleCase(int index, StreamReader input, StreamWriter output)
    {
      int S = int.Parse(input.ReadLine());
      List<string> engines = new List<string>();
      for (int i = 0; i < S; i++)
      {
        engines.Add(input.ReadLine());
      }
      int Q = int.Parse(input.ReadLine());
      List<string> queries = new List<string>();
      for (int i = 0; i < Q; i++)
      {
        queries.Add(input.ReadLine());
      }

      int res = HandleCase(engines.ToArray(), queries.ToArray());
      output.WriteLine("Case #{0}: {1}", index, res);
    }

    public static int HandleCase(string[] engines, string[] queries)
    {
      // greedy
      int res = 0;
      int done = 0;
      while (done < queries.Length)
      {
        int stretch = LongestStretch(queries, done, engines.Length - 1);
        done += stretch;
        res++;
      }
      if (res == 0)
        return 0;
      return res-1;
    }

    public static int LongestStretch(string[] queries, int start, int numEngines)
    {
      Dictionary<string, bool> used = new Dictionary<string, bool>();
      int counter = 0;
      while(start+counter<queries.Length)
      {
        string query = queries[start+counter];
        if(used.ContainsKey(query))
        {
          //ok
          counter++;
          continue;
        }else
        {
          if(used.Count<numEngines)
          {
            used.Add(query, true);
            counter++;
            continue;
          }else
          {
            return counter;
          }
        }
      }
      return counter;
    }
  }
}
