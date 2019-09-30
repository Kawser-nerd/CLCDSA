using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoderRegularContest069
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(program1(new String[] { Console.ReadLine(), Console.ReadLine() }));
        }

        public static string program1(string[] args)
        {
            var n = int.Parse(args[0]);
            var s = args[1].ToCharArray();

            var animalPattern = new List<char>[] { new List<char>() { 'S', 'S' }, new List<char> { 'S', 'W' }, new List<char> { 'W', 'W' }, new List<char> { 'W', 'S' } };

            return string.Join("", animalPattern.Select(animals =>
            s.Skip(1).Aggregate(animals, (ani, ans) =>
            {
                if (ani.Last() == 'S' && ans == 'x' || ani.Last() == 'W' && ans == 'o')
                {
                    ani.Add(ani.ElementAt(ani.Count() - 2) == 'S' ? 'W' : 'S');
                }
                else
                {
                    ani.Add(ani.ElementAt(ani.Count() - 2));
                }
                return ani;
            }))
            .Where(animals => animals.First() == animals.Last())
            .Select(animals => animals.Take(n))
            .FirstOrDefault(animals => {
                if (s.First() == 'o' && animals.First() == 'S' || s.First() == 'x' && animals.First() == 'W')
                {
                    return animals.ElementAt(1) == animals.Last();
                }
                else
                {
                    return animals.ElementAt(1) != animals.Last();
                }
            }) ?? new List<char>() { '-', '1' }) ;
        }
    }
}