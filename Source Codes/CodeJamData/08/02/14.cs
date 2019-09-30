using System;
using System.Collections.Generic;

public class B
{
  struct Event : IComparable<Event>
  {
    public int when;
    public int where;
    public int op;
    
    public int CompareTo (Event ev)
    {
      if (this.when < ev.when)
        return -1;
      if (this.when > ev.when)
        return 1;
      
      return -this.op.CompareTo (ev.op);
    }
  }
  
  public static void Main ()
  {
    int n = int.Parse (Console.ReadLine ());
    
    for (int i = 1; i <= n; ++i)
    {
      int ta = int.Parse (Console.ReadLine ());
      string[] nab = Console.ReadLine ().Split (' ');
      int na = int.Parse (nab[0]);
      int nb = int.Parse (nab[1]);
      
      List<Event> events = new List<Event> ();
      
      for (int j = 0; j < na; ++j)
        AddEvent (events, 0, ParseTimes (Console.ReadLine ().Split (' '), ta));
      
      for (int j = 0; j < nb; ++j)
        AddEvent (events, 1, ParseTimes (Console.ReadLine ().Split (' '), ta));
      
      events.Sort ();
      
      int[] av = new int[2];
      int[] req = new int[2];
      
      foreach (Event ev in events)
      {
        av[ev.where] += ev.op;
        
        if (av[ev.where] < 0)
        {
          av[ev.where]++;
          req[ev.where]++;
        }
      }
      
      Console.WriteLine ("Case #{0}: {1} {2}", i, req[0], req[1]);
    }
  }
  
  
  static void AddEvent (List<Event> events, int where, int[] times)
  {
    events.Add (new Event { when = times[0], where = where, op = -1 });
    events.Add (new Event { when = times[1], where = 1 - where, op = 1 });
  }
  
  
  static int[] ParseTimes (string[] times, int ta)
  {
    int[] res = new int[2];
    
    for (int i = 0; i < 2; ++i)
    {
      res[i] += 600 * (int)(times[i][0] - '0');
      res[i] += 60 * (int)(times[i][1] - '0');
      res[i] += 10 * (int)(times[i][3] - '0');
      res[i] += (int)(times[i][4] - '0');
    }
    
    res[1] += ta;
    return res;
  }
}
