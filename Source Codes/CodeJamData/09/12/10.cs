using System;
using System.Text;
using System.IO;

namespace GoogleCodeJam.PractiseProblems.HelperClasses
{
    public static class ReadPrimitivesExtensionMethods
    {
        /// <summary>Returns the next string of non-whitespace characters.</summary>
        /// <param name="tr">The TextReader to read from.</param>
        public static string ReadWord(this TextReader tr)
        {
            char c;
            //Skip whitespace
            do
            {
                c = (char)tr.Read();
            } while (Char.IsWhiteSpace(c));
            StringBuilder sb = new StringBuilder(10);
            do
            {
                sb.Append(c);
                c = (char)tr.Read();
            } while (!Char.IsWhiteSpace(c));
            return sb.ToString();
        }

        public static int ReadInt(this TextReader tr)
        {
            string s = tr.ReadWord();
            return int.Parse(s);
        }

        public static float ReadFloat(this TextReader tr)
        {
            string s = tr.ReadWord();
            return float.Parse(s);
        }

        public static double ReadDouble(this TextReader tr)
        {
            string s = tr.ReadWord();
            return double.Parse(s);
        }

        public static long ReadLong(this TextReader tr)
        {
            string s = tr.ReadWord();
            return long.Parse(s);
        }
    }
}
