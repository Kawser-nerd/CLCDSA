using System;
using System.Globalization;
using System.Linq;

namespace Beginnner011B
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputName = Console.ReadLine();

            var initialCharacter = char.ToUpper(inputName.First(), CultureInfo.CurrentCulture);
            var otherCharacters = inputName.Skip(1).Aggregate(string.Empty, (accum, elem) => accum + char.ToLower(elem, CultureInfo.CurrentCulture));

            var formattedName = string.Join("", initialCharacter, otherCharacters);
            Console.WriteLine(formattedName);
        }
    }
}