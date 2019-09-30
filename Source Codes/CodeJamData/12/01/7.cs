using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//Andrzeju! Nie dam się!

namespace tongues
{
    class Program
    {
        static void Main(string[] args)
        {
            var trainingInput = new string[]
            {
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
            };
            var trainingOutput = new string[]
            {
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up",
            };

            var mapping = new Dictionary<char, char>();
            for (var i = 0; i < trainingInput.Length; i++)
            {
                for (var j = 0; j < trainingInput[i].Length; j++)
                {
                    if (!mapping.ContainsKey(trainingInput[i][j]))
                        mapping.Add(trainingInput[i][j], trainingOutput[i][j]);
                }
            }

            mapping.Add('z', 'q');
            mapping.Add('q', 'z');

            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var input = inputStream.ReadLine();

                    var result = new string(input.Select(c => mapping[c]).ToArray());
                    outputStream.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }
    }
}
