using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ2010R2A {
    class Program {
        private int dim;
        private int[,] matrix;
        private void InputMatrix() {
            int[,] result = new int[dim, dim];
            for (int i = 0; i < 2 * dim - 1; ++i) {
                // Reading elements of diagonal i, should go into x+y=i
                int[] nums = Console.ReadLine().Trim().Split(' ').Select(p=>int.Parse(p)).ToArray();
                int startx = (i <= dim-1 ? 0 : i - dim + 1);
                int starty = (i >= dim - 1 ? 0 : dim - i - 1);
                for (int j = 0; j < nums.Length; ++j) {
                    result[startx + j, starty + j] = nums[j];
                }
            }
            /*
            Console.WriteLine("Begin");
            for (int i = 0; i < dim; ++i) {
                Console.WriteLine();
                for (int j = 0; j < dim; ++j)
                    Console.Write("{0} ", result[i, j]);
            }
            Console.WriteLine("End");*/
            matrix = result;
        }
        int get(int i, int j) {
            if (i < 0 || j < 0 || i >= dim || j >= dim) return -1;
            else return matrix[i, j];
        }
        int Symmetries(int k) {
            bool FwdSymm=true, BakSymm=true;
            for (int i = 0; i < dim; ++i)
            for (int j = 0; j < dim; ++j) {
                // Is it symmetric around x+y=k
                // (x,y) --> (k-y,k-x) under / reflection
                int ref1i = k - j, ref1j = k - i;
                // Is it symmetric around x-y=k
                // (x,y) --> (y+k,x-k) under \ reflection
                int ref2i = j + (k - (dim - 1)), ref2j = i - (k - (dim - 1));
                int fwdNum = get(ref1i, ref1j);
                int bakNum = get(ref2i, ref2j);
                if (fwdNum != -1 && fwdNum != matrix[i, j]) FwdSymm = false;
                if (bakNum != -1 && bakNum != matrix[i, j]) BakSymm = false;
            }
            return (FwdSymm ? 1 : 0) + (BakSymm ? 2 : 0);
        }
        int FindSymmetry() {
            int bestFwd = 2 * dim + 100, bestBak = 2 * dim + 100;
            for (int i = 0; i < 2 * dim; ++i) {
                int r = Symmetries(i);
                if ((r & 1) != 0) {
                    int k = i;
                    if (k < dim - 1) k = 2 * (dim - 1) - k;
                    if (bestFwd > k) bestFwd = k;
                }
                if ((r & 2) != 0) {
                    int k = i - (dim - 1);
                    if (k < 0) k = -k;
                    if (bestBak > k) bestBak = k;
                }
            }
            //Console.WriteLine("Symmetries at x+y={0}, x-y={1}", bestFwd, bestBak);
            int newLength = bestFwd + bestBak + 1;
            return newLength * newLength - dim * dim;
        }
        Program() {
            int ncases = int.Parse(Console.ReadLine());
            for (int i = 0; i < ncases; ++i) {
                dim = int.Parse(Console.ReadLine());
                InputMatrix();
                int ans = FindSymmetry();
                Console.WriteLine("Case #{0}: {1}", i + 1, ans);
            }
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
