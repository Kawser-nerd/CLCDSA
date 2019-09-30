using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CodeJam
{
    #region base problem resolution framework
    public  static class Extensions
    {

        public static T Get<T>(this T[] array, int i,  T defaultValue = default(T))
        {

            if (i < 0 || i >= array.Length)
                return defaultValue;
            return array[i];
        }
        public static T Get<T>(this T[,] matrix, int i, int j, T defaultValue = default(T))
        {

            if (i < 0 || j < 0)
                return defaultValue;

            int n = matrix.GetLength(0);
            int m = matrix.GetLength(1);
            if (i >= n || j >= m)
                return defaultValue;
            return matrix[i, j];
        }
        public static BigInteger SqrtN(this BigInteger n)
        {
            if (0 == n)
                return 0;
            BigInteger n1 = (n >> 1) + 1;
            BigInteger n2 = (n1 + (n / n1)) >> 1;
            while (n2 < n1)
            {
                n1 = n2;
                n2 = (n1 + (n / n1)) >> 1;
            }
            return n1;
        }
        public static int ToInt(this string value)
        {
            return int.Parse(value);
        }
        public static double ToDouble(this string value)
        {
            return double.Parse(value);
        }

        public static string ToString ( this double value, int decimalPlaces)
        {
            return string.Format("{0}", (Math.Round(value, decimalPlaces).ToString(string.Format ("F{0}", decimalPlaces)))).Replace(",", ".");
        }
        public static int IndexOf <T> ( this T [] values , T value, bool returnFirstHigherIfNoEqualFound = true)
            where T: IComparable
        {
            int start = 0;
            var length = values.Length;
            int end = length;
            if (length == 0)
                return -1;

            int comparison = values[start].CompareTo ( value);
            if (comparison == 0)
                return 0;
            if (comparison > 0)
                return returnFirstHigherIfNoEqualFound ?0:-1;
            comparison = values[end-1].CompareTo(value);
            if (comparison == 0)
                return end-1;
            if (comparison < 0)
                return returnFirstHigherIfNoEqualFound ? end : end-1;
            while (length > 1)
            {
                var middle = (start + end) >> 1;

                comparison = values[middle].CompareTo(value);
                if (comparison == 0)
                    return middle;
                if (comparison > 0)
                    end = middle;
                else
                    start = middle;
                length = end - start;
            }

            if (returnFirstHigherIfNoEqualFound)
                return end;
            else
                return start;

        }

        public static string Debug <T>(this T[,] array, int separation = 10)
        {
            int h = array.GetLength(0);
            int w = array.GetLength(1);
            string str = "";
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                    str += array[i, j].ToString().PadLeft(separation, ' ');
                str += "\r\n";
            }

            return str;
        }
    }

    #region set operations

    public class WeightedQuickUnion
    {
        int[] sz;
        int[] id;
        public WeightedQuickUnion(long n): this ( (int)n)
        { }
        public WeightedQuickUnion(int n)
        {
            sz = new int[n];
            id = new int[n];
            for (int i = 0; i < n; i++)
            {
                sz[i] = 1;
                id[i] = i;
            }
        }
        public WeightedQuickUnion(params int[] _ids)
        {
            id = _ids;
        }
        private int Root(int i)
        {
            while (i != id[i])
            {
                //id[] = id[id[i]];
                i = id[i];
            }
            return i;
        }
        public bool Connected(int p, int q)
        {
            return Root(p) == Root(q);
        }
        public void Union(long p, long q)
        {
            Union((int)p, (int)q);
        }
        public void Union(int p, int q)
        {
            int i = Root(p);
            int j = Root(q);
            if (i == j)
                return;
            if (sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
        }

        public int Group( int p)
        {
            return Root(p);
        }
        public int Count
        {
            get
            {
                int count = 0;
                int capacity = id.Length;
                for (int i = 0; i < capacity; i++)
                    if (id[i] == i)
                        count++;

                return count;
            }
        }
    }


    #endregion set operations

    public class Statistics
    {
        private static void Permutations<T> ( T[] values , bool[] aux , T[][] matrix, T[] currentValues ,ref int currentIndex, int currentAux, int length)
        {
            if (currentAux == length)
            {
                matrix[currentIndex] = new T[length];
                for (int j = 0; j < length; j++)
                    matrix[currentIndex][j] = currentValues[j];
                currentIndex++;
                return;
            }
            
            for (int i = 0; i < values.Length; i++)
            {
                if (!aux[i])
                {
                    currentValues[currentAux] = values[i];
                    aux[i] = true;
                    Permutations(values, aux, matrix, currentValues, ref currentIndex, currentAux + 1, length);
                    aux[i] = false;
                }
            }
        }
        public static T[][] Permutations<T>( IEnumerable<T> valuesToPermute)
        {
            var values = valuesToPermute.ToArray();
            bool [] aux = new bool[values.Length];
            int length = (int) CodeJamProblem.Factorial(values.Length);
            T[][] result = new T[length][];
            T[] currentValues = new T[values.Length];
            int i = 0;
            Permutations(values, aux, result, currentValues, ref i, 0 , values.Length);
            return result;
        }
    }
   
    [DebuggerDisplay("({X},{Y},{Z})")]
    public class Vector
    {
        public Vector()
        { }
        public Vector(double x, double y, double z)
            : this()
        {
            X = x;
            Y = y;
            Z = z;
        }
        public double X
        {
            get;
            set;
        }
        public double Y
        {
            get;
            set;
        }
        public double Z
        {
            get;
            set;
        }
        public double Mod()
        {
            return Math.Sqrt(X * X + Y * Y + Z * Z);
        }

        public static Vector operator *(double value, Vector v1)
        {
            return new Vector(v1.X * value,
           v1.Y = v1.Y * value,
           v1.Z = v1.Z * value);
        }
        public static Vector operator *(Vector v1, double value)
        {
            return new Vector(v1.X * value,
            v1.Y = v1.Y * value,
            v1.Z = v1.Z * value);
        }
        public static Vector operator /(Vector v1 , double value)
        {
            return new Vector(v1.X / value,
            v1.Y = v1.Y / value,
            v1.Z = v1.Z / value);
        }
        public static Vector operator +(Vector v1, Vector v2)
        {
            return new Vector(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
        }
        public static Vector operator -(Vector v1, Vector v2)
        {
            return new Vector(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
        }

        public static Vector operator -(Vector v1)
        {
            return new Vector(-v1.X, -v1.Y, v1.Z);
        }

        public double InnerProduct(Vector vector)
        {
            return X * vector.X + Y * vector.Y + Z * vector.Z;
        }
    }

    #region file reading
    public class FileReader
    {

        public static implicit operator int ( FileReader reader)
        {
            return reader.ReadInt();
        }
        public static implicit operator long(FileReader reader)
        {
            return reader.ReadLong();
        }
        public static implicit operator double(FileReader reader)
        {
            return reader.ReadDouble();
        }
        public static implicit operator string(FileReader reader)
        {
            return reader.ReadString();
        }
        public static implicit operator long[](FileReader reader)
        {
            return reader.ReadSpaceSeparatedLongs();
        }

        public static implicit operator BigInteger[](FileReader reader)
        {
            return reader.ReadSpaceSeparatedBigInts();
        }
        public static implicit operator int[](FileReader reader)
        {
            return reader.ReadSpaceSeparatedIntegers();
        }
        private FileReader(string text)
        {
            Content = text;
        }
        public string Content
        {
            get;
            set;
        }

        public int[] ReadLinesAsInt(int n)
        {
            int[] ints = new int[n];
            for (int i = 0; i < n; i++)
                ints[i] = ReadLineAsInt();
            return ints;
        }

        public string [] ReadLinesAsString(int n)
        {
            string[] strings = new string[n];
            for (int i = 0; i < n; i++)
                strings[i] = ReadLineAsString();
            return strings;
        }
        public string ReadLineAsString()
        {
            int pos = Content.IndexOfAny("\r\n".ToCharArray());
            if (pos == -1)
            {
                var result = Content;
                Content = "";
                return result;
            }
            else
            {
                var result = Content.Substring(0, pos);
                Content = Content.Substring(pos).Trim();
                return result;
            }
        }

        public long[,] ReadMatrix(int size)
        {
            long[,] matrix = null;
            for (int i = 0; i < size; i++)
            {
                var v = ReadSpaceSeparatedLongs();
                if (matrix == null)
                {
                    matrix = new long[size, v.Length];
                }
                for (int j = 0; j < v.Length; j++)
                    matrix[i, j] = v[j];
            }
            return matrix;
        }

        public int[] ReadSpaceSeparatedIntegers()
        {
            string value = ReadLineAsString();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] result = new int[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = int.Parse(values[i]);
            return result;
        }
        public string[] ReadSpaceSeparatedStrings()
        {
            string value = ReadLineAsString();
            return value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        }
        public long[] ReadSpaceSeparatedLongs()
        {
            string value = ReadLineAsString();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            long[] result = new long[values.Length];
            for (long i = 0; i < values.Length; i++)
                result[i] = long.Parse(values[i]);
            return result;
        }

        public BigInteger[] ReadSpaceSeparatedBigInts()
        {
            string value = ReadLineAsString();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            BigInteger[] result = new BigInteger[values.Length];
            for (long i = 0; i < values.Length; i++)
                result[i] = BigInteger.Parse(values[i]);
            return result;
        }

        public double[] ReadSpaceSeparatedDoubles()
        {
            string value = ReadLineAsString();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            double[] result = new double[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = double.Parse(values[i], CodeJamProblem.cultureInfo);
            return result;
        }

        public int ReadLineAsInt()
        {
            return int.Parse(ReadLineAsString());
        }
        public long ReadLineAsLong()
        {
            return long.Parse(ReadLineAsString());
        }



        protected int[,] ReadMatrix(int width, int height)
        {
            int[,] matrix = new int[width, height];
            for (int i = 0; i < height; i++)
            {
                var values = ReadSpaceSeparatedIntegers();
                for (int j = 0; j < width; j++)
                    matrix[j, i] = values[j];
            }
            return matrix;
        }

        private T ReadValue<T>(Func<string, T> readFunc)
        {

            int pos = Content.IndexOfAny(" \r\n".ToCharArray());
            if (pos < 0)
            {
                var v = readFunc(Content);
                Content = "";
                return v;
            }
            else
            {

                var value = readFunc(Content.Substring(0, pos));
                Content = Content.Substring(pos).Trim();
                return value;
            }
        }

        public char ReadChar()
        {
            var ch = Content.First();
            Content = Content.Substring(1);
            return ch;

        }
        public int ReadInt()
        {
            return ReadValue<int>(x => int.Parse(x));
        }
        public string ReadString()
        {
            return ReadValue<string>(x => x);
        }
        public long ReadLong()
        {
            return ReadValue<long>(x => long.Parse(x));
        }

        public double ReadDouble()
        {
            return ReadValue<double>(x => double.Parse(x, CodeJamProblem.cultureInfo));
        }


        public static FileReader CreateFromText(string text)
        {
            return new FileReader(text);
        }
    }
    #endregion file reading

    #region cycles
    public class Cycle<T>
    {
        [DebuggerDisplay("{Debug}")]
        public class WeightedCycleStep<T1>
        {
            public WeightedCycleStep( T1 value , long repetitions)
            {
                Value = value;
                Repetitions = repetitions;

            }
            public long Repetitions
            {
                get;
                private set;
            }

            public T1 Value
            {
                get;
                private set;
            }
            public string Debug
            {
                get
                {
                    return string.Format("{0} times {1}", Repetitions, Value.ToString());
                }
            }
        }
        public Cycle(List<CycleStep<T>> steps, int cycleSize)
        {
            CycleSize = cycleSize;
            Steps = steps;
        }
        public IEnumerable<T> LastCycle
        {
            get
            {
                return Steps.GetRange(Steps.Count - CycleSize, CycleSize).Select (x=>x.Value);
            }
        }
        public List<CycleStep<T>> Steps
        {
            get;
            set;
        }

        
        public IEnumerable <WeightedCycleStep <T>> GetSteps ( int iteration)
        {
            List<WeightedCycleStep<T>> result = new List<WeightedCycleStep<T>>();
            if ( iteration < Steps.Count)
            {
                for ( int i = 0; i < iteration; i++)
                    result.Add(new WeightedCycleStep<T>(Steps[i].Value, 1));
            }
            else
            {
                int warmUp = (Steps.Count - CycleSize );
                var totalInCycle = iteration -  warmUp;
                int repetitions = totalInCycle / CycleSize;
                int rem = totalInCycle % CycleSize;
                for (int i = 0; i < warmUp; i++)
                    result.Add(new WeightedCycleStep<T>(Steps[i].Value, 1));
                for (int i = 0, j = warmUp; i < rem; i++, j++)
                    result.Add(new WeightedCycleStep<T>(Steps[j].Value, repetitions + 1));
                for (int i = rem, j = warmUp + rem; i < CycleSize; i++, j++)
                    result.Add(new WeightedCycleStep<T>(Steps[j].Value, repetitions));
                
            }
            return result;
        }

        public int CycleSize
        {
            get;
            set;
        }

        public long FullCycles ( long iteration)
        {
            return iteration % CycleSize;
        }
        public T GetStep ( long iteration)
        {
            if ( iteration < Steps.Count)
                return Steps[(int)iteration].Value;
            else
                return Steps[(int)(Steps.Count - CycleSize + (iteration - Steps.Count) % CycleSize)].Value;
        }

        public IEnumerable<T> LastPartialCycle(int iteration)
        {
            if (iteration < Steps.Count)
                return Steps.GetRange(0, Steps.Count).Select(x => x.Value);
            else
            {
                int start = Steps.Count - CycleSize;
                int count = (iteration - Steps.Count) % CycleSize;
                return Steps.GetRange ( start , count).Select( x=>x.Value);
            }
        }
    }
    [DebuggerDisplay("{Key}")]
    public class CycleStep<T>
    {
        public CycleStep (T value , int iteration , int key)
        {
            Value = value;
            Iteration = iteration;
            Key = key;

        }
        public T Value
        {
            get;
            set;
        }

        public int Iteration
        {
            get;set;
        }
        public int Key
        {
            get;
            set;
        }

    }
    #endregion cycles


    public abstract class CodeJamProblemA:CodeJamProblem
    {
        public override string ProblemLetter
        {
            get { return "A"; }
        }
    }
    public abstract class CodeJamProblemB : CodeJamProblem
    {
        public override string ProblemLetter
        {
            get { return "B"; }
        }
    }
    public abstract class CodeJamProblemC : CodeJamProblem
    {
        public override string ProblemLetter
        {
            get { return "C"; }
        }
    }
    public abstract class CodeJamProblemD : CodeJamProblem
    {
        public override string ProblemLetter
        {
            get { return "D"; }
        }
    }
    [DebuggerDisplay("{Response}")]
    public abstract class CodeJamProblem
    {
        public CodeJamProblem()
        {
            AllowParallelExecution = false;
            HasSpecificLargeImplementation = true;
        }
        #region conversion related
        internal static CultureInfo cultureInfo = new CultureInfo("en");

        protected static string DoubleToString(double value, int decimalPlaces = -1)
        {
            if (decimalPlaces < 0)
                return value.ToString(cultureInfo);
            else
                return string.Format(cultureInfo, "{0.".PadRight(decimalPlaces + 3, '0') + "}", value);
        }

        protected static CultureInfo CultureInfo
        {
            get
            {
                return cultureInfo;
            }
        }
        protected static string ConvertToBase(long value, int baseToConvertTo, string chars = "0123456789ABCDEF")
        {
            if (value == 0)
                return chars[0].ToString();
            string result = "";
            while (value > 0)
            {
                int index = (int)(value % baseToConvertTo);
                result = chars[index] + result;
                value = value / baseToConvertTo;
            }
            return result;
        }
        #endregion conversion related

        #region auxiliary methods

        protected static T[,] CreateMatrix<T>(int width, int height, T defaultValue)
        {
            T[,] matrix = new T[width, height];
            for (int i = 0; i < width; i++)
                for (int j = 0; j < height; j++)
                    matrix[i, j] = defaultValue;
            return matrix;
        }
        protected static bool CompareArrays<T>(T[] array1, T[] array2)
            where T : IComparable
        {
            if (array1 == null)
                return array2 == null;

            if (array2 == null)
                return false;

            int len1 = array1.Length;
            int len2 = array2.Length;
            if (len1 != len2)
                return false;

            for (int i = 0; i < len1; i++)
            {
                if (array1[i].CompareTo(array2[i]) != 0)
                    return false;
            }
            return true;
        }
        protected static T[] CreateArray <T>(long size)
            where T:class, new()
        {
            if (size < 0)
                return null;
            T[] array = new T[size];
            for (int i = 0; i < size; i++)
                array[i] = new T();
            return array;
        }
        protected static T[] CreateArray<T>(long size, T defaultValue = default(T))
        {
            if (size < 0)
                return null;
            T[] array = new T[size];
            for (int i = 0; i < size; i++)
                array[i] = defaultValue;
            return array;
        }
        protected static T[] CloneArray<T>(T[] array)
        {
            if (array == null)
                return null;
            T[] newArray = new T[array.Length];
            for (int i = 0; i < array.Length; i++)
                newArray[i] = array[i];
            return newArray;
        }
        protected static int Min(params int[] values)
        {
            var min = values[0];
            for (int i = 1; i < values.Length; i++)
                min = Math.Min(min, values[i]);
            return min;
        }
        protected static string Min(params string[] values)
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
        protected static string Max(params string[] values)
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
        protected static long Min(params long[] values)
        {
            var min = values[0];
            for (int i = 1; i < values.Length; i++)
                min = Math.Min(min, values[i]);
            return min;
        }
        protected static int Max(params int[] values)
        {
            var max = values[0];
            for (int i = 1; i < values.Length; i++)
                max = Math.Max(max, values[i]);
            return max;
        }
        protected static long Max(params long[] values)
        {
            var max = values[0];
            for (int i = 1; i < values.Length; i++)
                max = Math.Max(max, values[i]);
            return max;
        }
        #endregion auxiliary methods

        #region debug related methods
        public static string WriteMatrix<T>(T[,] matrix)
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
                    result += aux[j, i].PadRight(maxSize + 1, ' ');
                }
                result += "\r\n";
            }
            return result;
        }

        #endregion debug related methods

        #region algorithms

        protected Cycle<T> FindCyclev2<T>(T initialValue, Func<T, int,T> nextValue, Func<T,int> getKey, int maxKeys = 1000000)
        {
            int[] aux = CreateArray<int>(maxKeys, -1);
            var aux2 = new List<CycleStep<T>>();

            int index = 0;
            var value = initialValue;

            while ( true)
            {
                int key = getKey(value);
                aux2.Add(new CycleStep<T>(value, index, key));
                if ( aux[key] != -1)
                {
                    return new Cycle<T>(aux2, index - aux[key]);
                }
                else
                {
                    aux[key] = index;
                }
                index++;
                value = nextValue(value, index);
            }

        }
        
        protected Cycle<T> FindCycle<T> (T initialValue , Func<T,int,T> nextValue , Func<T,int> getKey , int maxKeys=1000000 )
        {
            var possibleStepSizes = new Dictionary<int,int>();
            var keySteps = CreateArray<List<int>> ( maxKeys );
            var steps = new List<CycleStep<T>>();
            T currentValue = initialValue;
            int currentIteration = 0;
            
            while ( true)
            {
                var key = getKey(currentValue);
                steps.Add( new CycleStep<T>(currentValue, currentIteration, key));

                var previousSteps = keySteps[key];

                var newPossibleStepSizes = new Dictionary<int, int>();
                foreach ( var previousStep in previousSteps)
                {
                    int stepSize = currentIteration - previousStep;
                    int stepSizeDuration;
                    if (possibleStepSizes.TryGetValue(stepSize, out stepSizeDuration))
                    {
                        stepSizeDuration++;
                        if (stepSizeDuration > stepSize)
                            return new Cycle<T>(steps, stepSize);
                        newPossibleStepSizes[stepSize] = stepSizeDuration ;
                    }
                    else
                        newPossibleStepSizes.Add(stepSize, 1);
                }
                possibleStepSizes = newPossibleStepSizes;

                previousSteps.Add(currentIteration);
                currentIteration++;
                currentValue = nextValue(currentValue, currentIteration);
            }

        }
        internal static long Factorial ( long n)
        {
            long total = 1;
            for (int i = 2; i <= n; i++)
                total *= i;
            return total;
        }
        protected long BinomialCoefficient ( long n, long k)
        {
            return Factorial ( n) / (Factorial ( k) * Factorial (n-k)) ;
        }

        protected static T ExecuteAssotiativeOperation<T>(long repetitions, Func<T, T, T> assotiativeFunc, T initialValue)
        {
            string valueAsBool = ConvertToBase(repetitions, 2);

            var finalValue = default(T);
            bool finalValueInitialized = false; ;
            var value = initialValue;
            for (int i = valueAsBool.Length - 1; i >= 0; i--)
            {
                if (valueAsBool[i] == '1')
                {
                    if (!finalValueInitialized)
                    {
                        finalValueInitialized = true;
                        finalValue = value;
                    }
                    else
                        finalValue = assotiativeFunc(finalValue, value);
                }
                value = assotiativeFunc(value, value);
            }
            return finalValue;
        }

        protected long[] PrimesLowerThan(int value)
        {
            if (value <= 1)
                return new long[0];
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

        #endregion algorithms


        public static bool BitIsSet(long bitMask, int bitIndexZeroBased)
        {
            return (bitMask & (((long)1) << bitIndexZeroBased)) > 0;
        }
        public static int BitsCount(long bitMask)
        {
            int count = 0;
            for (int i = 0; ; i++)
            {
                long v = ((long)1) << i;
                if (v > bitMask)
                    return count;
                if ((bitMask & v) > 0)
                    count++;
            }
        }
        public long BinarySearch(long maxValue, Func<long, int> comparison)
        {
            long total = 1;
            while (total < maxValue)
                total *= 2;
            long min = 0;
            long max = total;

            do
            {
                long half = (max + min) / 2;
                if (half == min)
                    return half;
                if (half >= maxValue)
                    return maxValue - 1;
                int comparisonResult = comparison(half);
                if (comparisonResult == 0)
                    return half;
                if (comparisonResult < 0)
                    max = half;
                else
                    min = half;

            }
            while (true);
        }
        public long BinarySearch<T>(T[] sortedArray, T valueToSearch, Func<T, T, int> comparison)
        {
            if (sortedArray.Length == 0)
                return -1;
            long total = 1;
            long count = sortedArray.Length;
            while (total < count)
                total *= 2;
            long min = 0;
            long max = total;

            do
            {
                long half = (max + min) / 2;
                if (half == min)
                    return half;
                if (half >= count)
                    return count - 1;
                int comparisonResult = comparison(valueToSearch, sortedArray[half]);
                if (comparisonResult == 0)
                    return half;
                if (comparisonResult < 0)
                    max = half;
                else
                    min = half;

            }
            while (true);

        }

        protected static long GCD(long a, long b)
        {
            while (b != 0)
            {
                long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        protected static BigInteger GCD(BigInteger a, BigInteger b)
        {
            while (b != 0)
            {
                BigInteger temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        protected static BigInteger GCD(params BigInteger[] values)
        {
            if (values.Length < 2)
                return values[0];
            BigInteger gcd = values[0];
            for (int i = 1; i < values.Length; i++)
                gcd = GCD(gcd, values[i]);

            return gcd;
        }

        protected static long GCD(params  long[] values)
        {
            if (values.Length < 2)
                return values[0];
            long gcd = values[0];
            for (int i = 1; i < values.Length; i++)
                gcd = GCD(gcd, values[i]);

            return gcd;
        }

        protected static long LCM(params long[] values)
        {
            if (values.Length < 2)
                return values[0];
            long lcm = values[0];
            for (int i = 1; i < values.Length; i++)
                lcm = LCM(lcm, values[i]);

            return lcm;
        }
        protected static long LCM(long a, long b)
        {
            return (a / GCD(a, b)) * b;
        }
        public int CaseIndex
        {
            get;
            set;
        }
        public int CaseCount
        {
            get;
            set;
        }

        public virtual bool HasSpecificLargeImplementation
        {
            get;
            set;
        }
        public virtual bool AllowParallelExecution
        {
            get;
            set;
        }

        public string Response
        {
            get;
            private set;
        }

        public double ElapsedMilliseconds
        {
            get;
            private set;
        }

        public abstract string InputSample
        {
            get;
        }

        public abstract string OutputSample
        {
            get;
        }
        public abstract string ProblemLetter
        {
            get;
        }


        public virtual string BuildResponse()
        {
            return string.Format("Case #{0}: {1}\r\n", CaseIndex, Response);
        }
        #region initialization related methods
        public virtual int ReadNumberOfTestCases(FileReader reader)
        {
            return reader.ReadInt();
        }
        public abstract void Read(FileReader r);
        #endregion initialization related methods

        public string Solve(bool useLarge)
        {
            Stopwatch s = new Stopwatch();
            s.Start();
            if (useLarge)
                Response = SolveLarge();
            else
                Response = SolveSmall();
            ElapsedMilliseconds = s.ElapsedMilliseconds;
            return Response;
        }
        protected abstract string SolveSmall();
        protected virtual string SolveLarge()
        {
            HasSpecificLargeImplementation = false;
            return SolveSmall();
        }


    }

    #region autogrow array
    class AutoGrowArray<T>
    {
        T DefaultValue
        {
            get; set;
        }
        public AutoGrowArray(T defaultValue)
        {
            DefaultValue = defaultValue;
        }
        public AutoGrowArray() : this(default(T))
        {

        }
        T[] array = new T[0];
        int max = 0;
        public T this[int index]
        {
            get
            {
                if (index >= max || index < 0)
                    return DefaultValue;
                return array[index];
            }
            set
            {
                if (index < 0)
                    return;
                if (index >= max)
                {
                    int newMax = Length;
                    if (newMax == 0)
                        newMax = 1;
                    while (newMax <= index)
                        newMax *= 2;
                    T[] newArray = new T[newMax];
                    for (int i = 0; i < max; i++)
                        newArray[i] = array[i];
                    for (int i = max; i < newMax; i++)
                        newArray[i] = DefaultValue;
                    array = newArray;
                    max = newMax;
                }
                array[index] = value;
            }
        }

        public int Length
        {
            get
            {
                return array.Length;
            }
        }
    }
    #endregion autogrow array

    #region graphs
    class Graphs
    {
        public class BreadthFirstSearch<T>
           where T : IComparable<T>
        {

            private class Node : IComparable<Node>
            {
                public Node(T value)
                {
                    Value = value;
                }
                public Node(T value, Node parent) : this(value)
                {
                    Parent = parent;
                }
                public T Value
                {
                    get;
                    set;
                }
                public Node Parent
                {
                    get;
                    set;
                }

                public int CompareTo(Node other)
                {
                    return Value.CompareTo(other.Value);
                }
            }

            private List<T> GetEnumerator(Node node, int depth)
            {
                List<T> array;
                if (node.Parent != null)
                    array = GetEnumerator(node.Parent, depth + 1);
                else
                    array = new List<T>();
                array.Add(node.Value);
                return array;
            }
            public IEnumerable<T> ExecuteSearch(T start, Func<T, IEnumerable<T>> connectedNodes, Func<T, bool> isFinal)
            {
                PriorityQueue<Node> queue = new PriorityQueue<Node>();
                var next = new Node(start);
                while (!isFinal(next.Value))
                {
                    foreach (var newNodeValue in connectedNodes(next.Value))
                        queue.Insert(new Node(newNodeValue, next));
                    next = queue.RemoveMin();
                }
                return GetEnumerator(next, 0);
            }
        }
        class Node<T> : IComparable<Node<T>>, IComparable
            where T : INode
        {
            public Node(T value)
            {
                Value = value;
            }
            public Node(T value, Node<T> parent) : this(value)
            {
                Parent = parent;
            }
            public T Value
            {
                get; set;
            }
            public Node<T> Parent
            {
                get; set;
            }
            public int ID
            {
                get
                {
                    return Value.ID;

                }
            }
            public int CompareTo(Node<T> other)
            {
                return Value.CompareTo(other.Value);
            }
            public int CompareTo(object obj)
            {
                return CompareTo(obj as Node<T>);
            }
            public static implicit operator Node<T>(T value)
            {
                return new Node<T>(value);
            }
        }
        public interface INode : IComparable
        {
            int ID
            {
                get;
            }
        }
        public class Dijkstra
        {
            private static List<T> GetSolution<T>(List<T> list, Node<T> lastElement)
                where T : INode
            {
                if (lastElement.Parent != null)
                    GetSolution(list, lastElement.Parent);
                list.Add(lastElement.Value);
                return list;
            }
            private static IEnumerable<T> GetSolution<T>(Node<T> lastElement)
                where T : INode
            {
                return GetSolution(new List<T>(), lastElement);
            }
            public static IEnumerable<T> Search<T>(T start, Func<T, IEnumerable<T>> neighbours, Func<T, bool> isGoal)
                 where T : INode
            {
                var queue = new IndexMinPQ<Node<T>>();
                queue.Insert(start.ID, new Node<T>(start));
                AutoGrowArray<bool> explored = new AutoGrowArray<bool>();
                do
                {
                    var node = queue.DelMin();
                    if (isGoal(node.Value))
                        return GetSolution(node);
                    explored[node.ID] = true;
                    foreach (var neighbour in neighbours(node.Value))
                    {
                        var id = neighbour.ID;
                        if (!explored[id])
                        {
                            if (!queue.Contains(id))
                                queue.Insert(id, new Node<T>(neighbour, node));
                            else
                            {
                                //replace in queue if cost is bigger
                                var key = queue[id];
                                if (key.Value.CompareTo(neighbour) > 0)
                                    queue[id] = new Node<T>(neighbour, node);
                            }

                        }
                    }
                }
                while (true);
            }
        }
    }
    #endregion graphs

    #region priority queues
    /// <summary>
    /// Converted from IndexMinPQ.java by Robert Sedgewick and Kevin Wayne
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class IndexMinPQ<T>
        where T : IComparable
    {
        private int N;           // number of elements on PQ
        private AutoGrowArray<int> pq = new AutoGrowArray<int>(-1);   // binary heap using 1-based indexing
        private AutoGrowArray<int> qp = new AutoGrowArray<int>(-1);        // inverse of pq - qp[pq[i]] = pq[qp[i]] = i
        private AutoGrowArray<T> keys = new AutoGrowArray<T>();        // keys[i] = priority of i

        public IndexMinPQ()
        {
            N = 0;
        }
        public bool IsEmpty()
        {
            return N == 0;
        }
        public bool Contains(int i)
        {
            return qp[i] != -1;
        }
        public int Size()
        {
            return N;
        }
        public void Insert(int i, T key)
        {
            if (Contains(i))
                throw new ArgumentException("index is already in the priority queue");
            N++;
            qp[i] = N;
            pq[N] = i;
            keys[i] = key;
            Swim(N);
        }
        public int MinIndex()
        {
            if (N == 0)
                throw new InvalidOperationException("Priority queue underflow");
            return pq[1];
        }
        public T MinKey()
        {
            if (N == 0)
                throw new InvalidOperationException("Priority queue underflow");
            return keys[pq[1]];
        }
        public T DelMin()
        {
            if (N == 0)
                throw new InvalidOperationException("Priority queue underflow");
            int min = pq[1];
            Exch(1, N--);
            Sink(1);
            qp[min] = -1;               // delete
            var key = keys[min];
            keys[min] = default(T);     // to help with garbage collection
            pq[N + 1] = -1;             // not needed
            return key;
        }
        public T this[int index]
        {
            get
            {
                if (!Contains(index))
                    throw new ArgumentOutOfRangeException("index is not in the priority queue");
                else
                    return keys[index];
            }
            set
            {
                keys[index] = value;
                Swim(qp[index]);
                Sink(qp[index]);
            }
        }
        public void Delete(int i)
        {
            if (!Contains(i))
                throw new ArgumentException("index is not in the priority queue");
            int index = qp[i];
            Exch(index, N--);
            Swim(index);
            Sink(index);
            keys[i] = default(T);
            qp[i] = -1;
        }
        private bool Greater(int i, int j)
        {
            return keys[pq[i]].CompareTo(keys[pq[j]]) > 0;

        }
        private void Exch(int i, int j)
        {
            int swap = pq[i];
            pq[i] = pq[j];
            pq[j] = swap;
            qp[pq[i]] = i;
            qp[pq[j]] = j;
        }
        private void Swim(int k)
        {
            while (k > 1 && Greater(k / 2, k))
            {
                Exch(k, k / 2);
                k = k / 2;
            }
        }
        private void Sink(int k)
        {
            while (2 * k <= N)
            {
                int j = 2 * k;
                if (j < N && Greater(j, j + 1)) j++;
                if (!Greater(k, j)) break;
                Exch(k, j);
                k = j;
            }
        }
    }

    class PriorityQueue<TValue>
        where TValue : IComparable<TValue>
    {
        private TValue[] queue;
        private int n;

        public PriorityQueue(int capacity)
        {
            queue = new TValue[capacity + 1];
            n = 0;
        }
        public PriorityQueue() : this(1)
        { }

        public int Count
        {
            get
            {
                return n;
            }
        }

        public bool IsEmpty()
        {
            return n == 0;
        }

        public TValue min()
        {
            if (IsEmpty())
                return default(TValue);
            return queue[1];
        }

        private void Resize(int capacity)
        {
            if (capacity <= n)
                throw new InvalidDataException();
            TValue[] temp = new TValue[capacity];
            for (int i = 1; i <= n; i++)
                temp[i] = queue[i];
            queue = temp;
        }

        public void Insert(TValue x)
        {
            if (n == queue.Length - 1)
                Resize(2 * queue.Length);

            queue[++n] = x;
            Swim(n);
        }

        private void Swim(int k)
        {
            while (k > 1 && Greater(k / 2, k))
            {
                Exchange(k, k / 2);
                k = k / 2;
            }
        }

        private void Sink(int k)
        {
            while (2 * k <= n)
            {
                int j = 2 * k;
                if (j < n && Greater(j, j + 1)) j++;
                if (!Greater(k, j)) break;
                Exchange(k, j);
                k = j;
            }
        }

        public TValue RemoveMin()
        {
            if (IsEmpty())
                throw new InvalidOperationException("Queue is empty");

            Exchange((int)1, (int)n);
            var min = queue[n--];
            Sink(1);
            queue[n + 1] = default(TValue);
            if ((n > 0) && (n == (queue.Length - 1) / 4))
                Resize(queue.Length / 2);
            return min;
        }

        private bool Greater(int i, int j)
        {
            return queue[i].CompareTo(queue[j]) > 0;
        }

        private void Exchange(int i, int j)
        {
            var swap = queue[i];
            queue[i] = queue[j];
            queue[j] = swap;
        }

        private bool IsMinHeap()
        {
            return IsMinHeap(1);
        }

        private bool IsMinHeap(int k)
        {
            if (k > n) return true;
            int left = 2 * k, right = 2 * k + 1;
            if (left <= n && Greater(k, left)) return false;
            if (right <= n && Greater(k, right)) return false;
            return IsMinHeap(left) && IsMinHeap(right);
        }

    }
    #endregion priority queues


    public class Engine
    {
        #region static methods
        public static bool Solve(Type type , string folder = "c:\\temp\\")
        {
            return new Engine(folder).Solve<int>(type);
        }
        #endregion static methods

        #region fields
        object syncObject = new object();
        #endregion fields

        #region constructors
        private Engine(string folder)
        {
            Folder = folder;
        }

        #endregion constructors

        #region properties
        string Folder
        {
            get;
            set;
        }
        #endregion properties

        private void WriteToConsole(string text, ConsoleColor color)
        {
            lock (syncObject)
            {
                var currentColor = Console.ForegroundColor;
                Console.ForegroundColor = color;
                Console.WriteLine(text);
                Console.ForegroundColor = currentColor;
            }
        }

        private string FirstDifferentLine(string text1, string text2)
        {
            text1 = text1.Replace("\r", "");
            text2 = text2.Replace("\r", "");
            var lines1 = text1.Split('\n');
            var lines2 = text2.Split('\n');
            for (int i = 0; i < lines1.Length && i < lines2.Length; i++)
            {
                if (lines2[i] != lines1[i])
                    return lines1[i];
            }
            if (lines1.Length > lines2.Length)
                return lines1[lines2.Length];
            if (lines1.Length < lines2.Length)
                return lines2[lines1.Length];
            return null;
        }
        int casesSolved;
        int casesToSolve;

        [DebuggerStepThrough]
        private void Solve(CodeJamProblem problem, bool useLarge)
        {
            problem.Solve(useLarge);
            Interlocked.Increment(ref casesSolved);
            lock (syncObject)
            {
                Console.Write(string.Format("\rSolving: {0} of {1}", casesSolved, casesToSolve));
            }
        }
        [DebuggerStepThrough]
        private List<CodeJamProblem> Solve(CodeJamProblem dummyInstance, string inputText, bool useLarge)
        {
            var fileReader = FileReader.CreateFromText(inputText);
            int testCases = dummyInstance.ReadNumberOfTestCases(fileReader);
            List<CodeJamProblem> problemsToSolve = new List<CodeJamProblem>();
            for (int i = 0; i < testCases; i++)
            {
                CodeJamProblem newProblem = Activator.CreateInstance ( dummyInstance.GetType()) as CodeJamProblem;
                newProblem.CaseIndex = i + 1;
                newProblem.CaseCount = testCases;
                newProblem.Read(fileReader);
                problemsToSolve.Add(newProblem);
            }
            casesToSolve = testCases;
            casesSolved = 0;
            if (dummyInstance.AllowParallelExecution)
                Parallel.ForEach(problemsToSolve, x => Solve(x, useLarge));
            else
                foreach (var problem in problemsToSolve)
                    Solve(problem, useLarge);
            Console.Write("\r                      \r");
            return problemsToSolve;
        }
        private string ExecuteTest(CodeJamProblem dummyInstance, string inputText, bool isLarge)
        {
            if (string.IsNullOrEmpty(inputText))
                return "";
            var largeSolutions = Solve(dummyInstance, inputText, true);

            if (!isLarge && largeSolutions.First().HasSpecificLargeImplementation)
            {
                var smallSolutions = Solve(dummyInstance, inputText, false);
                int differences = 0;
                double totalLargeTime = 0;
                double totalSmallTime = 0;
                for (int i = 0; i < largeSolutions.Count; i++)
                {
                    if (largeSolutions[i].Response != smallSolutions[i].Response)
                    {
                        WriteToConsole(string.Format("    Case {0} has different result", i + 1), ConsoleColor.Red);
                        WriteToConsole("        " + smallSolutions[i].Response, ConsoleColor.Gray);
                        WriteToConsole("        " + largeSolutions[i].Response, ConsoleColor.Yellow);
                        differences++;
                    }
                    totalLargeTime += largeSolutions[i].ElapsedMilliseconds;
                    totalSmallTime += smallSolutions[i].ElapsedMilliseconds;
                }

                WriteToConsole(string.Format("    Total execution times:\r\n        Large: {0}ms \r\n        Small: {1}ms", totalLargeTime, totalSmallTime), ConsoleColor.Green);
                if (differences > 0)
                {
                    Console.ReadLine();
                    return null;
                }
            }
            string result = "";
            foreach (var solution in largeSolutions)
                result += solution.BuildResponse();
            return result.Trim();
        }
        [DebuggerStepThrough]
        int CompareFiles(string file1, string file2)
        {
            bool isLarge1 = file1.ToLowerInvariant().Contains("-large");
            bool isLarge2 = file2.ToLowerInvariant().Contains("-large");
            if (isLarge1 != isLarge2)
                return isLarge1 ? 1 : -1;
            else
                return file1.CompareTo(file2);
        }
        [DebuggerStepThrough]
        private string[] GetProblemFiles<T>(T problem)
            where T : CodeJamProblem
        {
            string fileName = string.Format("{0}-*.in", problem.ProblemLetter);
            var files = new List<string>(Directory.GetFiles(Folder, fileName, SearchOption.TopDirectoryOnly));
            files.Sort(CompareFiles);
            return files.ToArray();
        }
        [DebuggerStepThrough]
        private bool Solve<T>(Type type)
        {
            Stopwatch s = Stopwatch.StartNew();
            CodeJamProblem dummyInstance = Activator.CreateInstance (type) as CodeJamProblem;
            WriteToConsole(string.Format("Processing sample"), ConsoleColor.Gray);
            var result = ExecuteTest(dummyInstance, dummyInstance.InputSample, false);
            if ( dummyInstance.InputSample.Trim ().Length == 0)
                WriteToConsole ( "Warning: no samples defined", ConsoleColor.Yellow);
            var outputSample =dummyInstance.OutputSample.Replace ( "\r\n Case" , "\r\nCase").Trim("\r\n ".ToCharArray ());
            if (result != outputSample)
            {
                WriteToConsole("Result is different than expected:", ConsoleColor.Red);
                string firstDifference = FirstDifferentLine(result, outputSample);
                string firstDifference2 = FirstDifferentLine(outputSample, result);
                WriteToConsole("    " + firstDifference, ConsoleColor.Yellow);
                WriteToConsole("    " + firstDifference2, ConsoleColor.Gray);
                Console.ReadLine();
                return false;
            }
            else
                WriteToConsole("    Result matches", ConsoleColor.Green);
            string[] inputFiles = GetProblemFiles(dummyInstance);
            foreach (var inputFile in inputFiles)
            {
                string inputText = File.ReadAllText(inputFile);
                string outputFile = inputFile.Replace(".in", ".out.txt");
                string outputText = null;
                if (File.Exists(outputFile))
                    outputText = File.ReadAllText(outputFile);
                WriteToConsole("", ConsoleColor.Gray);
                WriteToConsole(string.Format("Processing file {0}", Path.GetFileName(inputFile)), ConsoleColor.Gray);
                result = ExecuteTest(dummyInstance, inputText, inputFile.ToLowerInvariant().Contains("-large"));
                if (result == null)
                    return false;
                if (outputText != null && result != outputText)
                {
                    WriteToConsole(string.Format("Result is different for file {0}. Overwrite (Y/N)?", Path.GetFileName(inputFile)), ConsoleColor.Yellow);
                    if (Console.ReadLine().ToLowerInvariant() == "y")
                    {
                        File.WriteAllText(outputFile, result);
                    }
                }
                else
                {
                    if (!File.Exists(outputFile))
                    {
                        File.WriteAllText(outputFile, result);
                        WriteToConsole("Generated file " + outputFile, ConsoleColor.Green);
                    }
                    else
                        WriteToConsole("File already existed: " + outputFile, ConsoleColor.Green);
                }
            }

            
            File.Copy ( string.Format ( "{0}\\program.cs" , 
                            Path.GetDirectoryName( Path.GetDirectoryName( Path.GetDirectoryName( GetType().Assembly.Location)))),
                        string.Format ( "{0}\\program.cs" , Folder), true
                );
            
            
            WriteToConsole(string.Format ( "\r\nSolved in {0}ms. Press enter to continue.", s.ElapsedMilliseconds), ConsoleColor.Green);
            Console.ReadLine();
            return true;
        }

    }

    #endregion base problem resolution framework

    class Problem : CodeJamProblemB
    {
        public override string InputSample
        {
            get
            {
                return @"4
1? 2?
?2? ??3
? ?
?5 ?0";
            }
        }

        public override string OutputSample
        {
            get
            {
                return @"Case #1: 19 20
Case #2: 023 023
Case #3: 0 0
Case #4: 05 00";
            }
        }

        string C;
        string J;
        int N;

        public override void Read(FileReader r)
        {
            C = r;
            J = r;
            N = C.Length;
        }


        private void FirstIsBigger ( out bool max1 , out bool max2)
        {
            for (int i = 0; i < C.Length; i++)
            {
                if (C[i] != '?' && J[i] != '?' && C[i] != J[i])
                {
                    var diff = ((int)C[i]) - ((int)J[i]);
                    if (Math.Abs(diff) == 5 || diff == 0)
                    {
                    }
                    else
                    {
                        if (Math.Abs(diff) <4 )
                        {
                            max1 = false;
                            max2 = true;
                        }
                        else
                        {
                            max1 = true;
                            max2 = false;
                        }
                        return;
                    }
                }
            }
            max1 = false;
            max2 = false;
        }

        private List<string> All(string s)
        {
            List<string> cs = new List<string>();
            if ( s.Length == 0)
                return new List<string>(new string[] { "" });
            for ( int i = 0; i < 1 ; i++)
            {
                if ( s[i] == '?')
                {
                    var aux = All(s.Substring(i + 1));
                    for ( int j = 0; j < 10; j++)
                    {
                        foreach ( var a in aux)
                        {
                            cs.Add(j.ToString() + a);
                        }
                    }
                }
                else
                {
                    var aux = All(s.Substring(i + 1));
                    foreach (var a in aux)
                    {
                        cs.Add(s[i] + a);
                    }
                }
            }
            return cs;
        }

        class Aux : IComparable
        {

            public int C
            {
                get;
                set;
            }
            public int J
            {
                get;
                set;
            }

            public int CompareTo(object obj)
            {
                var o = obj as Aux;
                int compare = Math.Abs ( C - J).CompareTo ( Math.Abs ( o.C - o.J));
                if ( compare != 0)
                    return compare;

                compare = C.CompareTo(o.C);
                if (compare != 0)
                    return compare;

                return J.CompareTo(o.J);

            }
        }
        protected override string SolveSmall()
        {
            List<Aux> all = new List<Aux> ();
            var allCs = All(C);
            var allJs = All(J);
            foreach (var c in allCs)
                foreach (var j in allJs)
                    all.Add(new Aux()
                        {
                            C = int.Parse (c),
                            J = int.Parse (j),
                        });

            all.Sort();

            return string.Format("{0} {1}", all[0].C.ToString().PadLeft(C.Length, '0'), all[0].J.ToString().PadLeft(C.Length, '0'));
        }

        class Aux2
        {
            public string C
            {
                get;
                set;
            }
            public string J
            {
                get;
                set;
            }

            public BigInteger Diff
            {
                get;
                set;
            }

            public int CompareTo(object obj)
            {
                var o = obj as Aux2;
                int compare = Diff.CompareTo(o.Diff);
                if (compare != 0)
                    return compare;

                compare = C.CompareTo(o.C);
                if (compare != 0)
                    return compare;

                return J.CompareTo(o.J);

            }
        }
        void Solve ( int i , bool? isBigger, string v1 , string v2, ref Aux2 bestSolution)
        {
            if ( i == N)
            {
                var b = BigInteger.Parse ( v1) - BigInteger.Parse ( v2);;
                if ( b < 0)
                    b = -b;
                Aux2 o = new Aux2 ()
                {
                    C = v1,
                    J = v2,
                    Diff = b
                };
                if ( bestSolution == null || bestSolution.CompareTo ( o) > 0)
                {
                    bestSolution = o;
                }
                return ;
            }

            if (C[i] == J[i])
            {
                if ( C[i] == '?')
                {
                    Solve ( i+1 , isBigger , v1 + "0" , v2 +"0" , ref bestSolution);

                    if ( isBigger != null)
                    {
                        if ( isBigger.Value)
                            Solve ( i+1 , isBigger , v1 + "0" , v2 +"9" , ref bestSolution);
                        else
                            Solve ( i+1 , isBigger , v1 + "9" , v2 +"0" , ref bestSolution);
                    }
                    else
                    {
                        Solve(i + 1, false, v1 + "0", v2 + "1", ref bestSolution);
                        Solve(i + 1, true, v1 + "1", v2 + "0", ref bestSolution);
                    }

                }
                else
                {
                    Solve ( i+1 , isBigger , v1 + C[i] , v2 + C[i] , ref bestSolution);
                }
            }
            else
            {
                if (C[i] == '?')
                {
                    if (isBigger == null)
                    {
                        Solve(i + 1, isBigger, v1 + J[i], v2 + J[i], ref bestSolution);
                        if ( J[i] != '0')
                            Solve(i + 1, false, v1 + (char)(J[i]-1), v2 + J[i], ref bestSolution);
                        if (J[i] != '9')
                            Solve(i + 1, true, v1 + (char)(J[i] +1), v2 + J[i], ref bestSolution);

                    }
                    else
                    {
                        if ( isBigger.Value)
                            Solve(i + 1, isBigger, v1 + "0", v2 + J[i], ref bestSolution);
                        else
                            Solve(i + 1, isBigger, v1 + "9", v2 + J[i], ref bestSolution);
                    }
                }
                else
                    if (J[i] == '?')
                    {
                        if (isBigger == null)
                        {
                            Solve(i + 1, isBigger, v1 + C[i], v2 + C[i], ref bestSolution);
                            if (C[i] != '0')
                                Solve(i + 1, true, v1 + C[i], v2 + (char)(C[i] - 1), ref bestSolution);
                            if (C[i] != '9')
                                Solve(i + 1, false, v1 + C[i], v2 + (char)(C[i] + 1), ref bestSolution);
                        }
                        else
                        {
                            if (isBigger.Value)
                                Solve(i + 1, isBigger, v1 + C[i], v2 + "9", ref bestSolution);
                            else
                                Solve(i + 1, isBigger, v1 +  C[i], v2+ "0", ref bestSolution);
                        }
                    }
                    else
                    {
                        if (isBigger == null)
                            isBigger = C[i] > J[i];
                        Solve(i + 1, isBigger, v1 + C[i], v2 + J[i], ref bestSolution);
                    }
            }
        }

        protected override string SolveLarge()
        {
         
            Aux2 aux = null;
            Solve(0, null, "", "", ref aux);
           
            return string.Format ( "{0} {1}", aux.C , aux.J);
        }
    }

    
  
    class Program
    {
        static void Main(string[] args)
        {
            foreach ( var type in typeof ( Program ).Assembly.GetTypes())
            {
                if (!type.IsAbstract && type.IsSubclassOf(typeof(CodeJamProblem)) && type.Namespace == typeof(Program).Namespace)
                {
                    Engine.Solve(type);
                    return;
                }
            }
        }
    }

}

