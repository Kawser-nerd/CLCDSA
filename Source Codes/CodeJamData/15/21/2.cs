using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CodeJam
{
    #region base problem resolution framework
    [DebuggerDisplay("({X},{Y})")]
    public struct Vector
    {
        public Vector(long x, long y)
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

        public static Vector operator + ( Vector v1 , Vector v2)
        {
            return new Vector(v1.X + v2.X, v1.Y + v2.Y);
        }
        public static Vector operator -(Vector v1, Vector v2)
        {
            return new Vector(v1.X - v2.X, v1.Y - v2.Y);
        }

        public static Vector operator -(Vector v1)
        {
            return new Vector(-v1.X , -v1.Y );
        }
    }

    
    public class FileReader
    {

        private FileReader ( string text)
        {
            Content = text;
        }
        public string Content
        {
            get;
            set;
        }

        public string ReadLineAsString ()
        {
            int pos = Content.IndexOfAny("\r\n".ToCharArray ());
            if ( pos == -1)
            {
                var result = Content;
                Content = "";
                return result;
            }
            else
            {
                var result = Content.Substring(0, pos);
                Content = Content.Substring(pos ).Trim();
                return result;
            }
        }

        public long[,] ReadMatrix ( int size)
        {
            long[,] matrix= null;
            for ( int i =0 ; i < size ; i++)
            {
                var v = ReadSpaceSeparatedLongs();
                if ( matrix == null)
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
            string value = ReadLineAsString ();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] result = new int[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = int.Parse(values[i]);
            return result;
        }
        public string[] ReadSpaceSeparatedStrings()
        {
            string value = ReadLineAsString ();
            return value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        }
        public long[] ReadSpaceSeparatedLongs()
        {
            string value = ReadLineAsString ();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            long[] result = new long[values.Length];
            for (long i = 0; i < values.Length; i++)
                result[i] = long.Parse(values[i]);
            return result;
        }

        public double[] ReadSpaceSeparatedDoubles()
        {
            string value = ReadLineAsString ();
            string[] values = value.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            double[] result = new double[values.Length];
            for (int i = 0; i < values.Length; i++)
                result[i] = double.Parse(values[i], CodeJamProblem.cultureInfo);
            return result;
        }

        public int ReadLineAsInt()
        {
            return int.Parse(ReadLineAsString ());
        }
        public long ReadLineAsLong()
        {
            return long.Parse(ReadLineAsString ());
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

            int pos = Content.IndexOfAny(" \r\n".ToCharArray ());
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
        public  int ReadInt()
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

        protected double ReadDouble()
        {
            return ReadValue<double>(x => double.Parse(x, CodeJamProblem.cultureInfo));
        }

        
        public static FileReader CreateFromText ( string text )
        {
            return new FileReader(text);
        }
    }

    [DebuggerDisplay("{Response}")]
    public abstract class CodeJamProblem
    {
        public CodeJamProblem ()
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


        public static bool BitIsSet ( long bitMask, int bitIndexZeroBased)
        {
            return (bitMask & (((long)1) << bitIndexZeroBased))>0;
        }
        public static int BitsCount ( long bitMask)
        {
            int count = 0;
            for ( int i = 0 ; ; i++)
            {
                long v = ((long)1) << i;
                if (v > bitMask)
                    return count;
                if ((bitMask & v) > 0)
                    count++;
            }
        }
        public long BinarySearch ( long maxValue , Func<long, int>comparison)
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
        public long BinarySearch<T> (T[] sortedArray , T valueToSearch, Func<T,T,int> comparison)
        {
            if ( sortedArray.Length == 0)
                return -1;
            long total = 1;
            long count = sortedArray.Length;
            while (total < count)
                total *= 2;
            long min = 0;
            long max = total;

            do
            {
                long half = (max + min)/2;
                if ( half == min)
                    return half;
                if (half >= count)
                    return count - 1;
                int comparisonResult = comparison ( valueToSearch , sortedArray [half]);
                if ( comparisonResult == 0)
                    return half;
                if ( comparisonResult < 0)
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

        protected static long GCD(params  long[] values)
        {
            if (values.Length < 2)
                return values[0];
            long gcd = values[0];
            for (int i = 1; i < values.Length; i++)
                gcd = GCD(gcd, values[i]);
                
            return gcd;
        }

        protected static long LCM ( params long[] values)
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


        public virtual string BuildResponse ()
        {
            return string.Format("Case #{0}: {1}\r\n", CaseIndex, Response);
        }
        #region initialization related methods
        public virtual int ReadNumberOfTestCases(FileReader reader)
        {
            return reader.ReadInt();
        }
        public abstract void Read(FileReader reader);
        #endregion initialization related methods

        public string Solve ( bool useLarge)
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
            return SolveSmall ();
        }


    }

    public class Engine
    {
        #region static methods
        public static bool Solve<T>(string folder = "c:\\temp\\")
            where T : CodeJamProblem, new()
        {
            return new Engine(folder).Solve<T>();
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

        private void WriteToConsole ( string text, ConsoleColor color)
        {
            lock ( syncObject )
            {
                var currentColor = Console.ForegroundColor;
                Console.ForegroundColor = color;
                Console.WriteLine(text);
                Console.ForegroundColor = currentColor;
            }
        }

        private string FirstDifferentLine ( string text1 , string text2)
        {
            text1 = text1.Replace ( "\r", "");
            text2 = text2.Replace ( "\r", "");
            var lines1 = text1.Split('\n');
            var lines2 = text2.Split('\n');
            for ( int i = 0; i < lines1.Length && i < lines2.Length ; i++)
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
        private void Solve ( CodeJamProblem  problem , bool useLarge)
        {
            problem.Solve(useLarge);
            Interlocked.Increment(ref casesSolved);
            lock ( syncObject )
            {
                Console.Write(string.Format ( "\rSolving: {0} of {1}" , casesSolved , casesToSolve ));
            }
        }
        private List<T> Solve <T> ( T dummyInstance , string inputText , bool useLarge )
            where T: CodeJamProblem , new()
        {
            var fileReader = FileReader.CreateFromText(inputText);
            int testCases = dummyInstance.ReadNumberOfTestCases(fileReader );
            List<T> problemsToSolve = new List<T> ();
            for ( int i = 0; i< testCases ; i++)
            {
                T newProblem = new T();
                newProblem.CaseIndex = i+1;
                newProblem.CaseCount = testCases;
                newProblem.Read ( fileReader);
                problemsToSolve .Add ( newProblem );
            }
            casesToSolve = testCases;
            casesSolved = 0;
            if ( dummyInstance.AllowParallelExecution )
                Parallel.ForEach ( problemsToSolve,x=>Solve ( x,useLarge ));
            else
                foreach ( var problem in problemsToSolve)
                    Solve(problem, useLarge);
            Console.Write("\r                      \r");
            return problemsToSolve ;
        }
        private string ExecuteTest <T>( T dummyInstance , string inputText , bool isLarge)
            where T: CodeJamProblem , new()
        {
            var largeSolutions = Solve ( dummyInstance , inputText, true);

            if (!isLarge && largeSolutions.First ().HasSpecificLargeImplementation)
            {
                var smallSolutions = Solve ( dummyInstance , inputText, false);
                int differences = 0;
                double totalLargeTime = 0;
                double totalSmallTime = 0;
                for ( int i =0 ; i < largeSolutions.Count ; i++)
                {
                    if ( largeSolutions[i].Response != smallSolutions[i].Response)
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
                if ( differences > 0 )
                {
                    Console.ReadLine();
                    return null;
                }
            }
            string result = "";
            foreach (var solution in largeSolutions)
                result += solution.BuildResponse();
            return result.Trim ();
        }

        int CompareFiles ( string file1 , string file2)
        {
            bool isLarge1 = file1.ToLowerInvariant().Contains("-large");
            bool isLarge2 = file2.ToLowerInvariant().Contains("-large");
            if (isLarge1 != isLarge2)
                return isLarge1 ? 1 : -1;
            else
                return file1.CompareTo(file2);
        }
        private string[] GetProblemFiles<T> ( T problem)
            where T: CodeJamProblem
        {
            string fileName = string.Format("{0}-*.in", problem.ProblemLetter);
            var files = new List<string>(Directory.GetFiles(Folder, fileName, SearchOption.TopDirectoryOnly));
            files.Sort(CompareFiles);
            return files.ToArray ();
        }
        private bool Solve<T>()
            where T: CodeJamProblem , new()
        {
            T dummyInstance = new T();
            WriteToConsole(string.Format("Processing sample"), ConsoleColor.Gray);
            var result = ExecuteTest<T>(dummyInstance,dummyInstance.InputSample, false);
            if (result != dummyInstance.OutputSample)
            {
                WriteToConsole("Result is different than expected:", ConsoleColor.Red);
                string firstDifference = FirstDifferentLine(result, dummyInstance.OutputSample);
                string firstDifference2 = FirstDifferentLine(dummyInstance.OutputSample, result);
                WriteToConsole("    " + firstDifference, ConsoleColor.Yellow);
                WriteToConsole("    " + firstDifference2, ConsoleColor.Gray);
                Console.ReadLine();
                return false;
            }
            else
                WriteToConsole("    Result matches", ConsoleColor.Green);
            string[] inputFiles = GetProblemFiles( dummyInstance );
            foreach ( var inputFile in inputFiles)
            {
                string inputText = File.ReadAllText(inputFile);
                string outputFile = inputFile.Replace(".in", ".out.txt");
                string outputText = null;
                if (File.Exists(outputFile))
                    outputText = File.ReadAllText(outputFile);
                WriteToConsole("", ConsoleColor.Gray);
                WriteToConsole(string.Format ( "Processing file {0}", Path.GetFileName (inputFile)) , ConsoleColor.Gray);
                result = ExecuteTest<T>(dummyInstance, inputText, inputFile.ToLowerInvariant().Contains("-large"));
                if (result == null)
                    return false;
                if ( outputText != null && result != outputText )
                {
                    WriteToConsole(string.Format ("Result is different for file {0}. Overwrite (Y/N)?", Path.GetFileName ( inputFile )), ConsoleColor.Yellow);
                    if ( Console.ReadLine ().ToLowerInvariant () == "y")
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
            WriteToConsole("\r\nSolved. Press enter to continue.", ConsoleColor.Green);
            Console.ReadLine();
            return true;
        }
        
    }
    #endregion base problem resolution framework

    class CounterCulture : CodeJamProblem
    {

        public override string InputSample
        {
            get
            {
                return @"3
1
19
23";
            }
        }

        public override string OutputSample
        {
            get
            {
                return @"Case #1: 1
Case #2: 19
Case #3: 15";
            }
        }

        public override string ProblemLetter
        {
            get { return "A"; }
        }

        long N;
        public override void Read(FileReader reader)
        {
            N = reader.ReadLong();
        }

        private long Reverse(long number)
        {
            long total = 0;
            while (number > 0)
            {
                total = 10 * total + number % 10;
                number = number / 10;
            }
            return total;
        }
        private long Count(long[] alreadySaid, long currentNumber, long currentCount)
        {
            if (currentNumber == N)
            {
                if (alreadySaid[currentNumber] > currentCount || alreadySaid[currentNumber] == -1)
                    alreadySaid[currentNumber] = currentCount;
                return currentCount;
            }
            alreadySaid[currentNumber] = currentCount;
            long next = currentNumber + 1;
            long reverse = Reverse(currentNumber);
            long min = long.MaxValue;
            if (next <= N && !(alreadySaid[next] > 0 && alreadySaid[next] <= currentCount))
                min = Min(min, Count(alreadySaid, next, currentCount + 1));
            if (reverse <= N && !(alreadySaid[reverse] > 0 && alreadySaid[reverse] <= currentCount))
                min = Min(min, Count(alreadySaid, reverse, currentCount + 1));
            return min;
        }

        private long SolveFast (long n, long currentCount)
        {
            int nDigits = n.ToString().Length;
            nDigits = nDigits / 2;
            long total = 1;
            for ( int i = 0; i < nDigits; i++)
            {
                
                int digit =(int)( (n/ total ) % 10);
                if (i == 0)
                    digit = digit == 0 ? 9 : digit - 1;
                currentCount += digit * total;
                
                n -= digit* total;
                total *= 10;
            }
            if ( n != 1 )
            {
                var n2 = Reverse(n);
                if ( n2 != n)
                    currentCount++;
                n = n2;
                var newN = long.Parse("1".PadRight(n.ToString().Length, '0'));
                currentCount += n - newN;
                n = newN;
                return SolveFast(n, currentCount);
            }
            return currentCount;
        }
        protected override string SolveSmall()
        {
            var res =  SolveFast((long)N, (long)0);
            res++;
            return res.ToString();
        }
    }
    class Program
    {
        
        static void Main(string[] args)
        {
            Engine.Solve<CounterCulture>();
            
        }
    }

}

