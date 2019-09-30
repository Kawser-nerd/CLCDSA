using System;
using System.Linq;

public class Test {
  struct city{
  public int sector;
  public int year;
  public int index;
  public city(int s,int y,int i)
{
sector =s;
year =y;
index=i;
}
  }
  public static void Main () {
    int n, m; {
      var ins = Console.ReadLine ().Split (' ').Select (s => int.Parse (s)).ToArray ();
      n = ins[0];
      m = ins[1];
    } {
      var ins = new city[m];
      for (int i = 0; i < m; i++) {
        var ins2 = Console.ReadLine ().Split (' ').Select (s => int.Parse (s)).ToArray ();
        ins[i] = new city(ins2[0],ins2[1],i);
      }
{
int[] sectC = new int[n];
     Array.Sort(ins,(v,w)=>v.year-w.year);
var ins3 = ins.Select((v,i)=>new {index=v.index,str=v.sector.ToString("D6")+(++sectC[v.sector-1]).ToString("D6")}).ToArray();
Array.Sort(ins3,(v,w)=>v.index-w.index);
Array.ForEach(ins3,v=>
Console.WriteLine(v.str));
}
    }
  }
}