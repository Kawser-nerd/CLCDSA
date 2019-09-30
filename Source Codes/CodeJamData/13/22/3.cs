using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class B : AbstractSolver
    {

        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            int x = Math.Abs(NextInt());
            int y = NextInt();

            int layer = (x + y) / 2;

            int layerSize;
            int cl = currentLayer(n, out layerSize);

            int itemsInALayer = n - layerSize;
            if (layer <= cl) return 1;
            if (layer > cl + 1) return 0;

            int max = layer * 2 + 1;

            double[,] cases = new double[max, max];

            cases[0, 0] = 1;


            for (int i = 0; i < itemsInALayer; i++)
            {
                for (int k = 0; k <= i; k++)
                {
                    if (k < max && i - k < max)
                    {

                        if (k == max - 1)
                        {
                            cases[k, i - k + 1] += cases[k, i - k];
                        }
                        else if (i - k == max - 1)
                        {
                            cases[k + 1, i - k] += cases[k, i - k];
                        }
                        else
                        {
                            cases[k + 1, i - k] += 0.5 * cases[k, i - k];
                            cases[k, i - k + 1] += 0.5 * cases[k, i - k];
                        }
                    }
                }
            }

            double sum = 0;
            for (int i = y + 1; i < max; i++)
            {
                
                if (itemsInALayer - i < max && itemsInALayer - i >= 0)
                {
                    sum += cases[i, itemsInALayer - i];
                }
            }
            return sum;

        }

        int currentLayer(int n, out int layerSize)
        {
            int layerId = 0;
            int currentLayer = 1;
            int items = 1;

            while (n >= items + currentLayer + 4)
            {
                layerId++;
                currentLayer += 4;
                items += currentLayer;
            }
            layerSize = items;
            return layerId;
        }
    }
}
