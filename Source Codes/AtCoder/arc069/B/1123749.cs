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

            return string.Join("", animalPattern.Select(animals => {
                s.Skip(1).Aggregate(animals.First(), (ani, ans) =>
                {
                    var current = animals.Last();
                    animals.Add(isXor(current, ans) ? not(ani) : ani);
                    return current;
                });
                return animals;
            }).Where(animals => animals.First() == animals.Last())
            .Select(animals => animals.Take(n))
            .FirstOrDefault(animals => animals.ElementAt(1) == (isXor(animals.First(), s.First()) ? not(animals.Last()) : animals.Last())) ?? new List<char>() { '-', '1' }) ;
        }

        public static bool isXor(char animal, char ans) => animal == 'S' && ans == 'x' || animal == 'W' && ans == 'o';

        public static char not(char animal) => animal == 'S' ? 'W' : 'S';
    }
}