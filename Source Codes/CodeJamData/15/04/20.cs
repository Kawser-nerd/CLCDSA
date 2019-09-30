using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    #region base class with common functionality
    [DebuggerDisplay("({X},{Y})")]
    public struct Point
    {
        public Point(long x, long y)
            : this()
        {
            X = x;
            Y = y;
        }
        public long X
        {
            get;
            set;
        }
        public long Y
        {
            get;
            set;
        }
    }

    /// <summary>
    /// Common functionality
    /// </summary>
    abstract class BaseGoogleJamProblem
    {

        protected int Min ( params int [] values )
        {
            var  min = values[0];
            for (int i = 1; i < values.Length; i++)
                min = Math.Min(min, values[i]);
            return min;
        }

        protected string Min(params string[] values)
        {
            var min = values[0];
            for (int i = 1; i < values.Length; i++)
            {
                if (min == null)
                    min = values[i];
                else
                {
                    int comparation = min.CompareTo(values[i]);
                    if (comparation > 0)
                        min = values[i];
                }
            }
            return min;
        }

        protected string Max(params string[] values)
        {
            var max = values[0];
            for (int i = 1; i < values.Length; i++)
            {
                if (max == null)
                {
                    max = values[i];
                }
                else
                {
                    int comparation = max.CompareTo(values[i]);
                    if (comparation < 0)
                        max = values[i];
                }
            }
            return max;
        }
        protected long Min(params long[] values)
        {
            var  min = values[0];
            for (int i = 1; i < values.Length; i++)
                min = Math.Min(min, values[i]);
            return min;
        }

        protected int Max(params int[] values)
        {
            var max = values[0];
            for (int i = 1; i < values.Length; i++)
                max = Math.Max(max, values[i]);
            return max;
        }
        protected long Max(params long[] values)
        {
            var max = values[0];
            for (int i = 1; i < values.Length; i++)
                max = Math.Max(max, values[i]);
            return max;
        }
        protected static string ConvertToBase(long value, int baseToConvertTo, string chars = "0123456789ABCDEF")
        {
            if (value == 0)
                return chars[0].ToString();
            string result = "";
            while (value > 0)
            {
                int index = (int) (value % baseToConvertTo);
                result = chars[index] + result;
                value = value / baseToConvertTo;
            }
            return result;
        }
        public static void Solve<T>( string inputFileName) 
            where T: BaseGoogleJamProblem, new()
        {
            T problem = new T();
            problem.Solve(inputFileName);
        }
        protected long[] PrimesLowerThan ( int value)
        {
            bool[] sieve = CreateArray<bool>((int)value, true);
            sieve[0] = false;
            sieve[1] = false;
            for (int i = 2; i < value; i++)
            {
                if (sieve[i])
                {
                    for (int j = i * 2; j < value; j += i)
                    sieve[j] = false;
            }
            }
            int count = 0;
            for (int i = 0; i < value; i++)
                if (sieve[i])
                    count++;

            long[] primes = new long[count];

            for (int i = 0, current = 0; i < value; i++)
                if (sieve[i])
                    primes[current++] = i;
            return primes;
        }
        Stopwatch s = new Stopwatch();
        CultureInfo cultureInfo = new CultureInfo("en");

        protected CultureInfo CultureInfo
        {
            get
            {
                return cultureInfo;
            }
        }
        #region state related properties
        protected int CaseCount
        {
            get;
            set;
        }
        protected int CaseIndex
        {
            get;
            set;
        }
        protected int CurrentLine
        {
            get;
            set;
        }
        protected string[] FileLines
        {
            get;
            set;
        }
        protected StringBuilder Result
        {
            get;
            set;
        }
        #endregion state related properties

        #region auxiliary methods
        public static long Combinations(long n, long k)
        {
            double sum = 0;
            for (long i = 0; i < k; i++)
            {
                sum += Math.Log10(n - i);
                sum -= Math.Log10(i + 1);
            }
            return (long)Math.Pow(10, sum);
        }

        protected T[,] CreateMatrix<T> ( int width , int height , T defaultValue)
        {
            T[,] matrix = new T[width, height];
            for ( int i = 0; i < width ; i++)
                for ( int j = 0; j < height ; j++)
                    matrix[i,j]=defaultValue;
            return matrix;
        }
        protected bool CompareArrays<T> ( T[] array1 , T[] array2)
            where T:IComparable
        {
            if ( array1 == null)
                return array2 == null;
            
            if (array2 == null)
                return false;

            int len1 = array1.Length;
            int len2 = array2.Length;
            if (len1 != len2)
                return false;

            for ( int i = 0; i < len1; i++)
            {
                if (array1[i].CompareTo (array2[i])!= 0)
                    return false;
            }
            return true;
        }
        protected T[] CreateArray<T>(long size, T defaultValue = default(T))
        {
            if (size < 0)
                return null;
            T[] array = new T[size];
            for (int i = 0; i < size; i++)
                array[i] = defaultValue;
            return array;
        }
        protected T[] CloneArray<T>(T[] array)
        {
            if (array == null)
                return null;
            T[] newArray = new T[array.Length];
            for (int i = 0; i < array.Length; i++)
                newArray[i] = array[i];
            return newArray;
        }
        protected string DoubleToString(double value, int decimalPlaces = -1)
        {
            if (decimalPlaces<0)
            return value.ToString(cultureInfo);
            else
                return string.Format ( cultureInfo,"{0.".PadRight ( decimalPlaces + 3,'0') + "}",value );
        }
        protected int ReadLineAsInt()
        {
            return int.Parse(FileLines[CurrentLine++]);
        }
        protected long ReadLineAsLong()
        {
            return long.Parse(FileLines[CurrentLine++]);
        }


        
        protected string ReadLineAsString()
        {
            return FileLines[CurrentLine++];
        }

        string RemainingLine
        {
            get;
            set;
        }

        protected int [,] ReadMatrix ( int width, int height)
        {
            int [,] matrix = new int[width, height];
            for ( int i = 0 ; i < height ; i++)
            {
                var values = ReadSpaceSeparatedIntegers();
                for (int j = 0; j < width; j++)
                    matrix[j,i] = values[j];
            }
            return matrix;
        }

        private T ReadValue<T> ( Func<string,T> readFunc)
        {
            if (string.IsNullOrEmpty(RemainingLine))
                RemainingLine = ReadLineAsString();

            int pos = RemainingLine.IndexOf(" ");
            if (pos < 0)
            {
                var v = readFunc(RemainingLine);
                RemainingLine = "";
                return v;
            }
            else
            {

                var value = readFunc(RemainingLine.Substring(0, pos));
                RemainingLine = RemainingLine.Substring(pos).Trim();
                return value;
            }
        }
        protected int ReadInt()
        {
            return ReadValue<int>(x => int.Parse(x));
        }
        protected string ReadString()
        {
            return ReadValue<string>(x => x);
        }
        protected long ReadLong()
        {
            return ReadValue<long>(x => long.Parse(x));
        }

        protected double ReadDouble()
        {
            return ReadValue<double>(x => double.Parse(x,cultureInfo));
        }


        
        protected int[] ReadSpaceSeparatedIntegers()
        {
            string value = FileLines[CurrentLine++];
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] result = new int[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = int.Parse(values[i]);
            return result;
        }
        protected string[] ReadSpaceSeparatedStrings()
        {
            string value = FileLines[CurrentLine++];
            return value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        }
        protected long[] ReadSpaceSeparatedLongs()
        {
            string value = FileLines[CurrentLine++];
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            long[] result = new long[values.Length];
            for (long i = 0; i < values.Length; i++)
                result[i] = long.Parse(values[i]);
            return result;
        }

        protected double[] ReadSpaceSeparatedDoubles()
        {
            string value = FileLines[CurrentLine++];
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            double[] result = new double[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = double.Parse(values[i], cultureInfo);
            return result;
        }

        protected virtual void AddCaseResponse ( long value )
        {
            AddCaseResponse(value.ToString());
        }
        protected virtual void AddCaseResponse ( long? value , string textWhenNull = "" )
        {
            if (value == null)
                AddCaseResponse(textWhenNull);
            else
                AddCaseResponse(value.Value.ToString());
        }

        protected virtual void AddCaseResponse ( double response, int decimalPlaces = -1)
        {
            AddCaseResponse(DoubleToString(response, decimalPlaces));
        }
        protected virtual void AddCaseResponse(string response)
        {
            Console.WriteLine(string.Format("Case {0} of {1}: {2}", CaseIndex, CaseCount, response));
            Result.AppendFormat("Case #{0}: {1}\r\n", CaseIndex, response);

            Console.WriteLine(string.Format("Case #{0}: {1} ({2}ms)", CaseIndex, response, s.ElapsedMilliseconds));
        }


        #endregion auxiliary methods


        #region debug related methods
        public string WriteMatrix<T>(T[,] matrix)
        {
            int width = matrix.GetLength(0);
            int height = matrix.GetLength(1);
            string[,] aux = new string[width, height];
            int maxSize = 0;
            for (int i = 0; i < width; i++)
                for (int j = 0; j < height; j++)
                {
                    string str = matrix[i, j] == null ? "null" : matrix[i, j].ToString();
                    aux[i, j] = str;
                    maxSize = Math.Max(str.Length, maxSize);
                }
            string result = "";
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    result += aux[j,i].PadRight(maxSize + 1, ' ');
                }
                result += "\r\n";
            }
            return result;
        }

        #endregion debug related methods
        public void Solve(string intputFileName, string outputFileName = null)
        {
            s.Start();
            if (string.IsNullOrEmpty(outputFileName))
                outputFileName = string.Format("{0}\\{1}.out.txt", System.IO.Path.GetDirectoryName(intputFileName), System.IO.Path.GetFileNameWithoutExtension(intputFileName));
            FileLines = System.IO.File.ReadAllLines(intputFileName);
            CurrentLine = 0;
            CaseIndex = 0;
            Result = new StringBuilder();
            SolveProblem();
            System.IO.File.WriteAllText(outputFileName, Result.ToString());
        }

        protected virtual void SolveProblem()
        {
            CaseCount = ReadLineAsInt();
            for (CaseIndex = 1; CaseIndex <= CaseCount; CaseIndex++)
                SolveProblemCase();
        }

        protected abstract void SolveProblemCase();

    }
    #endregion base class with common functionality

    class OminousOmino : BaseGoogleJamProblem
    {


        bool SolveSmall ( int X , int width , int height)
        {
            if ( width < height)
            {
                var aux = height;
                height = width;
                width = aux;
            }
            if ((width * height) % X != 0)
                return true;
            
            switch ( X)
            {
                case 1:
                    return false;
                case 2:
                    return false;
                case 3:
                    if (height == 1)
                        return true;
                    else
                        return false;
                case 4:
                    if (height < 3)
                        return true;
                    else
                        return false;
            }
            throw new NotImplementedException();
        }
        protected override void SolveProblemCase()
        {
            var X = ReadInt();
            var R = ReadInt();
            var C = ReadInt();

            var richardWins = SolveSmall(X, R, C);
            AddCaseResponse(richardWins ? "RICHARD" : "GABRIEL");
        }
    }
    class Program
    {
        
        static void Main(string[] args)
        {
            var problem = new OminousOmino();
            
            //problem.Solve("c:\\temp\\input.txt");
            problem.Solve("c:\\temp\\D-small-attempt0.in");
        }
    }

}

