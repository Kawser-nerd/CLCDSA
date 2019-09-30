using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ScratchPad
{
    public static class ParseUtils
    {
        public static int Int(this string data)
        {
            return int.Parse(data);
        }

        public static int[] IntA(this string data)
        {
            string[] split = data.Split(' ');
            return (from str in split select str.Int()).ToArray();
        }

    }
}
