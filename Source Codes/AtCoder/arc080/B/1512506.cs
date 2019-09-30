using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC080
{
    class GridColoring
    {
        public static void Main()
        {
            var hw = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_));
            var n = int.Parse(ReadLine());
            var stack = new Stack<int>();
            foreach(var a in ReadLine().Trim().Split(' ').Select(_ => int.Parse(_))) {
                stack.Push(a);
            }
            while(stack.Count() != 0) {
                WriteLine(BuildStringForward(ref stack, hw.Last()));
                if (stack.Count() != 0) WriteLine(BuildStringBackward(ref stack, hw.Last()));
            }
        }
        static string BuildStringForward(ref Stack<int> stack, int width)
        {
            var arr = new int[width];
            var len = 0;
            for (var idx = 0; idx < width; ++idx) {
                if (len == 0) len = stack.Pop();
                arr[idx] = stack.Count() + 1;
                --len;
            }
            if (len != 0) stack.Push(len);
            return string.Join(" ", arr.Select(_ => _.ToString()).ToArray());
        }
        static string BuildStringBackward(ref Stack<int> stack, int width)
        {
            var arr = new int[width];
            var len = 0;
            for (var idx = width - 1; idx >= 0; --idx) {
                if (len == 0) len = stack.Pop();
                arr[idx] = stack.Count() + 1;
                --len;
            }
            if (len != 0) stack.Push(len);
            return string.Join(" ", arr.Select(_ => _.ToString()).ToArray());
        }
    }
}