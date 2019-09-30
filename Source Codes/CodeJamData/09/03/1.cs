using System.IO;

namespace WelcomeToCodeJam
{
    class Program
    {
//        private const string PATTERN = "we";
        private const string PATTERN = "welcome to code jam";
        private const int MOD = 10000;

        static void Main(string[] args)
        {
            int n = PATTERN.Length;

            using (TextWriter tw = new StreamWriter(@"D:\Downloads\output.txt"))
            using (TextReader tr = new StreamReader(@"D:\Downloads\C-large.in"))
            {
                int cases = int.Parse(tr.ReadLine());
                for (int no = 1; no<=cases; ++no)
                {
                    string test = tr.ReadLine();
                    int m = test.Length;
                    int[,] a = new int[n+1, m+1];
                    for (int i = 0; i <= m; ++i) a[0, i] = 1;

                    for (int i = 1; i <= n; ++i)
                    {
                        for (int j = 1; j<=m; ++j)
                        {
                            if (PATTERN[i-1] == test[j-1])
                            {
                                a[i, j] = (a[i - 1, j - 1] + a[i, j - 1]) % MOD;
                            }
                            else
                            {
                                a[i, j] = a[i, j - 1];
                            }
                        }
                    }

                    int ans = a[n, m] % MOD;

                    string ansstr = (ans + MOD).ToString().Substring(1);
                    tw.WriteLine("Case #{0}: {1}", no, ansstr);
                }
                
            }

        }
    }
}
