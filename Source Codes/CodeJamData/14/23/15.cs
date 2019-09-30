using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ141BQ3
{
  using System.IO;

  class City
  {
    public String Zip;

    public bool Visited;

    public SortedDictionary<String, City> Neighbours = new SortedDictionary<string, City>();
  }


  class Program
  {
    static string Visit(List<City> soFar, List<City> route, City current, List<City> cities)
    {
      if (current.Visited) return null;

      current.Visited = true;
      soFar.Add(current);

      if (cities.All(c => c.Visited))
      {
        return String.Join("", soFar.Select(c => c.Zip.ToString()));
      }

      route.Add(current);

      var options = new SortedDictionary<String, List<int>>();
      for (int r = route.Count - 1; r >= 0; --r)
      {
        var n = route[r].Neighbours.Select(v => v.Value).Where(v => !v.Visited).ToList();
        foreach (City c in n)
        {
          string zip = c.Zip;
          List<int> l;
          if (options.ContainsKey(zip))
          {
            l = options[zip];
          }
          else
          {
            l = new List<int>();
            options.Add(zip, l);
          }
          l.Add(r);
        }
      }

      foreach (var nextO in options)
      {
        var next = cities.First(c => c.Zip == nextO.Key);
        foreach (int r in nextO.Value)
        {
          var routeHere = route.Take(r + 1).ToList();
          string result = Visit(soFar, routeHere, next, cities);
          if (result != null) return result;
        }
      }

      soFar.RemoveAt(soFar.Count - 1);
      current.Visited = false;
      return null;
    }

    static void Main(string[] args)
    {
      //args = new string[] {"..\\..\\C-small-attempt0.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          var l1 = sr.ReadLine().Split(' ').Select(ii => int.Parse(ii)).ToList();
          int nCities = l1[0];
          int nFlights = l1[1];

          var cities = new List<City>();
          for (int nCity = 0; nCity < nCities; ++nCity)
          {
            cities.Add(new City() { Zip = sr.ReadLine()});
          }
          for (int f = 0; f < nFlights; ++f)
          {
            var l2 = sr.ReadLine().Split(' ').Select(i => int.Parse(i)).ToList();
            int city0 = l2[0] - 1;
            int city1 = l2[1] - 1;
            var c0 = cities[city0];
            var c1 = cities[city1];
            c0.Neighbours.Add(c1.Zip,c1);
            c1.Neighbours.Add(c0.Zip,c0);
          }

          var sortedCities = new SortedDictionary<string, City>();
          foreach (var city in cities)
          {
            city.Visited = false;
            sortedCities.Add(city.Zip, city);
          }

          string result = "failed!";
          foreach (var startCity in sortedCities)
          {
            result = Visit(new List<City>(), new List<City>(), startCity.Value, cities);
            if (result != null) break;
          }
          
          Console.WriteLine("Case #{0}: {1}", nCase, result);
        }
      }
    }
  }
}
