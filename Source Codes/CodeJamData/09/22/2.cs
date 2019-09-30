using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            char[] s = Console.ReadLine().ToCharArray();
            if (!NextPermutation<char>(s))
            {
                List<char> digs = new List<char>();
                int zero = 1;
                for (int i = 0; i < s.Length; i++)
                {
                    if (s[i] == '0')
                        zero++;
                    else
                        digs.Add(s[i]);
                }
                digs.Sort();
                char[] s2 = new char[digs.Count + zero];
                s2[0] = digs[0];
                for (int i = 0; i < zero; i++)
                    s2[i + 1] = '0';
                for (int i = 1; i < digs.Count; i++)
                    s2[i + zero] = digs[i];
                s = s2;
            }
            Console.WriteLine("Case #" + CASE + ": " + new string(s));
        }
    }

    #region "Next Permutation"
    public static bool NextPermutation<T>(T[] array) where T : IComparable
    {
        for (int i = array.Length - 2; i >= 0; i--)
        {
            if (array[i].CompareTo(array[i + 1]) < 0)
            {
                int j = array.Length - 1;
                while (array[i].CompareTo(array[j]) >= 0)
                    j--;
                T tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                Array.Reverse(array, i + 1, array.Length - i - 1);
                return true;
            }
        }
        return false;
    }
    #endregion
}
