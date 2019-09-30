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
	            var parameters = Console.ReadLine().Split(' ').ToList();
	            var sourceCount = int.Parse(parameters[0]);
	            var requiredVolume = double.Parse(parameters[1]);
	            var requiredTemperature = double.Parse(parameters[2]);
	            var sources = new List<Source>(sourceCount);
	            foreach (var sourceIndex in Enumerable.Range(0, sourceCount))
	            {
		            var sourceParameters = Console.ReadLine().Split(' ').ToList();
					sources.Add(new Source
					{
						VolumePerSecond = double.Parse(sourceParameters[0]),
						Temperature = double.Parse(sourceParameters[1])
					});
	            }

				var hotSources = new Stack<Source>(sources.Where(source => source.Temperature > requiredTemperature).OrderBy(source => source.VolumePerSecond));
				var coldSources = new Stack<Source>(sources.Where(source => source.Temperature < requiredTemperature).OrderBy(source => source.VolumePerSecond));
				var exactSources = sources.Where(source => source.Temperature == requiredTemperature).ToList();

	            while (hotSources.Any() && coldSources.Any())
	            {
		            var hotSource = hotSources.Pop();
		            var coldSource = coldSources.Pop();

		            var heat = hotSource.VolumePerSecond * (hotSource.Temperature - requiredTemperature);
		            var cold = coldSource.VolumePerSecond * (requiredTemperature - coldSource.Temperature);
		            if (heat == cold)
		            {
			            exactSources.Add(new Source
			            {
				            Temperature = requiredTemperature,
							VolumePerSecond = hotSource.VolumePerSecond + coldSource.VolumePerSecond
			            });
		            }
					else if (heat < cold)
					{
						var usedColdVolumePerSecond = coldSource.VolumePerSecond * heat / cold;
						exactSources.Add(new Source
						{
							Temperature = requiredTemperature,
							VolumePerSecond = hotSource.VolumePerSecond + usedColdVolumePerSecond
						});
						coldSources.Push(new Source
						{
							Temperature = coldSource.Temperature,
							VolumePerSecond = coldSource.VolumePerSecond - usedColdVolumePerSecond
						});
					}
					else
					{
						var usedHotVolumePerSecond = hotSource.VolumePerSecond * cold / heat;
						exactSources.Add(new Source
						{
							Temperature = requiredTemperature,
							VolumePerSecond = coldSource.VolumePerSecond + usedHotVolumePerSecond
						});
						hotSources.Push(new Source
						{
							Temperature = hotSource.Temperature,
							VolumePerSecond = hotSource.VolumePerSecond - usedHotVolumePerSecond
						});
					}
				}

				var result = exactSources.Any() ? requiredVolume / exactSources.Sum(source => source.VolumePerSecond) : (double?)null;

				Console.WriteLine("Case #{0}: {1}", caseNumber, result?.ToString("0.00000000") ?? "IMPOSSIBLE");
            }
        }

	    struct Source
	    {
		    public double VolumePerSecond { get; set; }
			public double Temperature { get; set; }
	    }
    }
}
