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
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static double V(int k, double[] D)
    {
        double High = 1.0;
        double Low = 0.0;

        while (Low + 1e-9 < High)
        {
            double Mid = (High + Low) / 2.0;
            double[] B = new double[D.Length];
            for (int i = 0; i < D.Length; i++)
            {
                B[i] = D[i];
            }
            B[k] += Mid;
            double t = 1.0-Mid;
            for (int i = 0; i < D.Length; i++)
            {
                if (i != k)
                {
                    if (B[i] < B[k])
                    {
                        t -= B[k] - B[i];
                    }
                }
            }
            if (t < 0)
            {
                High = Mid;
            }
            else
            {
                Low = Mid;
            }
        }
        return (Low + High) / 2.0;
    }

    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        int A = int.Parse(t[0]);
        double X = 0;
        double[] D = new double[A];
        for (int i = 0; i < A; i++)
        {
            X += int.Parse(t[i + 1]);
            D[i] = double.Parse(t[i + 1]);
        }
        for (int i = 0; i < D.Length; i++)
        {
            D[i] /= X;
        }
        string s = "";
        for (int i = 0; i < A; i++)
        {
            s += string.Format(" {0:f7}", V(i,D)*100.0);
        }
        return s.Substring(1);
    }
}
