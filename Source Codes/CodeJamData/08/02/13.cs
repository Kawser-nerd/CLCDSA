using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Trains
{
  class Program
  {
    static void Main(string[] args)
    {
      String prefix = "B-large";
      FileStream read = File.OpenRead(prefix+".in");
      StreamReader sr = new StreamReader(read);
      FileStream write = File.OpenWrite(prefix+".out");
      StreamWriter wr = new StreamWriter(write);
      int numCases = int.Parse(sr.ReadLine());
      for(int i=1;i<=numCases;i++){
        HandleCase(i, sr, wr);
      }
      wr.Flush();
      wr.Close();
    }

    public static void HandleCase(int index, StreamReader input, StreamWriter output)
    {
      string line1 = input.ReadLine();
      int t = int.Parse(line1);
      string[] split = input.ReadLine().Split(' ');
      int na = int.Parse(split[0]);
      int nb = int.Parse(split[1]);
      List<string> atimes = new List<string>();
      for(int i=0;i<na;i++)
      {
        string line = input.ReadLine();
        atimes.Add(line);
      }
      List<string> btimes = new List<string>();
      for (int i = 0; i < nb; i++)
      {
        string line = input.ReadLine();
        btimes.Add(line);
      }
      string res = HandleCase(t, atimes.ToArray(), btimes.ToArray());
      output.WriteLine("Case #{0}: {1}", index, res);
    }

    public class TrainEvent
    {
      public TrainEvent(DateTime time, string what)
      {
        this.time = time;
        this.what = what;
      }

      public DateTime time;
      public string what;
    }

    public static string HandleCase(int t, string[] atimes, string[] btimes)
    {
      Console.WriteLine("------------");
      List<TrainEvent> events = new List<TrainEvent>();
      foreach(string line in atimes)
      {
        string[] split = line.Split(' ');
        DateTime depart = DateTime.Parse(split[0]);
        DateTime arrive = DateTime.Parse(split[1]);
        DateTime ready = arrive + TimeSpan.FromMinutes(t);
        events.Add(new TrainEvent(depart, "depart a"));
        events.Add(new TrainEvent(ready, "ready b"));
      }
      foreach (string line in btimes)
      {
        string[] split = line.Split(' ');
        DateTime depart = DateTime.Parse(split[0]);
        DateTime arrive = DateTime.Parse(split[1]);
        DateTime ready = arrive + TimeSpan.FromMinutes(t);
        events.Add(new TrainEvent(depart, "depart b"));
        events.Add(new TrainEvent(ready, "ready a"));
      }
      events.Sort(delegate(TrainEvent a, TrainEvent b)
                    {
                      int timecompare = DateTime.Compare(a.time, b.time);
                      if(timecompare!=0)
                        return timecompare;
                      if (a == b)
                        return 0;
                      if (a.what == "ready a")
                        return -1;
                      if (b.what == "ready a")
                        return 1;
                      if (a.what == "ready b")
                        return -1;
                      if (b.what == "ready b")
                        return 1;
                      if (a.what == "depart a")
                        return -1;
                      if (b.what == "depart a")
                        return 1;
                      if (a.what == "depart b")
                        return -1;
                      if (b.what == "depart b")
                        return 1;
                      return 0;
                    });
      int ata = 0;
      int atb = 0;
      int defa = 0;
      int defb = 0;
      foreach (TrainEvent e in events)
      {
        Console.WriteLine("{0} {1}", e.time, e.what);
        if(e.what=="depart a")
        {
          ata--;
          if (ata < defa)
            defa = ata;
        }
        else if (e.what == "depart b")
        {
          atb--;
          if (atb < defb)
            defb = atb;
        }
        else if (e.what == "ready a")
        {
          ata++;
        }
        else if (e.what == "ready b")
        {
          atb++;
        }
        Console.WriteLine("{0} {1} {2} {3}", ata, atb, defa, defb);
      }

      string res = (-defa)+" "+(-defb);
      Console.WriteLine(res);
      return res;
    }
  }
}
