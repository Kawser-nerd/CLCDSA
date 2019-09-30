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

    public int ReadInt()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        int r = 0;
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

    class F : IComparable<F>
    {
        public double P;
        public int V;

        #region IComparable<F> Members

        int IComparable<F>.CompareTo(F other)
        {
            return P.CompareTo(other.P);
        }

        #endregion
    }

    static void Main(string[] args)
    {
        Reader sr = new Reader("F:\\test\\in.in");
        StreamWriter sw = new StreamWriter("F:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        long C = int.Parse(t[0]);
        double D = int.Parse(t[1]);
        F[] H = new F[C];
        for (int i = 0; i < C; i++)
        {
            H[i] = new F();
            t = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            H[i].P = double.Parse(t[0]);
            H[i].V = int.Parse(t[1]);
        }

        Array.Sort(H);

        double min = 0;
        double max = (double)1000 * (double)1000 * (double)1000 * (double)1000;

        double prev = 0;
        while (min + 1e-7 < max)
        {
            
            double mid = (min + max) / 2;
            if (mid == prev)
                break;
            prev = mid;
            bool b = true;
            double start = H[0].P - mid;
            for (int i = 0; i < H.Length && b; i++)
            {
                F f = H[i];
                double minpos = f.P - mid;
                start = Math.Max(start, minpos);
                start += (double)(f.V - 1) * D;
                if (Math.Abs(f.P - start) - 1e-9 > mid)
                {
                    b = false;
                    break;
                }
                start += D;
            }
            if (!b)
                min = mid;
            else
                max = mid;
        }

        return string.Format("{0:0.000000000}", min);

    }
}
