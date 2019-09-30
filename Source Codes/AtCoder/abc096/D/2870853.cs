using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using static System.Console;
using static PB10004.Algorithm.Util;

namespace PB10004.Algorithm
{
    class Template
    {
        static void Main(string[] args)
        {
            new ABC096D().Solve();
        }
    }
    public class ABC096D{
        public void Solve(){
            var N = ReadInt();
            var stack = new Queue<int[]>();
            var primes = Enumerable.Range(2,55555).Where(x=>IsPrime(x) && x % 5 == 1).ToArray().Take(N);
            WriteLine(string.Join(" ", primes));
        }
        public bool IsPrime(int n){
            for(int i=2;i<=Math.Sqrt(n);i++){
                if(n%i==0){
                    return false;
                }
            }
            return true;
        }
    }
    public static class Util
    {
        /// <summary>
        /// ?????int???????
        /// </summary>
        /// <returns></returns>
        public static int ReadInt(){
            return int.Parse(ReadLine());
        }
        /// <summary>
        /// ?????int???????
        /// </summary>
        /// <returns></returns>
        public static int[] ReadIntArray(){
            return ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();
        }
        /// <summary>
        /// ?????long???????
        /// </summary>
        /// <returns></returns>
        public static long ReadLong()
        {
            return long.Parse(ReadLine());
        }
        /// <summary>
        /// ?????long???????
        /// </summary>
        /// <returns></returns>
        public static long[] ReadLongArray()
        {
            return ReadLine().Split(' ').Select(long.Parse).ToArray();
        }
        /// <summary>
        /// ???????????
        /// </summary>
        /// <param name="value"></param>
        /// <param name="length"></param>
        /// <returns></returns>
        public static IEnumerable<long> ConstSeq(long value, long length)
        {
            for (int i = 0; i < length; i++)
            {
                yield return value;
            }
        }
        /// <summary>
        /// int??????????
        /// </summary>
        /// <param name="array"></param>
        /// <returns></returns>
        public static IEnumerable<int> CumulativeSum(IEnumerable<int> array)
        {
            int tmp = 0;
            foreach (var num in array)
                yield return tmp += num;
        }
        /// <summary>
        /// long??????????
        /// </summary>
        /// <param name="array"></param>
        /// <returns></returns>
        public static IEnumerable<long> CumulativeSum(IEnumerable<long> array)
        {
            long tmp = 0;
            foreach (var num in array)
                yield return tmp += num;
        }
        /// <summary>
        /// ????????????????????
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static long Gcd(long a, long b)
        {
            return b == 0 ? a : Gcd(b, a % b);
        }
        /// <summary>
        /// ?????????
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static long Lcm(long a, long b)
        {
            return a * b / Gcd(a, b);
        }
    }
}