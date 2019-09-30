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

    static void Main(string[] args)
    {
        Reader sr = new Reader("C:\\test\\in.in");
        StreamWriter sw = new StreamWriter("C:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            string[] v = Solution(sr);
            sw.WriteLine("Case #" + (i + 1).ToString() + ":");
            for (int j = 0; j < v.Length; j++)
			{
			 sw.WriteLine(v[j]);
			}
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static string VV(long[] V, int b)
    {
        int i = 0;
        string s = "";
        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                s += " " + V[i].ToString();
            }
            b >>= 1;
            i++;
        }
        return s.Substring(1);
    }

    static string[] Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        int A = int.Parse(t[0]);
        long[] D = new long[A];
        for (int i = 0; i < A; i++)
        {
            D[i] = long.Parse(t[i + 1]);
        }


        Dictionary<long, int> F = new Dictionary<long, int>();

        for (int w = 1; w < 1<<A; w++)
        {
            int j = w;
            long tot = 0;
            int i = 0;
            while (j > 0)
            {
                if ((j & 1) == 1)
                {
                    tot += D[i];
                }
                j >>= 1;
                i++;
            }
            if (F.ContainsKey(tot))
            {
                int b = F[tot];
                int and = w & b;
                b ^= and;
                w ^= and;
                return new string[] { VV(D, b), VV(D, w) };
            }
            else
            {
                F.Add(tot, w);
            }
        }

        return new string[] { "Impossible" };

    }
}
