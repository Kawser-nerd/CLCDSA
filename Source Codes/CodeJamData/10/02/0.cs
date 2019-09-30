using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ10Q
{
    class FairWarning : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int N = int.Parse(s[0]);
                BigInteger[] events = new BigInteger[N];
                for (int i = 0; i < N; i++)
                {
                    events[i] = new BigInteger(s[i + 1]);
                }
                BigInteger ret = apoc(events);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private BigInteger apoc(BigInteger[] events)
        {
            Array.Sort(events);
            for (int i = 1; i < events.Length; i++)
            {
                events[i] = BigInteger.Subtract(events[i], events[0]);
            }
            BigInteger g = new BigInteger(events[1]);
            for (int i = 2; i < events.Length; i++)
            {
                g = gcd(g, events[i]);
            }
            BigInteger ret = BigInteger.Subtract(g, BigInteger.Mod(events[0], g));
            if (ret.Equals(g)) ret = BigInteger.Zero;
            return ret;
        }

        private BigInteger gcd(BigInteger a, BigInteger b)
        {
            if (!a.Positive) return gcd(a.Negative(), b);
            if (!b.Positive) return gcd(a, b.Negative());
            if (b.CompareTo(a) < 0) return gcd(b, a);
            if (a.isZero()) return b;
            return gcd(BigInteger.Mod(b, a), a);
        }



    }


    public class BigInteger : IComparable
    {
        private int[] num;
        private bool positive = true;

        public BigInteger()
        {
            this.num = new int[] { 0 };
            this.positive = true;
        }

        public BigInteger(string s)
        {
            if (s.Length == 0)
            {
                this.num = BigInteger.Zero.num;
            }
            else
            {
                if (s[0] == '-')
                {
                    this.positive = false;
                    this.num = new int[s.Length - 1];
                    for (int i = 1; i < s.Length; i++)
                    {
                        this.num[i - 1] = s[i] - '0';
                    }
                }
                else
                {
                    this.positive = true;
                    this.num = new int[s.Length];
                    for (int i = 0; i < s.Length; i++)
                    {
                        this.num[i] = s[i] - '0';
                    }
                }
            }
        }

        public BigInteger(int i)
            : this(i.ToString())
        {

        }

        public BigInteger(long i)
            : this(i.ToString())
        {

        }

        public BigInteger(int[] i, bool positive)
        {
            this.num = new int[i.Length];
            Array.Copy(i, this.num, i.Length);
            this.positive = positive;
        }

        public BigInteger(BigInteger b)
        {
            this.num = new int[b.Length];
            Array.Copy(b.num, this.num, b.Length);
            this.positive = b.Positive;
        }

        public int this[int index]
        {
            get
            {
                return this.num[index];
            }
        }

        public int Length
        {
            get
            {
                CleanLeadingZeroes();
                return this.num.Length;
            }
        }

        public bool Positive
        {
            get
            {
                return this.positive || this.isZero();
            }
        }

        public static BigInteger Zero
        {
            get { return new BigInteger(); }
        }


        public bool isZero()
        {
            if (this.num[0] != 0) return false;
            if (this.num.Length == 1 && this.num[0] == 0) return true;
            CleanLeadingZeroes();
            return this.isZero();
        }

        public BigInteger Negative()
        {
            BigInteger ret = new BigInteger(this);
            ret.positive = !ret.positive;
            return ret;
        }

        private void CleanLeadingZeroes()
        {
            if (this.num[0] != 0) return;
            int firstNonZero = -1;
            for (int i = 0; i < this.num.Length && firstNonZero == -1; i++)
            {
                if (this.num[i] != 0) firstNonZero = i;
            }
            if (firstNonZero == -1) firstNonZero = this.num.Length - 1;
            int[] clean = new int[num.Length - firstNonZero];
            Array.Copy(num, firstNonZero, clean, 0, num.Length - firstNonZero);
            num = clean;
        }

        public override string ToString()
        {
            this.CleanLeadingZeroes();
            char[] c = new char[this.num.Length];
            for (int i = 0; i < this.num.Length; i++)
            {
                c[i] = (char)('0' + this.num[i]);
            }
            return (this.Positive ? "" : "-") + new string(c);
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }

        public override bool Equals(object obj)
        {
            return this.CompareTo(obj) == 0;
        }

        public int CompareTo(object obj)
        {
            BigInteger b = obj as BigInteger;
            if (this.Positive && !b.Positive) return 1;
            if (!this.Positive && b.Positive) return -1;
            int ret = 0;
            for (int i = Math.Max(this.num.Length, b.Length) - 1;
                i >= 0 && ret == 0; i--)
            {
                int thisVal = 0;
                if (this.num.Length > i)
                    thisVal = this.num[this.num.Length - i - 1];
                int bVal = 0;
                if (b.Length > i) bVal = b[b.Length - i - 1];
                ret = thisVal.CompareTo(bVal);
            }
            if (!this.Positive) ret = -ret;
            return ret;
        }

        public static BigInteger Add(BigInteger a, BigInteger b)
        {
            if (a.Positive != b.Positive)
            {
                if (a.CompareTo(b) < 0)
                {
                    return BigInteger.Subtract(b, a.Negative());
                }
                else
                {
                    return BigInteger.Subtract(a, b.Negative());
                }
            }
            int max = Math.Max(a.Length, b.Length);
            int[] ret = new int[max + 1];
            int carry = 0;
            for (int i = 0; i < max; i++)
            {
                int tot = carry;
                if (a.Length - i - 1 >= 0) tot += a[a.Length - i - 1];
                if (b.Length - i - 1 >= 0) tot += b[b.Length - i - 1];
                carry = tot / 10;
                ret[ret.Length - 1 - i] = tot % 10;
            }
            ret[0] = carry;
            BigInteger r = new BigInteger(ret, a.Positive);
            r.CleanLeadingZeroes();
            return r;
        }

        public static BigInteger Mod(BigInteger a, BigInteger b)
        {
            BigInteger d = BigInteger.Divide(a, b);
            return BigInteger.Subtract(a, BigInteger.Multiply(b, d));
        }

        public static BigInteger Multiply(BigInteger a, BigInteger b)
        {
            int[][] partial = new int[b.Length][];
            for (int j = 0; j < b.Length; j++)
            {
                partial[j] = new int[a.Length + 1 + j];
                int carry = 0;
                for (int i = 0; i < a.Length; i++)
                {
                    int tot = carry + b[b.Length - 1 - j] * a[a.Length - 1 - i];
                    carry = tot / 10;
                    partial[j][a.Length - i] = tot % 10;
                }
                partial[j][0] = carry;
            }
            BigInteger ret = new BigInteger(partial[0], true);
            for (int j = 1; j < b.Length; j++)
            {
                ret = Add(ret, new BigInteger(partial[j], true));
            }
            ret.CleanLeadingZeroes();
            if (a.Positive ^ b.Positive) ret = ret.Negative();
            return ret;
        }

        public static BigInteger Subtract(BigInteger a, BigInteger b)
        {
            if (a.Positive && !b.Positive)
                return BigInteger.Add(a, b.Negative());
            if (!a.Positive && b.Positive)
                return BigInteger.Add(a.Negative(), b).Negative();
            if (!a.Positive && !b.Positive)
                return BigInteger.Subtract(a.Negative(), b.Negative()).Negative();
            if (a.CompareTo(b) < 0)
            {
                return BigInteger.Subtract(b, a).Negative();
            }
            int max = Math.Max(a.Length, b.Length);
            int[] ret = new int[max];
            int carry = 0;
            for (int i = 0; i < a.Length; i++)
            {
                int tot = carry;
                if (a.Length - i - 1 >= 0) tot += a[a.Length - i - 1];
                if (b.Length - i - 1 >= 0) tot -= b[b.Length - i - 1];
                carry = (tot - 9) / 10;
                ret[ret.Length - 1 - i] = ((tot % 10) + 10) % 10;
            }
            BigInteger r = new BigInteger(ret, true);
            r.CleanLeadingZeroes();
            return r;
        }

        public static BigInteger Divide(BigInteger a, BigInteger b)
        {
            // Implementation is ugly and very slow, 
            // with O(5*dig(N)) calls to multiply.
            if (b.isZero()) throw new OverflowException(
                "Cannot divide BigInteger by BigInteger.Zero");
            if (!b.Positive) return Divide(a, b.Negative()).Negative();
            int[] res = new int[a.Length];
            BigInteger balance = BigInteger.Zero;
            for (int i = 0; i < a.Length; i++)
            {
                balance = BigInteger.Multiply(balance, new BigInteger(10));
                balance = BigInteger.Add(balance, new BigInteger(a[i]));
                int digit = 0;
                while (balance.CompareTo(BigInteger.Multiply(b, new
     BigInteger(digit))) >= 0) digit++;
                res[i] = digit - 1;
                balance = BigInteger.Subtract(balance,
     BigInteger.Multiply(b, new BigInteger(res[i])));
            }

            return new BigInteger(res, a.Positive);
        }

        public static BigInteger SquareRoot(BigInteger a)
        {
            if (!a.Positive) throw new OverflowException(
                "Cannot find square root of a negative BigInteger");

            int[] ret = new int[(a.Length + 1) / 2];
            for (int i = 0; i < ret.Length; i++)
            {
                for (int j = 1; j < 10; j++)
                {
                    ret[i] = j;
                    BigInteger candidateRoot = new BigInteger(ret, true);
                    int compare = BigInteger.Multiply(
                        candidateRoot, candidateRoot).CompareTo(a);
                    if (compare == 0) return candidateRoot;
                    if (compare > 0)
                    {
                        ret[i]--;
                        break;
                    }
                }
            }
            return new BigInteger(ret, true);
        }

        public static BigInteger Abs(BigInteger a)
        {
            return new BigInteger(a.num, true);
        }

        public void RemoveTrailZeroes()
        {
            for (int i = num.Length - 1; i >= 0; i--)
            {
                if (num[i] > 0)
                {
                    if (i == num.Length - 1) return;
                    int[] trimmed = new int[i + 1];
                    Array.Copy(num, trimmed, i + 1);
                    num = trimmed;
                    return;
                }
            }
        }

        public void ModBase10(int digits)
        {
            if (num.Length <= digits) return;
            int[] trimmed = new int[digits];
            for (int i = 0; i < digits; i++)
            {
                trimmed[i] = num[num.Length - digits + i];
            }
            num = trimmed;
        }
    }

}
