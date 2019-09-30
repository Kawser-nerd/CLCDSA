namespace ConsoleApplication1
{
    using System.Collections;
    using System.IO;

    class IO
    {
        StreamReader sr; StreamWriter sw; IEnumerator e = new string[0].GetEnumerator();
        public IO(string name) { sr = File.OpenText(name + ".in"); sw = File.CreateText(name + ".out"); sw.AutoFlush = true; }
        public void Write(string s) { sw.Write(s); }
        public void WriteLine(string s) { sw.WriteLine(s); }
        public string ReadLine() { return sr.ReadLine(); }
        public string GetNext() { if (!e.MoveNext()) (e = this.ReadLine().Split(new char[] { ' ' }).GetEnumerator()).MoveNext(); return (string)e.Current; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IO io = new IO("B-large");

            int T = int.Parse(io.GetNext());

            for (int t = 1; t <= T; t++)
            {
                string s = "0" + io.GetNext();

                for (int i = s.Length - 2; i >= 0; i--)
                {
                    int min = -1;
                    for (int j = i + 1; j < s.Length; j++)
                        if (s[i] < s[j] && (min < 0 || s[j] < s[min]))
                            min = j;

                    if (min > 0)
                    {
                        s = s.Substring(0, i) + s[min] + s.Substring(i + 1, min - i - 1) + s[i] + s.Substring(min + 1);

                        for (int j = i + 1; j < s.Length; j++)
                            for (int k = j + 1; k < s.Length; k++)
                                if (s[j] > s[k])
                                    s = s.Substring(0, j) + s[k] + s.Substring(j + 1, k - j - 1) + s[j] + s.Substring(k + 1);
                        break;
                    }
                }

                io.WriteLine("Case #" + t + ": " + (s[0] == '0' ? s.Substring(1) : s));
            }
        }
    }
}
