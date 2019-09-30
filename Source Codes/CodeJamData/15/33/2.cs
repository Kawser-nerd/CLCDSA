using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemC
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
	            var maxRepeatCount = numbers[0];
	            var oldDenominationCount = numbers[1];
	            var maxPossiblePayment = numbers[2];
	            var oldDenominations = Console.ReadLine().Split(' ').Select(int.Parse).ToList();

				var arePaymentsPossible = new BitArray(maxPossiblePayment + 1);
	            arePaymentsPossible[0] = true;
	            foreach (var denomination in oldDenominations)
		            AddDenomination(arePaymentsPossible, denomination, maxRepeatCount);
	            var newDenominationCount = 0;
	            for (var payment = 1; payment <= maxPossiblePayment; payment++)
	            {
		            if (!arePaymentsPossible[payment])
		            {
			            AddDenomination(arePaymentsPossible, payment, maxRepeatCount);
			            newDenominationCount++;
		            }
	            }
				Console.WriteLine("Case #{0}: {1}", caseNumber, newDenominationCount);
            }
        }

	    static void AddDenomination(BitArray arePaymentsPossible, int denomination, int maxRepeatCount)
	    {
		    for (
					int amount = denomination, repeatIndex = 0; 
					(amount < arePaymentsPossible.Count) && (repeatIndex < maxRepeatCount); 
					amount += denomination, repeatIndex++)
				for (var oldAmount = arePaymentsPossible.Count - 1; oldAmount >= 0; oldAmount--)
					if (arePaymentsPossible[oldAmount] && (oldAmount + amount < arePaymentsPossible.Count))
						arePaymentsPossible[oldAmount + amount] = true;
	    }
    }
}
