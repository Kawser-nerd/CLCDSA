using System;
using System.Linq;//??????
using System.Collections.Generic;
public class Program
{
    public static void Main()
    {
      var answer = 0;
      string[] nums = Console.ReadLine().Split(' ');
      var n = int.Parse(nums[0]);
      var m = int.Parse(nums[1]);
      var p = int.Parse(nums[2]);
      var q = int.Parse(nums[3]);
      var r = int.Parse(nums[4]);
      var vertexes = new int[n,m];
      for (int i = 0; i < r; i++)
      {
        string[] numsSub = Console.ReadLine().Split(' ');
        vertexes[int.Parse(numsSub[0])-1, int.Parse(numsSub[1])-1] = int.Parse(numsSub[2]);
      }
      var combList = Enumerable.Range(0, n).Combination(p);//???????????
      foreach (var numbers in combList)
      {
        var combArray = numbers.ToArray();//0??n-1????????????
        var plusList = new List<int>();
        for (int i = 0; i < m; i++)
        {
          var plusMemo = 0;
          foreach (var x in combArray) plusMemo += vertexes[x, i];
          plusList.Add(plusMemo);
        }
        var mem = plusList.OrderByDescending(g => g).Take(q).Sum();//??????????
        answer = Math.Max(answer, mem);
      }
      Console.WriteLine(answer);
    }
}

public static class Comb//????k??????????????
{
  public static IEnumerable<IEnumerable<T>> Combination<T>(this IEnumerable<T> items, int k)
  {
    if (k == 0)
    {
      yield return Enumerable.Empty<T>();
    }
    else
    {
      var i = 1;
      foreach (var x in items)
      {
        var memo = items.Skip(i);
        foreach (var c in Combination(memo, k-1))
          yield return c.Before(x);
        i++;
      }
    }
  }
  public static IEnumerable<T> Before<T>(this IEnumerable<T> items, T first)
  {
    yield return first;
    foreach (var i in items)
      yield return i;
  }
}