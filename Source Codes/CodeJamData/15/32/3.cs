using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
	            var numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
	            var keyCount = numbers[0];
	            var wordLength = numbers[1];
	            var stringLength = numbers[2];
	            var keyboard = Console.ReadLine();
	            var word = Console.ReadLine();

				var keys = keyboard.GroupBy(key => key).ToDictionary(grouping => grouping.Key, grouping => grouping.Count());
	            var repeatLength = GetRepeatLength(word);
				var maxCount = (stringLength < wordLength) || (word.Any(key => !keys.ContainsKey(key))) ? 
					0 : 
					(stringLength - wordLength) / repeatLength + 1;

				var stateChanges = new List<List<State>>(wordLength);
	            for (var position = 0; position < wordLength; position++)
	            {
		            var positionStateChanges = new List<State>();
					stateChanges.Add(positionStateChanges);
		            var availableKeys = new HashSet<char>(keys.Keys);
			        for (var nextPosition = Math.Min(wordLength - 1, position + 1); nextPosition > 0; nextPosition--)
			        {
				        var key = word[nextPosition - 1];
				        if (availableKeys.Contains(key))
				        {
					        if (word.Substring(position - nextPosition + 1, nextPosition - 1) == word.Substring(0, nextPosition - 1))
					        {
						        positionStateChanges.Add(new State
						        {
							        Position = nextPosition,
									Probability = GetKeyProbability(key, keys, keyCount)
						        });
						        availableKeys.Remove(key);
					        }
				        }
			        }
		            if (availableKeys.Any())
		            {
			            positionStateChanges.Add(new State
				        {
					        Position = 0,
					        Probability = availableKeys.Sum(key => GetKeyProbability(key, keys, keyCount))
				        });
		            }
	            }

	            var states = new List<State>
	            {
		            new State
		            {
			            Position = 0,
						Probability = 1
		            }
	            };
	            var expectedGivenCount = 0.0;
	            foreach (var keyIndex in Enumerable.Range(0, stringLength))
	            {
		            expectedGivenCount +=
			            states.Where(state => state.Position == wordLength - 1).Sum(state => state.Probability) *
				            GetKeyProbability(word[wordLength - 1], keys, keyCount);
					states = states
						.SelectMany(state => stateChanges[state.Position]
							.Select(stateChange => new State
							{
								Position = stateChange.Position,
								Probability = state.Probability * stateChange.Probability
							}))
						.GroupBy(state => state.Position)
						.Select(grouping => new State
						{
							Position = grouping.Key,
							Probability = grouping.Sum(state => state.Probability)
						})
						.ToList();
                }
	            var expectedLeft = maxCount - expectedGivenCount;
				Console.WriteLine("Case #{0}: {1:0.0000000}", caseNumber, expectedLeft);
            }
        }

	    static int GetRepeatLength(string word)
	    {
		    for (var repeatLength = 1; repeatLength < word.Length; repeatLength++)
			    if (word.Substring(repeatLength) == word.Substring(0, word.Length - repeatLength))
				    return repeatLength;
		    return word.Length;
	    }

	    static double GetKeyProbability(char givenKey, Dictionary<char, int> keys, int keyCount)
	    {
		    int givenKeyCount;
		    if (keys.TryGetValue(givenKey, out givenKeyCount))
			    return givenKeyCount / (double)keyCount;
		    return 0;
	    }


	    struct State
	    {
		    public int Position { get; set; }
			public double Probability { get; set; }
	    }
    }
}
