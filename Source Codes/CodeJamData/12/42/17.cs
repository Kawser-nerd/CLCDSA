using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



#region Hide
static public class Serializer
{
    static public void SerializeObject(string filename, object

objectToSerialize)
    {
        Stream stream = File.Open(filename, FileMode.Create);
        BinaryFormatter bFormatter = new BinaryFormatter();
        bFormatter.Serialize(stream, objectToSerialize);
        stream.Close();
    }

    static public object DeSerializeObject(string filename)
    {
        object objectToSerialize;
        Stream stream = File.Open(filename, FileMode.Open);
        BinaryFormatter bFormatter = new BinaryFormatter();
        objectToSerialize =
           (object)bFormatter.Deserialize(stream);
        stream.Close();
        return objectToSerialize;
    }
}

class Reader : System.IO.StreamReader
{


    public Reader(string path) : base(path) { }

    public long Readlong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public long ReadLong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public char ReadChar()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        return (char)this.Read();
    }
    public string ReadWord()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        while (!this.EndOfStream && char.IsWhiteSpace((char)this.Peek()))
        {
            this.Read();
        }
        StringBuilder sb = new StringBuilder();

        while (!this.EndOfStream && !char.IsWhiteSpace((char)this.Peek()))
        {
            sb.Append((char)this.Read());
        }
        return sb.ToString();
    }
}
#endregion


class Program
{
    class G : IComparable<G>
    {
        public long R;
        public int ind;
        public G(long r, int i)
        {
            R = r; ind = i;
        }

        int IComparable<G>.CompareTo(G other)
        {
            return R.CompareTo(other.R);
        }
    }

    class P
    {
        public long x, y;
        public P(long X, long Y)
        {
            x = X; y = Y;
        }
    }

    static void Main(string[] args)
    {
        Reader sr = new Reader("C:\\test\\in.in");
        StreamWriter sw = new StreamWriter("C:\\test\\out.out");
        sw.AutoFlush = true;
        long n = long.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (long i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }

    static List<long> X = new List<long>();
    static List<long> Y = new List<long>();
    static G[] A;
    static bool GOod(long x, long y, long r)
    {
        for (int i = 0; i < X.Count; i++)
        {
            if (Math.Abs(X[i] - x) >= A[i].R + r ||
                Math.Abs(Y[i] - y) >= A[i].R + r)
            {
            }
            else
                return false;
        }
        return true;
    }

    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        long N = long.Parse(t[0]);
        long W = long.Parse(t[1]);
        long H = long.Parse(t[2]);
        bool B = false;
        if (H > W)
        {
            B = true;
            long q = H;
            H = W;
            W = q;
        }
        t = sr.ReadLine().Split(' ');
        A = new G[N];

        for (int i = 0; i < N; i++)
        {
            A[i] = new G(long.Parse(t[i]), i);
        }
        Array.Sort(A);
        Array.Reverse(A);
        X.Clear();
        Y.Clear();
        List<P> roof = new List<P>();
        List<P> next = new List<P>();

        roof.Add(new P(W, -A[0].R));
        long r = 0;
        X.Add(0);
        Y.Add(0);
        for (long rr = 1; rr < N; rr++)
        {
            G j = A[rr];

            /*  plac:
                  while (r < roof.Count && roof[r].y + j.R > H)
                  {
                      r++;
                  }

                  if (r == roof.Count)
                  {
                      next.Add(new P(W, next[next.Count - 1].y));
                      roof = next;
                      roof = new List<P>();
                      r = 0;
                      goto plac;
                  }

                  if (next.Count == 0)
                  {
                      long y = Math.Max(0, roof[r].y + j.R);
                      long x;
                      if (r == 0)
                          x = 0;
                      else
                          x = roof[r - 1].x + j.R;
                      X.Add(x);
                      Y.Add(y);
                      next.Add(new P(x + j.R, y + j.R));
                      continue;
                  }

                  {
                      long x = next[next.Count - 1].x + j.R;
                      if (x > W)
                      {
                          next.Add(new P(W, next[next.Count - 1].y));
                          roof = next;
                          roof = new List<P>();
                          r = 0;
                          goto plac;
                      }
                      while (r < roof.Count-1 && roof[r].x < x-j.R)
                          r++;
                      long y = Math.Max(0, roof[r].y + j.R);
                      next.Add(new P(x + j.R, y + j.R));

                      X.Add(x);
                      Y.Add(y);
                      continue;

                  }*/

            bool b = false;
            for (int i = 0; i < X.Count; i++)
            {
                long x = X[i] + A[i].R + j.R;
                long y = Y[i];
                if (y <= H && x <= W && GOod(x, y, j.R))
                {
                    X.Add(x);
                    Y.Add(y);
                    break;
                }
                x = X[i];
                y = Y[i] + A[i].R + j.R;
                if (y <= H && x <= W && GOod(x, y, j.R))
                {
                    X.Add(x);
                    Y.Add(y);
                    break;
                }

                x = X[i] + A[i].R + j.R;
                y = Y[i] + A[i].R + j.R;
                if (y <= H && x <= W && GOod(x, y, j.R))
                {
                    X.Add(x);
                    Y.Add(y);
                    break;
                }
            }



        }








        if (B)
        {
            List<long> V = Y;
            Y = X;
            X = V;
        }

        int[] rev = new int[N];
        for (int i = 0; i < N; i++)
        {
            rev[A[i].ind] = i;
        }
        string ret = "";

        for (int i = 0; i < N; i++)
        {
            int j = rev[i];
            ret += " " + X[j].ToString() + ".0 " + Y[j].ToString() + ".0";
        }


        return ret.Substring(1);
    }
}
