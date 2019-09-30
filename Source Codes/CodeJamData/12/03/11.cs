using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class C : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int prev = NextInt();
            int last = NextInt();
            int sum = 0;
            for (int i = prev; i < last; i++)
            {
                sum += allHigherRecycles(i, last);
            }
            return sum;
        }

        HashSet<int> tempSet;

        void allHigherRecycles(int number)
        {
            int td;
            int n = ileCyfr(number, out td);
            int d = 1;
            for (int i = 1; i < n; i++) 
            {
                d *= 10;
                td/=10;
                int m = number % d * td + number / d;
                tempSet.Add(m);
            }
        }

        int ileCyfr(int n, out int d)
        {
            int x = 0;
            d = 1;
            while (n > 0) { n /= 10; x++; d *= 10; }
            return x;
        }

        int allHigherRecycles(int number, int maxNumber)
        {
            tempSet = new HashSet<int>();
            allHigherRecycles(number);
            return tempSet.Count((x) => x > number && x<=maxNumber);
        }
    }
}
