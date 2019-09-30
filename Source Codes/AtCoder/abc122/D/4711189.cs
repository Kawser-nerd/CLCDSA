using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

using FiniteFieldSystem;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        FiniteField[][][][] dp = new FiniteField[N + 1][][][];
        for (int i = 0; i <= N; i++)
        {
            dp[i] = new FiniteField[4][][];
            for (int j = 0; j < 4; j++)
            {
                dp[i][j] = new FiniteField[4][];
                for (int k = 0; k < 4; k++)
                    dp[i][j][k] = new FiniteField[4];
            }
        }
        dp[3][0][0][0] = 1;
        dp[3][0][0][1] = 1;
        dp[3][0][0][2] = 1;
        dp[3][0][0][3] = 1;
        dp[3][0][1][0] = 1;
        dp[3][0][1][1] = 1;
        dp[3][0][1][2] = 1;
        dp[3][0][1][3] = 1;
        dp[3][0][2][0] = 1;
        dp[3][0][2][1] = 1;
        dp[3][0][2][2] = 1;
        dp[3][0][2][3] = 1;
        dp[3][0][3][0] = 1;
        dp[3][0][3][1] = 1;
        dp[3][0][3][2] = 1;
        dp[3][0][3][3] = 1;

        dp[3][1][0][0] = 1;
        dp[3][1][0][1] = 1;
        dp[3][1][0][2] = 1;
        dp[3][1][0][3] = 1;
        dp[3][1][1][0] = 1;
        dp[3][1][1][1] = 1;
        dp[3][1][1][2] = 1;
        dp[3][1][1][3] = 1;
        dp[3][1][2][0] = 0;
        dp[3][1][2][1] = 1;
        dp[3][1][2][2] = 1;
        dp[3][1][2][3] = 1;
        dp[3][1][3][0] = 1;
        dp[3][1][3][1] = 1;
        dp[3][1][3][2] = 1;
        dp[3][1][3][3] = 1;

        dp[3][2][0][0] = 1;
        dp[3][2][0][1] = 0;
        dp[3][2][0][2] = 1;
        dp[3][2][0][3] = 1;
        dp[3][2][1][0] = 0;
        dp[3][2][1][1] = 1;
        dp[3][2][1][2] = 1;
        dp[3][2][1][3] = 1;
        dp[3][2][2][0] = 1;
        dp[3][2][2][1] = 1;
        dp[3][2][2][2] = 1;
        dp[3][2][2][3] = 1;
        dp[3][2][3][0] = 1;
        dp[3][2][3][1] = 1;
        dp[3][2][3][2] = 1;
        dp[3][2][3][3] = 1;

        dp[3][3][0][0] = 1;
        dp[3][3][0][1] = 1;
        dp[3][3][0][2] = 1;
        dp[3][3][0][3] = 1;
        dp[3][3][1][0] = 1;
        dp[3][3][1][1] = 1;
        dp[3][3][1][2] = 1;
        dp[3][3][1][3] = 1;
        dp[3][3][2][0] = 1;
        dp[3][3][2][1] = 1;
        dp[3][3][2][2] = 1;
        dp[3][3][2][3] = 1;
        dp[3][3][3][0] = 1;
        dp[3][3][3][1] = 1;
        dp[3][3][3][2] = 1;
        dp[3][3][3][3] = 1;

        for (int i = 4; i <= N; i++)
        {
            dp[i][0][0][0] = dp[i - 1][0][0][0] + dp[i - 1][0][0][1] + dp[i - 1][0][0][2] + dp[i - 1][0][0][3];
            dp[i][0][0][1] = dp[i - 1][0][1][0] + dp[i - 1][0][1][1] + dp[i - 1][0][1][2] + dp[i - 1][0][1][3];
            dp[i][0][0][2] = dp[i - 1][0][2][0] + dp[i - 1][0][2][1] + dp[i - 1][0][2][2] + dp[i - 1][0][2][3];
            dp[i][0][0][3] = dp[i - 1][0][3][0] + dp[i - 1][0][3][1] + dp[i - 1][0][3][2] + dp[i - 1][0][3][3];
            dp[i][0][1][0] = dp[i - 1][1][0][0] + dp[i - 1][1][0][1] + dp[i - 1][1][0][2] + dp[i - 1][1][0][3];
            dp[i][0][1][1] = dp[i - 1][1][1][0] + dp[i - 1][1][1][1] + dp[i - 1][1][1][2] + dp[i - 1][1][1][3];
            dp[i][0][1][2] = dp[i - 1][1][2][0] + dp[i - 1][1][2][1] + dp[i - 1][1][2][2] + dp[i - 1][1][2][3];
            dp[i][0][1][3] = dp[i - 1][1][3][0] + dp[i - 1][1][3][1] + dp[i - 1][1][3][2] + dp[i - 1][1][3][3];
            dp[i][0][2][0] = dp[i - 1][2][0][0] + dp[i - 1][2][0][1] + dp[i - 1][2][0][2] + dp[i - 1][2][0][3];
            dp[i][0][2][1] = dp[i - 1][2][1][0] + dp[i - 1][2][1][1] + dp[i - 1][2][1][2] + dp[i - 1][2][1][3];
            dp[i][0][2][2] = dp[i - 1][2][2][0] + dp[i - 1][2][2][1] + dp[i - 1][2][2][2] + dp[i - 1][2][2][3];
            dp[i][0][2][3] = dp[i - 1][2][3][0] + dp[i - 1][2][3][1] + dp[i - 1][2][3][2] + dp[i - 1][2][3][3];
            dp[i][0][3][0] = dp[i - 1][3][0][0] + dp[i - 1][3][0][1] + dp[i - 1][3][0][2] + dp[i - 1][3][0][3];
            dp[i][0][3][1] = dp[i - 1][3][1][0] + dp[i - 1][3][1][1] + dp[i - 1][3][1][2] + dp[i - 1][3][1][3];
            dp[i][0][3][2] = dp[i - 1][3][2][0] + dp[i - 1][3][2][1] + dp[i - 1][3][2][2] + dp[i - 1][3][2][3];
            dp[i][0][3][3] = dp[i - 1][3][3][0] + dp[i - 1][3][3][1] + dp[i - 1][3][3][2] + dp[i - 1][3][3][3];

            dp[i][1][0][0] = dp[i - 1][0][0][0] + dp[i - 1][0][0][1] + dp[i - 1][0][0][2] + dp[i - 1][0][0][3];
            dp[i][1][0][1] = dp[i - 1][0][1][0] + dp[i - 1][0][1][1] + dp[i - 1][0][1][2] + dp[i - 1][0][1][3];
            dp[i][1][0][2] = dp[i - 1][0][2][0] + dp[i - 1][0][2][1] + dp[i - 1][0][2][2] + dp[i - 1][0][2][3];
            dp[i][1][0][3] = dp[i - 1][0][3][0] + dp[i - 1][0][3][1] + dp[i - 1][0][3][2] + dp[i - 1][0][3][3];
            dp[i][1][1][0] = dp[i - 1][1][0][0] + dp[i - 1][1][0][1] + dp[i - 1][1][0][2] + dp[i - 1][1][0][3];
            dp[i][1][1][1] = dp[i - 1][1][1][0] + dp[i - 1][1][1][1] + dp[i - 1][1][1][2] + dp[i - 1][1][1][3];
            dp[i][1][1][2] = dp[i - 1][1][2][0] + dp[i - 1][1][2][1] + dp[i - 1][1][2][2] + dp[i - 1][1][2][3];
            dp[i][1][1][3] = dp[i - 1][1][3][0] + dp[i - 1][1][3][1] + dp[i - 1][1][3][2] + dp[i - 1][1][3][3];
            dp[i][1][2][0] = 0;
            dp[i][1][2][1] = dp[i - 1][2][1][0] + dp[i - 1][2][1][1] + dp[i - 1][2][1][2] + dp[i - 1][2][1][3];
            dp[i][1][2][2] = dp[i - 1][2][2][0] + dp[i - 1][2][2][1] + dp[i - 1][2][2][2] + dp[i - 1][2][2][3];
            dp[i][1][2][3] = dp[i - 1][2][3][0] + dp[i - 1][2][3][1] + dp[i - 1][2][3][2] + dp[i - 1][2][3][3];
            dp[i][1][3][0] = dp[i - 1][3][0][0] + dp[i - 1][3][0][1] + dp[i - 1][3][0][2] + dp[i - 1][3][0][3];
            dp[i][1][3][1] = dp[i - 1][3][1][0] + dp[i - 1][3][1][1] + dp[i - 1][3][1][2] + dp[i - 1][3][1][3];
            dp[i][1][3][2] = dp[i - 1][3][2][0] + dp[i - 1][3][2][1] + dp[i - 1][3][2][2] + dp[i - 1][3][2][3];
            dp[i][1][3][3] = dp[i - 1][3][3][0] + dp[i - 1][3][3][1] + dp[i - 1][3][3][2] + dp[i - 1][3][3][3];

            dp[i][2][0][0] = dp[i - 1][0][0][0] + dp[i - 1][0][0][1] + dp[i - 1][0][0][2] + dp[i - 1][0][0][3];
            dp[i][2][0][1] = 0;
            dp[i][2][0][2] = dp[i - 1][0][2][0] + dp[i - 1][0][2][1] + dp[i - 1][0][2][2] + dp[i - 1][0][2][3];
            dp[i][2][0][3] = dp[i - 1][0][3][0] + dp[i - 1][0][3][1] + dp[i - 1][0][3][2] + dp[i - 1][0][3][3];
            dp[i][2][1][0] = 0;
            dp[i][2][1][1] = dp[i - 1][1][1][1] + dp[i - 1][1][1][2] + dp[i - 1][1][1][3];
            dp[i][2][1][2] = dp[i - 1][1][2][1] + dp[i - 1][1][2][2] + dp[i - 1][1][2][3];
            dp[i][2][1][3] = dp[i - 1][1][3][1] + dp[i - 1][1][3][2] + dp[i - 1][1][3][3];
            dp[i][2][2][0] = dp[i - 1][2][0][0] + dp[i - 1][2][0][1] + dp[i - 1][2][0][2] + dp[i - 1][2][0][3];
            dp[i][2][2][1] = dp[i - 1][2][1][1] + dp[i - 1][2][1][2] + dp[i - 1][2][1][3];
            dp[i][2][2][2] = dp[i - 1][2][2][0] + dp[i - 1][2][2][1] + dp[i - 1][2][2][2] + dp[i - 1][2][2][3];
            dp[i][2][2][3] = dp[i - 1][2][3][0] + dp[i - 1][2][3][1] + dp[i - 1][2][3][2] + dp[i - 1][2][3][3];
            dp[i][2][3][0] = dp[i - 1][3][0][0] + dp[i - 1][3][0][1] + dp[i - 1][3][0][2] + dp[i - 1][3][0][3];
            dp[i][2][3][1] = dp[i - 1][3][1][1] + dp[i - 1][3][1][2] + dp[i - 1][3][1][3];
            dp[i][2][3][2] = dp[i - 1][3][2][0] + dp[i - 1][3][2][1] + dp[i - 1][3][2][2] + dp[i - 1][3][2][3];
            dp[i][2][3][3] = dp[i - 1][3][3][0] + dp[i - 1][3][3][1] + dp[i - 1][3][3][2] + dp[i - 1][3][3][3];

            dp[i][3][0][0] = dp[i - 1][0][0][0] + dp[i - 1][0][0][1] + dp[i - 1][0][0][2] + dp[i - 1][0][0][3];
            dp[i][3][0][1] = dp[i - 1][0][1][0] + dp[i - 1][0][1][1] + dp[i - 1][0][1][2] + dp[i - 1][0][1][3];
            dp[i][3][0][2] = dp[i - 1][0][2][0] + dp[i - 1][0][2][1] + dp[i - 1][0][2][2] + dp[i - 1][0][2][3];
            dp[i][3][0][3] = dp[i - 1][0][3][0] + dp[i - 1][0][3][1] + dp[i - 1][0][3][2] + dp[i - 1][0][3][3];
            dp[i][3][1][0] = dp[i - 1][1][0][0] + dp[i - 1][1][0][1] + dp[i - 1][1][0][2] + dp[i - 1][1][0][3];
            dp[i][3][1][1] = dp[i - 1][1][1][0] + dp[i - 1][1][1][1] + dp[i - 1][1][1][2] + dp[i - 1][1][1][3];
            dp[i][3][1][2] = dp[i - 1][1][2][0] + dp[i - 1][1][2][1] + dp[i - 1][1][2][2] + dp[i - 1][1][2][3];
            dp[i][3][1][3] = dp[i - 1][1][3][0] + dp[i - 1][1][3][1] + dp[i - 1][1][3][2] + dp[i - 1][1][3][3];
            dp[i][3][2][0] = dp[i - 1][2][0][0] + dp[i - 1][2][0][1] + dp[i - 1][2][0][2] + dp[i - 1][2][0][3];
            dp[i][3][2][1] = dp[i - 1][2][1][0] + dp[i - 1][2][1][1] + dp[i - 1][2][1][2] + dp[i - 1][2][1][3];
            dp[i][3][2][2] = dp[i - 1][2][2][0] + dp[i - 1][2][2][1] + dp[i - 1][2][2][2] + dp[i - 1][2][2][3];
            dp[i][3][2][3] = dp[i - 1][2][3][0] + dp[i - 1][2][3][1] + dp[i - 1][2][3][2] + dp[i - 1][2][3][3];
            dp[i][3][3][0] = dp[i - 1][3][0][0] + dp[i - 1][3][0][1] + dp[i - 1][3][0][2] + dp[i - 1][3][0][3];
            dp[i][3][3][1] = dp[i - 1][3][1][0] + dp[i - 1][3][1][1] + dp[i - 1][3][1][2] + dp[i - 1][3][1][3];
            dp[i][3][3][2] = dp[i - 1][3][2][0] + dp[i - 1][3][2][1] + dp[i - 1][3][2][2] + dp[i - 1][3][2][3];
            dp[i][3][3][3] = dp[i - 1][3][3][0] + dp[i - 1][3][3][1] + dp[i - 1][3][3][2] + dp[i - 1][3][3][3];
        }
        Console.WriteLine(
        dp[N][0][0][0]+
        dp[N][0][0][1]+
        dp[N][0][0][2]+
        dp[N][0][0][3]+
        dp[N][0][1][0]+
        dp[N][0][1][1]+
        dp[N][0][1][2]+
        dp[N][0][1][3]+
        dp[N][0][2][0]+
        dp[N][0][2][1]+
        dp[N][0][2][2]+
        dp[N][0][2][3]+
        dp[N][0][3][0]+
        dp[N][0][3][1]+
        dp[N][0][3][2]+
        dp[N][0][3][3]+

        dp[N][1][0][0]+
        dp[N][1][0][1]+
        dp[N][1][0][2]+
        dp[N][1][0][3]+
        dp[N][1][1][0]+
        dp[N][1][1][1]+
        dp[N][1][1][2]+
        dp[N][1][1][3]+
        dp[N][1][2][0]+
        dp[N][1][2][1]+
        dp[N][1][2][2]+
        dp[N][1][2][3]+
        dp[N][1][3][0]+
        dp[N][1][3][1]+
        dp[N][1][3][2]+
        dp[N][1][3][3]+

        dp[N][2][0][0]+
        dp[N][2][0][1]+
        dp[N][2][0][2]+
        dp[N][2][0][3]+
        dp[N][2][1][0]+
        dp[N][2][1][1]+
        dp[N][2][1][2]+
        dp[N][2][1][3]+
        dp[N][2][2][0]+
        dp[N][2][2][1]+
        dp[N][2][2][2]+
        dp[N][2][2][3]+
        dp[N][2][3][0]+
        dp[N][2][3][1]+
        dp[N][2][3][2]+
        dp[N][2][3][3]+

        dp[N][3][0][0]+
        dp[N][3][0][1]+
        dp[N][3][0][2]+
        dp[N][3][0][3]+
        dp[N][3][1][0]+
        dp[N][3][1][1]+
        dp[N][3][1][2]+
        dp[N][3][1][3]+
        dp[N][3][2][0]+
        dp[N][3][2][1]+
        dp[N][3][2][2]+
        dp[N][3][2][3]+
        dp[N][3][3][0]+
        dp[N][3][3][1]+
        dp[N][3][3][2]+
        dp[N][3][3][3]
        );
    }
}

namespace FiniteFieldSystem
{
    struct FiniteField : IComparable
    {
        public static readonly long p = 1000000007;

        public long Value;

        public int CompareTo(object obj)
        {
            if (obj == null) return 1;

            if (obj is FiniteField)
                return Value.CompareTo(((FiniteField)obj).Value);
            else
                throw new ArgumentException("");
        }

        public static implicit operator FiniteField(int value)
        {
            return new FiniteField(value);
        }
        public static implicit operator FiniteField(long value)
        {
            return new FiniteField(value);
        }
        public static implicit operator int(FiniteField value)
        {
            return (int)value.Value;
        }
        public static implicit operator long(FiniteField value)
        {
            return value.Value;
        }

        public FiniteField(int value)
        {
            Value = value % p;
            while (Value < 0)
                Value += p;
        }
        public FiniteField(long value)
        {
            Value = value % p;
            while (Value < 0)
                Value += p;
        }
        public FiniteField(FiniteField value)
        {
            Value = value.Value;
        }

        public static FiniteField operator +(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value + rhs.Value);
        }
        public static FiniteField operator -(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value - rhs.Value);
        }
        public static FiniteField operator *(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value * rhs.Value);
        }
        public static FiniteField operator /(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value * inversion(rhs));
        }
        static FiniteField inversion(FiniteField a)
        {
            long b = p, u = 1, v = 0;
            while (b!=0)
            {
                long t = a.Value / b;
                a.Value -= t * b;
                long tmp = a.Value;
                a.Value = b;
                b = tmp;
                u -= t * v;
                tmp = u;
                u = v;
                v = tmp;
            }
            u %= p;
            if (u < 0) u += p;
            return u;
        }

        public static FiniteField operator ++(FiniteField f)
        {
            return new FiniteField(f.Value + 1);
        }
        public static FiniteField operator --(FiniteField f)
        {
            return new FiniteField(f.Value - 1);
        }

        public override bool Equals(object obj)
        {
            if (obj == null || this.GetType() != obj.GetType())
                return false;
            return (Value == ((FiniteField)obj).Value);
        }
        public override int GetHashCode()
        {
            return Value.GetHashCode();
        }

        public static bool operator ==(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value == rhs.Value);
        }
        public static bool operator !=(FiniteField lhs, FiniteField rhs)
        {
            return !(lhs.Value == rhs.Value);
        }
        public static bool operator <(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value < rhs.Value);
        }
        public static bool operator >(FiniteField lhs, FiniteField rhs)
        {
            return (lhs.Value > rhs.Value);
        }

        public static FiniteField[] fac = { new FiniteField(1), new FiniteField(1) };
        public static FiniteField Factorial(FiniteField n)
        {
            if (fac.Length <= n.Value)
            {
                fac = new FiniteField[n + 1];
                fac[0] = new FiniteField(1);
                fac[1] = new FiniteField(1);
                for (int i = 2; i <= n; i++)
                    fac[i] = i * fac[i - 1];
            }
            return fac[n];
        }
        public static FiniteField nCm(FiniteField n, FiniteField m)
        {
            if (n < m) return 0;
            if (n < 0 || m < 0) return 0;

            return Factorial(n) / (Factorial(m) * Factorial(n - m));
        }
        public static FiniteField Catalan(FiniteField n)
        {
            return nCm(2 * n, n) / (n + 1);
        }
        public static FiniteField[] der = { new FiniteField(0), new FiniteField(1) };
        public static FiniteField Derangement(FiniteField n)
        {            
            if (der.Length < n.Value)
            {
                der = new FiniteField[n];
                der[0] = new FiniteField(0);
                der[1] = new FiniteField(1);
                for (int i = 2; i < n; i++)
                    der[i] = i * (der[i - 1] + der[i - 2]);
            }
            return der[n-1];
        }

        public new string ToString()
        {
            return Value.ToString();
        }
    }
}